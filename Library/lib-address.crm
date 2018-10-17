#setLanguageLevel 3;

/*
 * Helpermethods for working with Addresses in SuperOffice CRM and Service.
 */

Map validAddressTypes;
validAddressTypes.insert("PostalAddress1", "");
validAddressTypes.insert("PostalAddress2", "");
validAddressTypes.insert("PostalAddress3", "");
validAddressTypes.insert("PostalCity", "");
validAddressTypes.insert("PostalCounty", "");
validAddressTypes.insert("PostalState", "");
validAddressTypes.insert("PostalZipcode", "");
validAddressTypes.insert("StreetAddress1", "");
validAddressTypes.insert("StreetAddress2", "");
validAddressTypes.insert("StreetAddress3", "");
validAddressTypes.insert("StreetCity", "");
validAddressTypes.insert("StreetCounty", "");
validAddressTypes.insert("StreetState", "");
validAddressTypes.insert("StreetZipcode", "");
//validAddressTypes.insert("ContactStreetAddress", "");
//validAddressTypes.insert("ContactPostalAddress", "");
//validAddressTypes.insert("PersonPostalAddress", "");
//validAddressTypes.insert("PersonStreetAddress", "");

//Get the addresses of a contact as values in a map.
Map getContactAddresses(NSContactEntity contact)
{
  NSAddress contactAddress = contact.GetAddress();
  NSLocalizedField[][] fields = contactAddress.GetLocalizedAddress();

  Map addr;
  for (Integer i=0; i < fields.length(); i++)
  {
    for (Integer j=0; j<fields[i].length(); j++)
    {
      addr.insert(fields[i][j].GetName(), fields[i][j].GetValue());
    }
  }
  return addr;
}

NSContactEntity setContactAddresses(NSContactEntity contact, Map addresses)
{
  //For troubleshooting - detect illegal addresstypes.
  for (addresses.first(); !addresses.eof(); addresses.next())
    if (!validAddressTypes.exists(addresses.getKey()))
      exitWithMessage("Illegal address type: " + addresses.getKey());

  NSAddress contactAddress = contact.GetAddress();
  NSLocalizedField[][] fields = contactAddress.GetLocalizedAddress();

  for (Integer i = 0; i < fields.length(); i++)
  {
    for (Integer j = 0; j < fields[i].length(); j++)
    {
      if (addresses.exists(fields[i][j].GetName()))
      {
        fields[i][j].SetValue(addresses.get(fields[i][j].GetName()));
      }
    }
  }
  contactAddress.SetLocalizedAddress(fields);
  contact.SetAddress(contactAddress);
  return contact;
}

//Converts the NSLocalizedField multiarray to a Map.
Map getAddresses(NSLocalizedField[][] fields) {
  Map addr;
  for (Integer i=0; i < fields.length(); i++)
  {
    for (Integer j=0; j<fields[i].length(); j++)
    {
      addr.insert(fields[i][j].GetName(), fields[i][j].GetValue());
    }
  }
  return addr;
}