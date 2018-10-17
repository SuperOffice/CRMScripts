#setLanguageLevel 3;
#include "lib-sentry";

//Delete all
deleteAllSentryPreferences();
//return;

//Create new
/*
addSentryPreference(2, 0, "Rights-contact", "contact.number2", "1, Only read"); //All users - set number field on contact as read-only.
addSentryPreference(2, 0, "Rights-person", "udpersonsmall.long05", "1, Readable for System."); //All users, set a userdefined field as read-only.
addSentryPreference(4, 3, "Rights-person", "udpersonsmall.long05", "63, Full access for this group."); //For usergroup 3, give full access to the udef above.
addSentryPreference(2, 0, "Rights-sale", "table", "1"); //All users, only read access to all sales
addSentryPreference(5, 5, "Rights-project-new", "table", "1, Cannot create new projects"); //AssociateId 5 cannot create projects
addSentryPreference(5, 5, "Rights-contact-5", "table", "1, Cannot edit this company"); //AssociateId 5 cannot edit contact_id 5 (Sparkfun)
addSentryPreference(5, 5, "Rights-project-2", "project.name", "1, Cannot edit this company"); //AssociateId 5 cannot change name on project id 2 (Example project)
addSentryPreference(2, 0, "Rights-contact", "udcontactsmall.long13", "0, Hidden"); //Hide the userdefined field
addSentryPreference(2, 0, "Rights-contact", "udcontactsmall.long13", "0, Hidden"); //Hide the userdefined field
*/
//addSentryPreference(5, 5, "Rights-contact-2866", "table", "63, Full access given to this contact"); //AssociateId 5 is given full rights to this company, which he normally cannot see
addSentryPreference(PREF_LEVEL_ALL, 0, "Rights-contact", "udcontactsmall.long15", "1, Your usergroup can only read.");
addSentryPreference(PREF_LEVEL_GROUP, 1, "Rights-contact", "udcontactsmall.long15", "63, Full access for usergroup 1");

//printLine(getActiveUser().getValue("associateId"));


//List all Sentry Preferences
NSPreference[] preferences = getAllSentryPreferences();
for (Integer i = 0; i < preferences.length(); i++)
{
  NSPreference p = preferences[i];
  print(p.GetUserPreferenceId().toString() + "\t");
  print(p.GetLevel().toString() + "\t");
  print(p.GetTargetId().toString() + "\t");
  print(p.GetSpecification().GetSection() + "\t");
  print(p.GetSpecification().GetKey() + "\t");
  printLine(p.GetRawValue() + "\t");
}


/*
SearchEngine se;
se.addField("UserPreference.userpreference_id");
se.addField("UserPreference.deflevel");
se.addField("UserPreference.maxlevel");
se.addField("UserPreference.owner_id");
se.addField("UserPreference.prefsection");
se.addField("UserPreference.prefkey");
se.addField("UserPreference.prefvalue");
se.addCriteria("UserPreference.prefsection", "beginswith", "Rights");
for (se.execute(); !se.eof(); se.next())
{
  print(se.getField(0) + "\t");
  print(se.getField(1) + "\t");
  print(se.getField(2) + "\t");
  print(se.getField(3) + "\t");
  print(se.getField(4) + "\t");
  print(se.getField(5) + "\t");
  printLine(se.getField(6) + "\t");
}
*/