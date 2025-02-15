package org.openqa.grid.e2e.selenium;

import java.net.URL;
import java.util.ArrayList;
import java.util.List;

import org.openqa.grid.e2e.utils.GridConfigurationMock;
import org.openqa.grid.internal.utils.GridHubConfiguration;
import org.openqa.grid.selenium.SelfRegisteringRemote;
import org.openqa.grid.web.Hub;
import org.openqa.selenium.net.PortProber;
import org.testng.Assert;
import org.testng.annotations.AfterClass;
import org.testng.annotations.BeforeClass;
import org.testng.annotations.Test;

import com.thoughtworks.selenium.DefaultSelenium;
import com.thoughtworks.selenium.Selenium;

/**
 * Register 5 remote for selenium1. Make sure the tests are spread to all the
 * remotes.
 * 
 * 
 */
public class MultiRCTest {
	private Hub hub;
	private URL hubURL;
	List<Selenium> seleniums = new ArrayList<Selenium>();

	@BeforeClass(alwaysRun = true)
	public void prepare() throws Exception {
		GridHubConfiguration config = new GridHubConfiguration();
		config.setPort(PortProber.findFreePort());
		hub = new Hub(config);
		hubURL = hub.getUrl();
		hub.start();

		for (int i = 0; i < 5; i++) {
			SelfRegisteringRemote remote = SelfRegisteringRemote.create(GridConfigurationMock.seleniumConfig(hub.getRegistrationURL()));
			remote.addFirefoxSupport();
			remote.addSafariSupport();
			remote.addInternetExplorerSupport();
			remote.launchRemoteServer();
			remote.registerToHub();
		}

	}

	@Test(invocationCount = 5, threadPoolSize = 5)
	public void multifirefox() {
		Selenium selenium = new DefaultSelenium(hub.getHost(), hub.getPort(), "*firefox", hubURL + "");
		seleniums.add(selenium);
		System.out.println("selenium !");
		selenium.start();
		selenium.open(hubURL + "/grid/console");
	}

	@Test(dependsOnMethods = "multifirefox", timeOut = 10000, enabled = false)
	public void validate() throws InterruptedException {
		Assert.assertEquals(seleniums.size(), 5);

		for (Selenium selenium : seleniums) {
			selenium.stop();
		}
		// cannot assume it will be 0 active session right away. selenium.stop()
		// will trigger a session.terminate() on the grid, that runs in a
		// different thread
		// not to block the test.
		while (hub.getRegistry().getActiveSessions().size() != 0) {

			Thread.sleep(250);
		}
	}

	@AfterClass(alwaysRun = true)
	public void stop() throws Exception {
		hub.stop();
	}
}
