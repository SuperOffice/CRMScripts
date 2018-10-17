#setLanguageLevel 3;
#include "lib-sorting";

/* 
 * Structure that behaves like a Map, except that the entries are stored in the order they are added.
 * Useful when order matters.
 */
Struct OrderedMap {
  String[] _keys;
  String[] _values;
  Integer _index = 0;
  
  Void clear() {
    this._keys.clear();
    this._values.clear();
    this._index = 0;
  }
  
  Bool eof() {
    return this._index == this._keys.length();
  }
  
  Bool exists(String key) {
    for (Integer i = 0; i < this._keys.length(); i++)
      if (this._keys[i] == key)
        return true;
    return false;
  }
  
  Bool first() {
    this._index = 0;
    return (this._keys.length() > 0);
  }
  
  String getKey() {
    return this._keys[this._index];
  }
  
  String getVal() {
    return this._values[this._index];
  }
  
  Integer getIndex(String key) {
    for (Integer i = 0; i < this._keys.length(); i++)
      if (this._keys[i] == key)
        return i;
    return -1;
  }

  String get(String key) {
    Integer i = this.getIndex(key);
    if (i > -1)
      return this._values[i];
    else
      return "";
  }
  
  Void increaseValueForKey(String key, Float increment) {
    Integer index = this.getIndex(key);
    if (index > -1) {
      Float val = Float(this.get(key));
      val += increment;
      this._values[index] = val.toString(2);
    }      
  }
  
  Void increaseValueForKey(String key, Integer increment) {
    Integer index = this.getIndex(key);
    if (index > -1) {
      Integer val = this.get(key).toInteger();
      val += increment;
      this._values[index] = val.toString();
    }      
  }
  
  OrderedMap insert(String key, String value) {
    Integer index = this.getIndex(key);
    if (index >= 0) { //i.e the key exists, so update the value
      this._values[index] = value;
    }
    else {
      this._keys.pushBack(key);
      this._values.pushBack(value);
    }
    return this;
  }
  
  Bool next() {
    this._index++;
    return this.eof();
  }
  
  Void remove(String key) {
    exitWithMessage("Not implemented");
  }
  
  Integer size() {
    return this._keys.length();
  }
  
  Void sortByKey() {
    this._keys = bubbleSort(this._keys); //TODO
  }
  
  Void sortByValue() {
    //TODO
  }
  
  Void fromJson(String json) {
    Map m;
    m.fromJson(json);
    for (m.first(); !m.eof(); m.next()) {
      this.insert(m.getKey(), m.getVal());
    }
  }
  
  String toJson() {
    JSONBuilder jb;
    
    jb.pushArray("");
    for (Integer i = 0; i < this._keys.length(); i++) {
      jb.pushObject("");
      jb.addString(this._keys[i], this._values[i]);
      jb.popLevel();
    }
    jb.popLevel();    
    
    return jb.getString();
  }
  
  String toString() {
    
  }
};