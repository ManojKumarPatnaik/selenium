/*
Copyright 2011 WebDriver committers
Copyright 2011 Google Inc.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

     http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

package com.thoughtworks.selenium;

import com.thoughtworks.selenium.corebased.TestAddLocationStrategy;
import com.thoughtworks.selenium.corebased.TestAddSelection;
import com.thoughtworks.selenium.corebased.TestAlerts;
import com.thoughtworks.selenium.corebased.TestBasicAuth;
import com.thoughtworks.selenium.corebased.TestBrowserVersion;
import com.thoughtworks.selenium.corebased.TestCheckUncheck;
import com.thoughtworks.selenium.corebased.TestClick;
import com.thoughtworks.selenium.corebased.TestClickBlankTarget;
import com.thoughtworks.selenium.corebased.TestClickJavascriptHref;
import com.thoughtworks.selenium.corebased.TestClickJavascriptHrefChrome;
import com.thoughtworks.selenium.corebased.TestClickJavascriptHrefWithVoidChrome;
import com.thoughtworks.selenium.corebased.TestCommandError;
import com.thoughtworks.selenium.corebased.TestComments;
import com.thoughtworks.selenium.corebased.TestConfirmations;
import com.thoughtworks.selenium.corebased.TestCookie;
import com.thoughtworks.selenium.corebased.TestCssLocators;
import com.thoughtworks.selenium.corebased.TestCursorPosition;
import com.thoughtworks.selenium.corebased.TestDojoDragAndDrop;
import com.thoughtworks.selenium.corebased.TestDomainCookie;
import com.thoughtworks.selenium.corebased.TestDragAndDrop;
import com.thoughtworks.selenium.corebased.TestEditable;
import com.thoughtworks.selenium.corebased.TestElementIndex;
import com.thoughtworks.selenium.corebased.TestElementOrder;
import com.thoughtworks.selenium.corebased.TestElementPresent;
import com.thoughtworks.selenium.corebased.TestErrorChecking;
import com.thoughtworks.selenium.corebased.TestEval;
import com.thoughtworks.selenium.corebased.TestEvilClosingWindow;
import com.thoughtworks.selenium.corebased.TestFailingAssert;
import com.thoughtworks.selenium.corebased.TestFailingVerifications;
import com.thoughtworks.selenium.corebased.TestFocusOnBlur;
import com.thoughtworks.selenium.corebased.TestFramesClick;
import com.thoughtworks.selenium.corebased.TestFramesClickJavascriptHref;
import com.thoughtworks.selenium.corebased.TestFramesNested;
import com.thoughtworks.selenium.corebased.TestFramesOpen;
import com.thoughtworks.selenium.corebased.TestFramesSpecialTargets;
import com.thoughtworks.selenium.corebased.TestFunkEventHandling;
import com.thoughtworks.selenium.corebased.TestGet;
import com.thoughtworks.selenium.corebased.TestGetTextContent;
import com.thoughtworks.selenium.corebased.TestGettingValueOfCheckbox;
import com.thoughtworks.selenium.corebased.TestGoBack;
import com.thoughtworks.selenium.corebased.TestHighlight;
import com.thoughtworks.selenium.corebased.TestHtmlSource;
import com.thoughtworks.selenium.corebased.TestImplicitLocators;
import com.thoughtworks.selenium.corebased.TestJavaScriptAttributes;
import com.thoughtworks.selenium.corebased.TestJavascriptParameters;
import com.thoughtworks.selenium.corebased.TestLocators;
import com.thoughtworks.selenium.corebased.TestModalDialog;
import com.thoughtworks.selenium.corebased.TestMultiSelect;
import com.thoughtworks.selenium.corebased.TestOpen;
import com.thoughtworks.selenium.corebased.TestOpenInTargetFrame;
import com.thoughtworks.selenium.corebased.TestPatternMatching;
import com.thoughtworks.selenium.corebased.TestPause;
import com.thoughtworks.selenium.corebased.TestPrompt;
import com.thoughtworks.selenium.corebased.TestProxy;
import com.thoughtworks.selenium.corebased.TestQuickOpen;
import com.thoughtworks.selenium.corebased.TestRefresh;
import com.thoughtworks.selenium.corebased.TestRollup;
import com.thoughtworks.selenium.corebased.TestSelect;
import com.thoughtworks.selenium.corebased.TestSelectMultiLevelFrame;
import com.thoughtworks.selenium.corebased.TestSelectPopUp;
import com.thoughtworks.selenium.corebased.TestSelectWindow;
import com.thoughtworks.selenium.corebased.TestSelectWindowTitle;
import com.thoughtworks.selenium.corebased.TestSetSpeed;
import com.thoughtworks.selenium.corebased.TestStore;
import com.thoughtworks.selenium.corebased.TestSubmit;
import com.thoughtworks.selenium.corebased.TestTextWhitespace;
import com.thoughtworks.selenium.corebased.TestType;
import com.thoughtworks.selenium.corebased.TestTypeRichText;
import com.thoughtworks.selenium.corebased.TestUIElementLocators;
import com.thoughtworks.selenium.corebased.TestUseXpathLibrary;
import com.thoughtworks.selenium.corebased.TestVerifications;
import com.thoughtworks.selenium.corebased.TestVisibility;
import com.thoughtworks.selenium.corebased.TestWait;
import com.thoughtworks.selenium.corebased.TestWaitFor;
import com.thoughtworks.selenium.corebased.TestWaitForNot;
import com.thoughtworks.selenium.corebased.TestWaitInPopupWindow;
import com.thoughtworks.selenium.corebased.TestXPathLocatorInXHtml;
import com.thoughtworks.selenium.corebased.TestXPathLocators;
import org.junit.runner.RunWith;
import org.junit.runners.Suite;

@RunWith(Suite.class)
@Suite.SuiteClasses({
    TestAddLocationStrategy.class,
    TestAddSelection.class,
    TestAlerts.class,
    TestBasicAuth.class,
    TestBrowserVersion.class,
    TestCheckUncheck.class,
    TestClick.class,
    TestClickBlankTarget.class,
    TestClickJavascriptHref.class,
    TestClickJavascriptHrefChrome.class,
    TestClickJavascriptHrefWithVoidChrome.class,
    TestCommandError.class,
    TestComments.class,
    TestConfirmations.class,
    TestCookie.class,
    TestCssLocators.class,
    TestCursorPosition.class,
    TestDojoDragAndDrop.class,
    TestDomainCookie.class,
    TestDragAndDrop.class,
    TestEditable.class,
    TestElementIndex.class,
    TestElementOrder.class,
    TestElementPresent.class,
    TestErrorChecking.class,
    TestEval.class,
    TestEvilClosingWindow.class,
    TestFailingAssert.class,
    TestFailingVerifications.class,
    TestFocusOnBlur.class,
    TestFramesClick.class,
    TestFramesClickJavascriptHref.class,
    TestFramesNested.class,
    TestFramesOpen.class,
    TestFramesSpecialTargets.class,
    TestFunkEventHandling.class,
    TestGet.class,
    TestGetTextContent.class,
    TestGettingValueOfCheckbox.class,
    TestGoBack.class,
    TestHighlight.class,
    TestHtmlSource.class,
    TestImplicitLocators.class,
    TestJavaScriptAttributes.class,
    TestJavascriptParameters.class,
    TestLocators.class,
    TestModalDialog.class,
    TestMultiSelect.class,
    TestOpen.class,
    TestOpenInTargetFrame.class,
    TestPatternMatching.class,
    TestPause.class,
    TestPrompt.class,
    TestProxy.class,
    TestQuickOpen.class,
    TestRefresh.class,
    TestRollup.class,
    TestSelect.class,
    TestSelectMultiLevelFrame.class,
    TestSelectPopUp.class,
    TestSelectWindow.class,
    TestSelectWindowTitle.class,
    TestSetSpeed.class,
    TestStore.class,
    TestSubmit.class,
    TestTextWhitespace.class,
    TestType.class,
    TestTypeRichText.class,
    TestUIElementLocators.class,
    TestUseXpathLibrary.class,
    TestVerifications.class,
    TestVisibility.class,
    TestWait.class,
    TestWaitFor.class,
    TestWaitForNot.class,
    TestWaitInPopupWindow.class,
    TestXPathLocatorInXHtml.class,
    TestXPathLocators.class
})
public class SeleniumRcTestSuite extends BaseSuite {
  // empty
}
