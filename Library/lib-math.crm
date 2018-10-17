#setLanguageLevel 3;

/*
 * Methods for doing mathematics
 */

/*
 * Constants
 */
Integer CONST_INTEGER_MAX = 2147483647;
Integer CONST_INTEGER_MIN = -2147483648;
Float CONST_PI = 3.14159265359;

/*
 * Get the Absolute value of the number (i.e. remove sign)
 */
Integer abs(Integer number)
{
  if (number >= 0)
    return number;
  else
    return number * -1;
}

Float abs(Float number)
{
  if (number >= 0)
    return number;
  else
    return number * -1;
}

/*
 * Find the highest of two numbers
 */
Integer max(Integer a, Integer b)
{
  if (a > b) return a;
  else return b;
}

/*
 * Find the smallest of two numbers
 */
Integer min(Integer a, Integer b)
{
  if (a < b) return a;
  else return b;
}

/*
 * Get array with Fibonacci numbers. 
 * n determines how many numbers to get.
 */
Integer[] getFibonacci(Integer n) {
  Integer[] result;
  
  if (n > 0) result.pushBack(1);
  if (n > 1) result.pushBack(1);
    
  for (Integer i = 2; i < n; i++) {
    result.pushBack(result[i-1] + result[i-2]);
  }
  return result;
}

/*
 * Create a unique GUID. Note, isn't particularly fast.
 * Doesn't work in Online.
 */
String createGUID() {
  String command = "powershell -Command \"[guid]::NewGuid()\"";
  String result = runProgram(command);
  String guidPattern = "(\\w+-\\w+-\\w+-\\w+-\\w+)";
  String[] matches = result.regexp(guidPattern);
  if (matches.length() > 1)
    return matches[1];
  else 
    exitWithMessage("Unable to create GUID!");
}