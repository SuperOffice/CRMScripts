#setLanguageLevel 3;
#include "lib-string";

//Example: Capitalize words
printLine(capitalizeWords("this is a sentence with originally only lowercase words."));

//Example: Check for alphanumeric characters
String txt = "[{:\"},{}\r\n]";
printLine("containsAlphaNumericChar: " + containsAlphaNumericChar(txt).toString());

//Example: Pretty split a string
String text;
for (Integer i = 0; i < 10; i++)
  text.append("All work and no play makes Jack a dull boy. ");
Vector s = prettySplit(text, 80, " ");
printLine(s.buildString("\n"));

//MultiRegexp to find multiple matches in a string
String text2 = "How to find all these numbers #12345, #23456, #34567 in this string?";
/*MultiRegexp mr;
mr.setPattern("#(\\d+)"); //all numbers
printLine("MatchesExists: " + mr.matchesExists(text2).toString());*/
String pattern = "#(\\d+)";
String[] results = getAllMatches(pattern, text2);
for (Integer i = 0; i < results.length(); i++) {
  printLine(results[i]);
}
if (results.length() == 0)
  printLine("No matches");

//Example: Pad Left
String a = "abc";
a = padLeft(a, 10, "0");
printLine(a);

//Example: strlen
String b = "Hello there";
printLine("The string '" + b + "' is " + strlen(b).toString() + " chars long.");