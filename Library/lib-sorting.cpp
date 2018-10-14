#setLanguageLevel 3;

/*
 * Sort strings in array alphabetically
 */
String[] bubbleSort(String[] items) {
	Integer length = items.length();
  Integer j = 0;
  String tmp;
  Bool swapped = true;
  while (swapped) {
    swapped = false;
    j++;
    for (Integer i = 0; i < length - j; i++) {
      if (items[i] > items[i+1]) {
      	tmp = items[i];
      	items[i] = items[i+1];
      	items[i+1] = tmp;
      	swapped = true;
     	}
    }
  }
  return items;
}