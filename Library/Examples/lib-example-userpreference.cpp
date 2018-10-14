#setLanguageLevel 3;
#include "lib-userpreference";

String prefsection = "test-section";
String prefkey = "test-key";
String val = "abc";

//Write preference
setUserPreferenceValue(prefsection, prefkey, val);

//Read preference
String value = getUserPreferenceValue(prefsection, prefkey);
printLine(value);