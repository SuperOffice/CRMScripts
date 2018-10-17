#setLanguageLevel 3;
#include "lib-consent";

/*
 * Example for working with Consent and Subscriptions
 */

Integer personId = 338;

String sourceKey = CONSENT_SOURCE_API_KEY;
String legalKey = LEGALBASE_61F_KEY;
String comment = "Set from CRMScript";

setEmarketingConsent(personId, sourceKey, legalKey, comment);
//removeEmarketingConsent(personId);

//Add these subcriptions
Integer[] add;
add.pushBack(4);

//Remove these subscriptions
Integer[] remove;
remove.pushBack(1);
remove.pushBack(2);
remove.pushBack(3);

setShipmentTypeReservations(personId, add, remove);