#setLanguageLevel 3;

/*
 * Read a value from crm8.userpreference table.
 */
String getUserPreferenceValue(String prefSection, String prefKey)
{
 NSPreferenceAgent prefAgent;
 NSPreferenceSpec spec;
 spec.SetKey(prefKey);
 spec.SetSection(prefSection);

 NSPreferenceSpec[1] specs;
 specs[0] = spec;
 NSPreference[] preferences = prefAgent.GetPreferences(specs);

 if (preferences.length() > 0)
  return preferences[0].GetRawValue();
 else
  return ""; //No such preference found
}

/*
 * Write a value to crm8.userpreference table
 */
Integer setUserPreferenceValue(String prefSection, String prefKey, String value)
{
 NSPreferenceAgent prefAgent;
 NSPreferenceSpec spec;
 spec.SetKey(prefKey);
 spec.SetSection(prefSection);

 NSPreferenceSpec[1] specs;
 specs[0] = spec;
 NSPreference[] prefs = prefAgent.GetPreferences(specs);

 for (Integer i = 0; i < prefs.length(); i++)
 {
  prefs[i].SetRawValue(value);
  prefAgent.SavePreference(prefs[i]);
 }

 return prefs.length();
}