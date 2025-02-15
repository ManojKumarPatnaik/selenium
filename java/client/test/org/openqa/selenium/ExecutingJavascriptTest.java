/*
Copyright 2007-2009 WebDriver committers
Copyright 2007-2009 Google Inc.

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

package org.openqa.selenium;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;

import org.apache.commons.io.FileUtils;

import static org.hamcrest.MatcherAssert.assertThat;
import static org.hamcrest.Matchers.greaterThanOrEqualTo;
import static org.hamcrest.Matchers.instanceOf;
import static org.openqa.selenium.Ignore.Driver.IE;
import static org.openqa.selenium.Ignore.Driver.IPHONE;
import static org.openqa.selenium.Ignore.Driver.REMOTE;
import static org.openqa.selenium.Ignore.Driver.SELENESE;

public class ExecutingJavascriptTest extends AbstractDriverTestCase {

  @JavascriptEnabled
  public void testShouldBeAbleToExecuteSimpleJavascriptAndReturnAString() {
    if (!(driver instanceof JavascriptExecutor)) {
      return;
    }

    driver.get(pages.xhtmlTestPage);

    Object result = executeScript("return document.title;");

    assertTrue(result instanceof String);
    assertEquals("XHTML Test Page", result);
  }

  @JavascriptEnabled
  public void testShouldBeAbleToExecuteSimpleJavascriptAndReturnALong() {
    if (!(driver instanceof JavascriptExecutor)) {
      return;
    }

    driver.get(pages.nestedPage);

    Object result = executeScript("return document.getElementsByName('checky').length;");

    assertTrue(result.getClass().getName(), result instanceof Long);
    assertTrue((Long) result > 1);
  }

  @JavascriptEnabled
  @Ignore(SELENESE)
  public void testShouldBeAbleToExecuteSimpleJavascriptAndReturnAWebElement() {
    if (!(driver instanceof JavascriptExecutor)) {
      return;
    }

    driver.get(pages.xhtmlTestPage);

    Object result = executeScript("return document.getElementById('id1');");

    assertNotNull(result);
    assertThat(result, instanceOf(WebElement.class));
    assertEquals("a", ((WebElement) result).getTagName().toLowerCase());
  }

  @JavascriptEnabled
  public void testShouldBeAbleToExecuteSimpleJavascriptAndReturnABoolean() {
    if (!(driver instanceof JavascriptExecutor)) {
      return;
    }

    driver.get(pages.xhtmlTestPage);

    Object result = executeScript("return true;");

    assertNotNull(result);
    assertTrue(result instanceof Boolean);
    assertTrue((Boolean) result);
  }

  @SuppressWarnings("unchecked")
  @JavascriptEnabled
  @Ignore({SELENESE, IPHONE})
  public void testShouldBeAbleToExecuteSimpleJavascriptAndAStringsArray() {
    if (!(driver instanceof JavascriptExecutor)) {
      return;
    }

    driver.get(pages.javascriptPage);
    List<Object> expectedResult = new ArrayList<Object>();
    expectedResult.add("zero");
    expectedResult.add("one");
    expectedResult.add("two");
    Object result = ((JavascriptExecutor) driver).executeScript(
    "return ['zero', 'one', 'two'];");

    ExecutingJavascriptTest.compareLists(expectedResult, (List<Object>) result);
  }

  @SuppressWarnings("unchecked")
  @JavascriptEnabled
  @Ignore({SELENESE, IPHONE})
  public void testShouldBeAbleToExecuteSimpleJavascriptAndReturnAnArray() {
    if (!(driver instanceof JavascriptExecutor)) {
      return;
    }

    driver.get(pages.javascriptPage);
    List<Object> expectedResult = new ArrayList<Object>();
    expectedResult.add("zero");
    List<Object> subList = new ArrayList<Object>();
    subList.add(true);
    subList.add(false);
    expectedResult.add(subList);
    Object result = executeScript("return ['zero', [true, false]];");
    assertNotNull(result);
    assertTrue("result was: " + result + " (" + result.getClass() + ")", result instanceof List);
    List<Object> list = (List<Object>) result;
    assertTrue(compareLists(expectedResult, list));
  }


  @SuppressWarnings("unchecked")
  @JavascriptEnabled
  @Ignore({IE, SELENESE, IPHONE})
  public void testShouldBeAbleToExecuteJavascriptAndReturnABasicObjectLiteral() {
    if (!(driver instanceof JavascriptExecutor)) {
      return;
    }

    driver.get(pages.javascriptPage);

    Object result = executeScript("return {abc: '123', tired: false};");
    assertTrue("result was: " + result + " (" + result.getClass() + ")", result instanceof Map);
    Map<String, Object> map = (Map<String, Object>) result;

    Map<String, Object> expected = new HashMap<String, Object>();
    expected.put("abc", "123");
    expected.put("tired", false);

    // Cannot do an exact match; Firefox 4 inserts a few extra keys in our object; this is OK, as
    // long as the expected keys are there.
    assertThat("Expected:<" + expected + ">, but was:<" + map + ">",
        map.size(), greaterThanOrEqualTo(expected.size()));
    for (Map.Entry<String, Object> entry : expected.entrySet()) {
      assertEquals("Difference at key:<" + entry.getKey() + ">",
          entry.getValue(), map.get(entry.getKey()));
    }
  }

  @SuppressWarnings("unchecked")
  @JavascriptEnabled
  @Ignore({IE, SELENESE, IPHONE})
  public void testShouldBeAbleToExecuteSimpleJavascriptAndReturnAnObjectLiteral() {
    if (!(driver instanceof JavascriptExecutor)) {
      return;
    }

    driver.get(pages.javascriptPage);

    Map<String, Object> expectedResult = new HashMap<String, Object>(){{
      put("foo", "bar");
      put("baz", Arrays.asList("a", "b", "c"));
      put("person", new HashMap<String, String>(){{
        put("first", "John");
        put("last", "Doe");
      }});
    }};

    Object result = executeScript(
        "return {foo:'bar', baz: ['a', 'b', 'c'], " +
            "person: {first: 'John',last: 'Doe'}};");
    assertTrue("result was: " + result + " (" + result.getClass() + ")", result instanceof Map);

    Map<String, Object> map = (Map<String, Object>) result;
    assertThat("Expected:<" + expectedResult + ">, but was:<" + map + ">",
        map.size(), greaterThanOrEqualTo(3));
    assertEquals("bar", map.get("foo"));
    assertTrue(compareLists((List<?>) expectedResult.get("baz"),
        (List<?>) map.get("baz")));

    Map<String, String> person = (Map<String, String>) map.get("person");
    assertThat("Expected:<{first:John, last:Doe}>, but was:<" + person + ">",
        person.size(), greaterThanOrEqualTo(2));
    assertEquals("John", person.get("first"));
    assertEquals("Doe", person.get("last"));
  }

  private static boolean compareLists(List<?> first, List<?> second) {
    if (first.size() != second.size()) {
      return false;
    }
    for (int i = 0; i < first.size(); ++i) {
      if (first.get(i) instanceof List<?>) {
        if (!(second instanceof List<?>)) {
          return false;
        } else {
          if (!compareLists((List<?>) first.get(i), (List<?>) second.get(i))) {
            return false;
          }
        }
      } else {
        if (!first.get(i).equals(second.get(i))) {
          return false;
        }
      }
    }
    return true;
  }

  @JavascriptEnabled
  public void testPassingAndReturningALongShouldReturnAWholeNumber() {
    if (!(driver instanceof JavascriptExecutor)) {
      return;
    }

    driver.get(pages.javascriptPage);
    Long expectedResult = 1L;
    Object result = executeScript("return arguments[0];", expectedResult);
    assertTrue("Expected result to be an Integer or Long but was a " +
               result.getClass(), result instanceof Integer || result instanceof Long);
    assertEquals(expectedResult.longValue(), result);
  }

  @JavascriptEnabled
  public void testPassingAndReturningADoubleShouldReturnADecimal() {
    if (!(driver instanceof JavascriptExecutor)) {
      return;
    }

    driver.get(pages.javascriptPage);
    Double expectedResult = 1.2;
    Object result = executeScript("return arguments[0];", expectedResult);
    assertTrue("Expected result to be a Double or Float but was a " +
               result.getClass(), result instanceof Float || result instanceof Double);
    assertEquals(expectedResult.doubleValue(), result);
  }

  @JavascriptEnabled
  public void testShouldThrowAnExceptionWhenTheJavascriptIsBad() {
    if (!(driver instanceof JavascriptExecutor)) {
      return;
    }

    driver.get(pages.xhtmlTestPage);

    try {
      executeScript("return squiggle();");
      fail("Expected an exception");
    } catch (Exception e) {
      // This is expected
    }
  }

  @JavascriptEnabled
  @Ignore(SELENESE)
  public void testShouldBeAbleToCallFunctionsDefinedOnThePage() {
    if (!(driver instanceof JavascriptExecutor)) {
      return;
    }

    driver.get(pages.javascriptPage);
    executeScript("displayMessage('I like cheese');");
    String text = driver.findElement(By.id("result")).getText();

    assertEquals("I like cheese", text.trim());
  }

  private Object executeScript(String script, Object... args) {
    return ((JavascriptExecutor) driver).executeScript(script, args);
  }

  @JavascriptEnabled
  public void testShouldBeAbleToPassAStringAnAsArgument() {
    if (!(driver instanceof JavascriptExecutor)) {
      return;
    }

    driver.get(pages.javascriptPage);
    String
        value =
        (String) executeScript("return arguments[0] == 'fish' ? 'fish' : 'not fish';", "fish");

    assertEquals("fish", value);
  }

  @JavascriptEnabled
  public void testShouldBeAbleToPassABooleanAnAsArgument() {
    if (!(driver instanceof JavascriptExecutor)) {
      return;
    }

    driver.get(pages.javascriptPage);
    boolean value = (Boolean) executeScript("return arguments[0] == true;", true);

    assertTrue(value);
  }

  @JavascriptEnabled
  public void testShouldBeAbleToPassANumberAnAsArgument() {
    if (!(driver instanceof JavascriptExecutor)) {
      return;
    }

    driver.get(pages.javascriptPage);
    boolean value = (Boolean) executeScript("return arguments[0] == 1 ? true : false;", 1);

    assertTrue(value);
  }

  @JavascriptEnabled
  @Ignore(SELENESE)
  public void testShouldBeAbleToPassAWebElementAsArgument() {
    if (!(driver instanceof JavascriptExecutor)) {
      return;
    }

    driver.get(pages.javascriptPage);
    WebElement button = driver.findElement(By.id("plainButton"));
    String value = (String) executeScript(
        "arguments[0]['flibble'] = arguments[0].getAttribute('id'); return arguments[0]['flibble'];",
        button);

    assertEquals("plainButton", value);
  }

  @JavascriptEnabled
  @Ignore(SELENESE)
  public void testPassingArrayAsOnlyArgumentFlattensArray() {
    if (!(driver instanceof JavascriptExecutor)) {
      return;
    }

    driver.get(pages.javascriptPage);
    Object[] array = new Object[]{"zero", 1, true, 3.14159, false};
    String value = (String) executeScript("return arguments[0]", array);
    assertEquals(array[0], value);
  }

  @JavascriptEnabled
  @Ignore
  public void testShouldBeAbleToPassAnArrayAsAdditionalArgument() {
    if (!(driver instanceof JavascriptExecutor)) {
      return;
    }

    driver.get(pages.javascriptPage);
    Object[] array = new Object[]{"zero", 1, true, 3.14159, false};
    long length = (Long) executeScript("return arguments[1].length", "string", array);
    assertEquals(array.length, length);
  }

  @JavascriptEnabled
  @Ignore({IE, REMOTE, SELENESE})
  public void testShouldBeAbleToPassACollectionAsArgument() {
    if (!(driver instanceof JavascriptExecutor)) {
      return;
    }

    driver.get(pages.javascriptPage);
    Collection<Object> collection = new ArrayList<Object>();
    collection.add("Cheddar");
    collection.add("Brie");
    collection.add(7);
    long length = (Long) executeScript("return arguments[0].length", collection);
    assertEquals(collection.size(), length);

    collection = new HashSet<Object>();
    collection.add("Gouda");
    collection.add("Stilton");
    collection.add("Stilton");
    collection.add(true);
    length = (Long) executeScript("return arguments[0].length", collection);
    assertEquals(collection.size(), length);
  }

  @JavascriptEnabled
  public void testShouldThrowAnExceptionIfAnArgumentIsNotValid() {
    if (!(driver instanceof JavascriptExecutor)) {
      return;
    }

    driver.get(pages.javascriptPage);
    try {
      executeScript("return arguments[0];", driver);
      fail("Exception should have been thrown");
    } catch (IllegalArgumentException e) {
      // this is expected
    }
  }

  @JavascriptEnabled
  public void testShouldBeAbleToPassInMoreThanOneArgument() {
    if (!(driver instanceof JavascriptExecutor)) {
      return;
    }

    driver.get(pages.javascriptPage);
    String result = (String) executeScript("return arguments[0] + arguments[1];", "one", "two");

    assertEquals("onetwo", result);
  }

  @Ignore(value = {SELENESE, IPHONE},
      reason = "iPhone: Frame switching not yet implemented.")
  @JavascriptEnabled
  public void testShouldBeAbleToGrabTheBodyOfFrameOnceSwitchedTo() {
    driver.get(pages.richTextPage);

    driver.switchTo().frame("editFrame");
    WebElement body =
        (WebElement) ((JavascriptExecutor) driver).executeScript("return document.body");

    assertEquals("", body.getText());
  }

  @Ignore
  public void testShouldBeAbleToReturnAnArrayOfWebElements() {
    driver.get(pages.formPage);

    List<WebElement> items = (List<WebElement>) ((JavascriptExecutor) driver)
        .executeScript("return document.getElementsByName('snack');");

    assertTrue(items.size() > 0);
  }

  @JavascriptEnabled
  @Ignore(SELENESE)
  public void testJavascriptStringHandlingShouldWorkAsExpected() {
    driver.get(pages.javascriptPage);

    String value = (String) executeScript("return '';");
    assertEquals("", value);

    value = (String) executeScript("return undefined;");
    assertNull(value);

    value = (String) executeScript("return ' '");
    assertEquals(" ", value);
  }

  @JavascriptEnabled
  public void testShouldBeAbleToExecuteABigChunkOfJavascriptCode() throws IOException {
    driver.get(pages.javascriptPage);

    File jqueryFile = new File("common/src/web/jquery-1.3.2.js");
    if(!jqueryFile.isFile()) {
      jqueryFile = new File("../common/src/web/jquery-1.3.2.js");
      if(!jqueryFile.isFile()) {
        jqueryFile = new File("../../common/src/web/jquery-1.3.2.js");
      }
    }
    String jquery = FileUtils.readFileToString(jqueryFile, "US-ASCII");
    assertTrue("The javascript code should be at least 50 KB.", jquery.length() > 50000);
    // This should not throw an exception ...
    executeScript(jquery);
  }

  @SuppressWarnings("unchecked")
  @JavascriptEnabled
  @Ignore({SELENESE, REMOTE, IPHONE})
  public void testShouldBeAbleToExecuteScriptAndReturnElementsList() {
    driver.get(pages.formPage);
    String scriptToExec = "return document.getElementsByName('snack');";
    
    List<WebElement> resultsList = (List<WebElement>) ((JavascriptExecutor) driver)
      .executeScript(scriptToExec);

    assertTrue(resultsList.size() > 0);
  }

  @JavascriptEnabled
  @NeedsFreshDriver
  @NoDriverAfterTest
  @Ignore //Reason for ignore: Failure indicates hang condition,
          //which would break the test suite.  Really needs a timeout set.
  public void testShouldThrowExceptionIfExecutingOnNoPage() {
    try {
      ((JavascriptExecutor)driver).executeScript("return 1;");
    } catch (WebDriverException e) {
      //Expected
      return;
    }
    fail("Expected exception to be thrown");
  }

  @JavascriptEnabled
  public void testShouldBeAbleToCreateAPersistentValue() {
    driver.get(pages.formPage);

    executeScript("document.alerts = []");
    executeScript("document.alerts.push('hello world');");
    String text = (String) executeScript("return document.alerts.shift()");

    assertEquals("hello world", text);
  }

  @JavascriptEnabled
  @Ignore(SELENESE)
  public void testCanHandleAnArrayOfElementsAsAnObjectArray() {
    driver.get(pages.formPage);

    List<WebElement> forms = driver.findElements(By.tagName("form"));
    Object[] args = new Object[] { forms };

    String name = (String) ((JavascriptExecutor) driver).executeScript(
        "return arguments[0][0].tagName", args);

    assertEquals("form", name.toLowerCase());
  }
}
