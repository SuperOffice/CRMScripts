#setLanguageLevel 3;

/*
 * Library for set-operations
 * See https://www.probabilitycourse.com/chapter1/1_2_2_set_operations.php
 * Frode Lillerud, Ganske Enkelt AS, 20.oct 2017
 */

/*
 * Does the value exist in the array of numbers?
 */
Bool setOperationsExists( Integer value, Integer[] numbers)
{
  for (Integer i = 0; i < numbers.length(); i++)
    if (numbers[i] == value)
      return true;
  return false;
}

/*
 * Get elements that exist in A, but exclude the ones in B
 */
Integer[] setOperationsComplement(Integer[] a, Integer[] b)
{
  Integer[] result;
  for (Integer i = 0; i < a.length(); i++)
  {
    If (!setOperationsExists(a[i], b))
      result.pushBack(a[i]);
  }
  return result;
}

/*
 * Get elements that exist in A, but not in B
 */
Integer[] setOperationsDifference(Integer[] a, Integer[] b)
{
  Integer[] result;
  for (Integer i = 0; i < a.length(); i++)
    //for (Integer j = 0; j < b.length(); j++)
  	{
      if (!setOperationsExists(a[i], b))
        result.pushBack(a[i]);
  	}
  return result;
}

/*
 * Get elements that exist in both A and B.
 */
Integer[] setOperationsIntersection(Integer[] a, Integer[] b)
{
  Integer[] result;
  for (Integer i = 0; i < a.length(); i++) {
    for (Integer j = 0; j < b.length(); j++) {
      if (a[i] == b[j])
        result.pushBack(a[i]);
    }
  }
  return result;
}

/*
 * Get elements that exists in either A or B
 */
Integer[] setOperationsUnion(Integer[] a, Integer[] b)
{
  Integer[] result;
  for (Integer i = 0; i < a.length(); i++)
    result.pushBack(a[i]);
  //result = a;
  Integer[] onlyInB = setOperationsDifference(b, a);
  for (Integer i = 0; i < onlyInB.length(); i++)
    result.pushBack(onlyInB[i]);
  return result;
}

/*
 * Check if arrays are mutually exclusive.
 * Do the arrays share any of the same values?
 */
Bool setOperationsIsMutuallyExclusive(Integer[] a, Integer[] b)
{
  Integer[] intersect = setOperationsIntersection(a, b);
  return intersect.length() == 0;
}