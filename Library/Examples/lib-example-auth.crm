#setLanguageLevel 3;
#include "lib-auth";

String username = "elvis";
String password = "presley";

Customer cust = loginAsCustomer(username, password);
printLine("Logged in as user: " + cust.getValue("firstname"));
printLine("Session Key: " + cust.getValue("loginSessionKey"));