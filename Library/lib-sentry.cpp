#setLanguageLevel 3;

/*
 * Methods for working with SentryPreference rows in crm8.userpreference
 */

Integer PREF_LEVEL_ALL = 2;
Integer PREF_LEVEL_GROUP = 4;
Integer PREF_LEVEL_USER = 5;

Integer SENTRY_FLAG_READ = 1;
Integer SENTRY_FLAG_UPDATE = 2;
Integer SENTRY_FLAG_INSERT = 4;
Integer SENTRY_FLAG_DELETE = 8;
Integer SENTRY_FLAG_FILTER = 16;
Integer SENTRY_FLAG_RESTRICTEDUPDATE = 32;

/*
 * Delete all Sentry Preferences
 */
Void deleteAllSentryPreferences()
{
	SearchEngine del;
	del.addCriteria("UserPreference.prefsection", "beginswith", "Rights");
	del.delete();
}

Void deleteSentryPreferencesForKey(String key)
{
  SearchEngine del;
  del.addCriteria("UserPreference.prefsection", "beginswith", "Rights");
  del.addCriteria("UserPreference.prefkey", "equals", key);
  del.delete();
}


/*
 Level: 2=System, 3=Database, 4=Usergroup, 5=User
 OwnerId: If level is 4 or 5, then this points to usergroup_id or associate_id
 PrefSection: 'Rights-person', 'Rights-contact-existing', 'Rights-sale-new' etc.
 PrefKey: 'Table', 'contact.number2', udsalesmall.long05'
 PrefValue: '1, Tooltip' where number is access level
 Access level bitflags:
 	1 = Read
  2 = Update
  4 = Insert
  8 = Delete
  16 = Filter
  32 = RestrictedUpdate
  Example: 51 = 1+2+16+32 (not insert(4) or delete(8))
  Example: 63 = full access 
 */
NSPreference addSentryPreference(Integer level, Integer ownerId, String prefsection, String prefkey, String prefvalue)
{
  //Create row in crm7.userpreference
  NSPreferenceAgent prefAgent;
  NSPreferenceSpec[] specs;
  NSPreferenceSpec spec;
  spec.SetSection(prefsection);
  spec.SetKey(prefkey);
  prefAgent.GetPreferences(specs);
  NSPreference pref = prefAgent.CreateDefaultPreference();
  pref.SetSpecification(spec);
  pref.SetRawValue(prefvalue);
  pref.SetLevel(level);
  pref.SetTargetId(ownerId);
  pref = prefAgent.SavePreferenceEntity(pref, false);
  return pref;
}

/*
 * Get all preferences from crm8.userpreference where prefsection starts with 'Rights-'
 */
NSPreference[] getAllSentryPreferences()
{
  NSPreferenceAgent prefAgent;
  NSPreference[] prefs;
  
  //Use SearchEngine to find all
  SearchEngine se;
  se.addField("UserPreference.userpreference_id");
  se.addCriteria("UserPreference.prefsection", "beginswith", "Rights-");
  for (se.execute(); !se.eof(); se.next())
  {
    //Load up each one and add to array.
    Integer userpreferenceId = se.getField("UserPreference.userpreference_id").toInteger();
    NSPreference p = prefAgent.GetPreference(userpreferenceId);
    prefs.pushBack(p);
  }
  
  return prefs;  
}