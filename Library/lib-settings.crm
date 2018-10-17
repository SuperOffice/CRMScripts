#setLanguageLevel 3;

/*
 * Get the base URL used by CRM
 */
String getCRMBaseURL()
{
  SearchEngine se;
  se.addField("UserPreference.prefvalue");
  se.addCriteria("UserPreference.prefkey", "equals", "CRMBaseURL");
  for (se.execute(); !se.eof(); se.next())
    return se.getField(0);

  return "";
}

//printLine(getCRMBaseURL());