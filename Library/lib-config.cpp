#setLanguageLevel 3;

/*
 * Methods for working with standard tables crm8.config and crm8.registry, and custom extratable crm8.y_config.
 * 
 * IMPORTANT - expects the following ExtraTable to exist!
 * Table: y_config
 *   Field: x_key (string short)
 *   Field: x_value (string short)
 */

/*
 * Constants
 */
Integer REG_ID_CUSTOMER_COLUMNS = 226;
Integer REG_ID_COMPANY_COLUMNS = 227;
Integer REG_ID_BYPASS_NETSERVER = 235;
Integer REG_ID_MAX_ROWS_IN_GRID = 325;
//TODO - add lots more regIds...

/*
 * Read value from crm8.registry
 */
String getRegistryValue(Integer reg_id) {
  SearchEngine se;
  se.addField("registry.value");
  se.addCriteria("registry.reg_id", "equals", reg_id.toString());
  if (se.execute() > 0)
    return se.getField("registry.value");
  else
    return "";
}

/*
 * Update value in crm8.registry table. USE WITH CAUTION!
 */
Void setRegistryValue(Integer reg_id, String value) {
  SearchEngine se;
  se.addData("registry.value", value);
  se.addCriteria("registry.reg_id", "equals", reg_id.toString());
  se.bypassNetServer(true);
  se.update();
}

/*
 * Get value from extratable y_config
 */
String getConfigValue(String key) {
  SearchEngine se;
  se.addField("y_config.x_value");
  se.addCriteria("y_config.x_key", "equals", key);
  for (se.execute(); !se.eof(); se.next())
    return se.getField("y_config.x_value");
  return "";
}

/*
 * Set value in extratable y_config
 */
Void setConfigValue(String key, String value) {
  //Find ID of existing - if any.
  Integer id;
  SearchEngine se;
  se.addField("y_config.id");
  se.addCriteria("y_config.x_key", "equals", key);
  for (se.execute(); !se.eof(); se.next())
    id = se.getField("y_config.id").toInteger();
  
  //Insert/Update row.
  ExtraTable config = getExtraTable("y_config");
  if (id > 0)
  	config.load(id);
  config.setValue("x_key", key);
  config.setValue("x_value", value);
  config.save();
  //return;
}