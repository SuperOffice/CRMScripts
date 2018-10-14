#setLanguageLevel 3;

/*
 * Grab the first in an array of NSEntityElements (for example phonenumbers)
 */
NSEntityElement getFirst(NSEntityElement[] elements) {
  NSEntityElement result;
  if (elements.length() > 0)
    result = elements[0];
  return result;
}

Bool isValidPhone(String phone) {
  if (phone.isEmpty())
    return true;

  if (phone == phone.keepChars("+ 0123456789"))
    return true;

  return false;
}