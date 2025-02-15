package org.openqa.grid.common.defaults;

import java.io.IOException;
import java.io.InputStream;
import java.util.Properties;

import org.apache.commons.lang.WordUtils;

public class GridDocHelper {
	private static Properties hubProperties = load("defaults/HubParameters.properties");
	private static Properties nodeProperties = load("defaults/NodeParameters.properties");

	public static void helpHub(String msg) {
		printHelpInConsole(hubProperties, msg);
	}

	public static void helpNode(String msg) {
		printHelpInConsole(nodeProperties, msg);
	}

	public static String getNodeParam(String param) {
		return getParam(nodeProperties, param);
	}

	public static String getHubParam(String param) {
		return getParam(hubProperties, param);
	}

	private static String getParam(Properties p, String param) {
		if (param == null) {
			return "";
		}
		String s = (String) hubProperties.get(param);
		if (s == null) {
			return "No help specified for " + param;
		} else {
			return s;
		}
	}

	private static void printHelpInConsole(Properties p, String msg) {
		if (msg != null) {
			System.out.println("Error building the config :" + msg);
		}

		System.out.println("Usage :");
		for (Object key : p.keySet()) {
			System.out.println("-" + key + ":\n\t" + WordUtils.wrap((String) getParam(p, key.toString()), 80, "\n\t", false));
		}
	}

	private static Properties load(String resource) {
		InputStream in = Thread.currentThread().getContextClassLoader().getResourceAsStream(resource);
		Properties p = new Properties();
		if (in != null) {
			try {
				p.load(in);
				return p;
			} catch (IOException e) {
				throw new RuntimeException("bug." + resource + " cannot be loaded.");
			}
		} else {
			throw new RuntimeException("bug." + resource + " cannot be loaded.");
		}
	}

	public static void main(String[] args) {
		helpHub(null);
	}

}
