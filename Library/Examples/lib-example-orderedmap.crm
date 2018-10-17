#setLanguageLevel 3;
#include "lib-orderedmap";

OrderedMap a;
a.insert("z", "Z");
a.insert("a", "A");
a.insert("m", "M");
a.insert("g", "G");
a.insert("a", "b").insert("c", "d").insert("a", "CHANGED");

a.insert("number", "5");
a.increaseValueForKey("number", 2);

a.insert("float", "1.2");
a.increaseValueForKey("float", 3.14);


for (a.first(); !a.eof(); a.next())
{
  printLine(a.getKey() + " => " + a.getVal());
}

printLine(a.toJson());


//printLine(a.toString());