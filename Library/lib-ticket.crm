#setLanguageLevel 3;

/*
 * Get a new, unsaved, Ticket object. Properties are set based mostly on the current users settings.
 */
Ticket createDefaultTicket()
{
 Ticket t;
 t.setValue("title", "(No title set)");

 //Category. Determined by users own settings.
 Integer defaultCategoryId = getActiveUser().getValue("defaultCategory").toInteger();
 FHBitSet userflags;
 userflags.set(getActiveUser().getValue("flags"));
 if (userflags.getBitNo(2)) //Use last category checkbox set
  defaultCategoryId = getActiveUser().getValue("lastCategory").toInteger();
 t.setValue("category", defaultCategoryId.toString());

 //Owned by
 Integer ownedBy;
 String defaultUserSetting = getActiveUser().getValue("defaultUser");
 if (defaultUserSetting == "1") //Automatically assigned
  ownedBy = -1;
 else if (defaultUserSetting == "2") //Unassigned
  ownedBy = 0;
 else if (defaultUserSetting == "3") //Yourself
  ownedBy = getActiveUser().getValue("id").toInteger();
 t.setValue("ownedBy", ownedBy.toString());

 //Slevel
 String slevel = "1"; //Internal by default
 SearchEngine seSlevel;
 seSlevel.addField("config.flags");
 seSlevel.execute();
 FHBitSet config;
 config.set(seSlevel.getField(0));
 if (config.getBitNo(1))
  slevel = "2"; //"External access level as default" set in System settings
 t.setValue("slevel", slevel);

 //Priority
 Integer defaultPriorityId;
 SearchEngine sePri;
 sePri.addField("ticket_priority.id");
 sePri.addField("ticket_priority.flags");
 sePri.addCriteria("ticket_priority.flags", "gt", "0");
 for (sePri.execute(); !sePri.eof(); sePri.next())
 {
  FHBitSet priorityFlags;
  priorityFlags.set(sePri.getField("ticket_priority.flags"));
  if (priorityFlags.getBitNo(1)) //Default checkbox
   defaultPriorityId = sePri.getField("ticket_priority.id").toInteger();
 }
 t.setValue("priority", defaultPriorityId.toString());

 //Status and TicketStatus
 Integer defaultTicketStatusId = getActiveUser().getValue("defaultStatusNewTicket").toInteger();
 Integer defaultStatusId = -1;
 SearchEngine seStatus;
 seStatus.addField("ticket_status.status");
 seStatus.addCriteria("ticket_status.id", "equals", defaultTicketStatusId.toString());
 for (seStatus.execute(); !seStatus.eof(); seStatus.next())
  defaultStatusId = seStatus.getField(0).toInteger();
 t.setValue("status", defaultStatusId.toString());
 t.setValue("ticketStatus", defaultTicketStatusId.toString());

 //Extrafields
 SearchEngine seEx;
 seEx.addField("extra_fields.flags");
 seEx.addField("extra_fields.field_name");
 seEx.addField("extra_fields.default_value");
 seEx.addCriteria("extra_fields.domain", "equals", "4");
 for (seEx.execute(); !seEx.eof(); seEx.next())
 {
   FHBitSet exFlags;
   exFlags.set(seEx.getField("extra_fields.flags"));
   if (exFlags.getBitNo(13)) //"Use default value" checkbox
     t.setValue(seEx.getField("extra_fields.field_name"), seEx.getField("extra_fields.default_value"));
 }

 //Other...
 t.setValue("createdBy", getActiveUser().getValue("id"));
 t.setValue("author", getActiveUser().getValue("username"));
 t.setValue("createdAt", getCurrentDateTime().toString());
 t.setValue("origin", "7"); //7 = Internal

 return t;
}

/*
 * Prepare a new, unsaved, Message object for the given ticket.
 * Will set default values based on current time, and current user.
 */
Message createDefaultMessage(Integer ticketId)
{
 Ticket t;
 t.load(ticketId);

 Message m;
 m.setValue("ticketId", ticketId.toString());
 m.setValue("createdAt", getCurrentDateTime().toString());
 m.setValue("createdBy", getActiveUser().getValue("id"));
 m.setValue("type", "1"); //1 = internal
 m.setValue("author", getActiveUser().getValue("username"));
 m.setValue("slevel", t.getValue("slevel"));
 return m;
}

/*
 * Get the ID of the row in crm8.ticket_priority that is set as the default one.
 * Returns -1 if none found.
 */
Integer getDefaultTicketPriorityId()
{
  SearchEngine se;
  se.addField("ticket_priority.id");
  se.addField("ticket_priority.flags");
  for (se.execute(); !se.eof(); se.next())
  {
    Integer priorityId = se.getField("ticket_priority.id").toInteger();
    Integer flags = se.getField("ticket_priority.flags").toInteger();
    FHBitSet bits;
    bits.set(flags);
    if (bits.getBitNo(1) == true)
      return priorityId;
  }
  return -1;
}