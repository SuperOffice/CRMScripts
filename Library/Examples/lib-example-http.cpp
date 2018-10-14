%EJSCRIPT_START%
<%
#setLanguageLevel 3;
#include "lib-http";

/*
 * An example microservice that uses the lib-http helper.
 * See also blogpost: https://community.superoffice.com/en/developer/blog/building-custom-rest-api-methods-using-crmscript/
 */

//Execute the script by navigating to:
// /scripts/customer.exe?action=safeParse&includeId=lib-example-http&key=yourkey&contactId=2

Struct Response {
  String name;
  String department;
  Integer contactId;
  
  String toJson() {
    JSONBuilder jb;
		this.toJson(jb);
		return jb.getString();
  }
};

Integer contactId = getCgiVariable("contactId").toInteger();
if (contactId <= 0)
  return BadRequest("No contactId in URL");

NSContactAgent contactAgent;
NSContact contact = contactAgent.GetContact(contactId);

if (contact.GetContactId() != contactId)
  return NotFound();

Response r;
r.name = contact.GetName();
r.department = contact.GetDepartment();
r.contactId = contact.GetContactId();

return Ok(r.toJson());

%>
%EJSCRIPT_END%