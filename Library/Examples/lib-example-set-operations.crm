#setLanguageLevel 3;
#include "lib-set-operations";


Void printIntegerArray(Integer[] a)
{
  for (Integer i = 0; i < a.length(); i++)
    printLine(a[i].toString());
}

Integer[] a;
a.pushBack(1);
a.pushBack(2);
a.pushBack(3);

Integer[] b;
b.pushBack(2);
b.pushBack(3);
b.pushBack(4);

printLine("-- EXISTS --");
printLine(setOperationsExists(3, a).toString());

printLine("-- COMPLEMENT --");
Integer[] c = setOperationsComplement(a, b);
printIntegerArray(c);
  
printLine("-- DIFFERENCE --");
Integer[] d = setOperationsDifference(a, b);
printIntegerArray(d);

printLine("-- INTERSECTION --");
Integer[] e = setOperationsIntersection(a, b);
printIntegerArray(e);

printLine("-- UNION --");
Integer[] f = setOperationsUnion(a, b);
printIntegerArray(f);

printLine("-- MUTUAL EXCLUSIVE --");
printLine(setOperationsIsMutuallyExclusive(a, b).toString());