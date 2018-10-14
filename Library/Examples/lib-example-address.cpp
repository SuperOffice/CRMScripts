#setLanguageLevel 3;
#include "lib-address";

/* Example code for using the address helper */

Integer contactId = 3;

//Find a contact
NSContactAgent contactAgent;
NSContactEntity contact = contactAgent.GetContactEntity(contactId);

//Get the addresses
Map adr = getContactAddresses(contact);

for (adr.first(); !adr.eof(); adr.next())
  printLine(adr.getKey() + " => " + adr.getVal());

//Change address
adr.insert("StreetAddress1", "Testroad 1");
adr.insert("StreetZipcode", "1234");
adr.insert("StreetCity", "TEST");
setContactAddresses(contact, adr);

//Save contact with new address info
contact = contactAgent.SaveContactEntity(contact);