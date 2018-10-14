#setLanguageLevel 3;

/*
 * Library which makes working with Consent easier
 * Frode Lillerud, Ganske Enkelt AS, october 2018
 */

//Default consentpurposes
String CONSENT_PURPOSE_STORE_KEY = "STORE";
String CONSENT_PURPOSE_EMARKETING_KEY = "EMARKETING";

//Default consentsources (crm7.consentsource)
String CONSENT_SOURCE_USER_KEY = "USER";
String CONSENT_SOURCE_EMAIL_KEY = "EMAIL";
String CONSENT_SOURCE_REQUEST_KEY = "REQUEST";
String CONSENT_SOURCE_CHAT_KEY = "CHAT";
String CONSENT_SOURCE_WEBFORM_KEY = "WEBFORM";
String CONSENT_SOURCE_CUSTOMERPORTAL_KEY = "CUSTOMERPORTAL";
String CONSENT_SOURCE_IMPORT_KEY = "IMPORT";
String CONSENT_SOURCE_API_KEY = "API";
String CONSENT_SOURCE_UNKNOWN_KEY = "UNKNOWN";

//Default legalbases
String LEGALBASE_WITHDRAWN_KEY = "WITHDRAWN";
String LEGALBASE_61A_KEY = "61A";
String LEGALBASE_61B_KEY = "61B";
String LEGALBASE_61C_KEY = "61C";
String LEGALBASE_61D_KEY = "61D";
String LEGALBASE_61E_KEY = "61E";
String LEGALBASE_61F_KEY = "61F";


//Removes the consent or E-marketing.
Void removeEmarketingConsent(Integer personId) {
  NSPersonAgent personAgent;
  personAgent.RemoveConsent(personId, CONSENT_PURPOSE_EMARKETING_KEY);
}

//Toggle ON the E-marketing Consent for given person ID.
Void setEmarketingConsent(Integer personId, String sourceKey, String legalKey, String comment) {
  NSPersonAgent personAgent;
  personAgent.SetConsent(personId, CONSENT_PURPOSE_EMARKETING_KEY, sourceKey, legalKey, comment);  
}


//Adds and removes shipment type reservations for the given person.
//Shipmenttype IDs not included in the arrays are not touched.
Void setShipmentTypeReservations(Integer personId, Integer[] add, Integer[] remove) {
  NSPersonAgent personAgent;
  NSPersonEntity person = personAgent.GetPersonEntity(personId);
  NSSelectableMDOListItem[] shipments = person.GetShipmentTypes();
  
  //For each existing shipments..
  for (Integer i = 0; i < shipments.length(); i++) {
  
    //Loop over all shipments we want to ADD
    for (Integer j = 0; j < add.length(); j++) {
      if (shipments[i].GetId() == add[j])
        shipments[i].SetSelected(true);  
    }
    
    //Loop over all shipments we want to REMOVE
    for (Integer k = 0; k < remove.length(); k++) {
      if (shipments[i].GetId() == remove[k])
        shipments[i].SetSelected(false);
    }
  }
  
  person.SetShipmentTypes(shipments);
  personAgent.SavePersonEntity(person);
}