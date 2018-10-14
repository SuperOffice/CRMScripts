#setLanguageLevel 3;
#include "lib-math";

Integer[] numbers = getFibonacci(100);
for (Integer i = 0; i < numbers.length(); i++)
  printLine(numbers[i].toString());

printLine("-----");
Integer max = 2147483647;
printLine(max.toString());
max++;
printLine(max.toString());
max++;
printLine(max.toString());
max++;
printLine(max.toString());

//GUID
printLine("GUID: " + createGUID());

//abs
Integer a = -5;
printLine("Absolute value of " + a.toString() + " is " + abs(a).toString());