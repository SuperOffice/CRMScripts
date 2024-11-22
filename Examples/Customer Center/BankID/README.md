# Customer Center - BankId sample

To be able to login with bankid on the customer center there needs to be registed an unique identifier on each person inside of SuperOffice. BankId has a set of properties you can fetch through the userinfo-endpoint, so the most common/natural would be to use social security number as that is unique per person.

Actual credentials to test the flow are not included in this sample. Please contact digdir (or any other provider of your choice) to get access to a client_id and client_secret.
The baseURL needs to be adjusted depending on what provider is chosen.

## In this solution

* lib-difi.crmscript - helper library for handling requests and type definitions
* difi-login.crmscript - the crmscript that gets the callback after the user has logged inn at idporten
* login.html - Edited login.html, which adds a button to start the authentication flow

### #Step 1

login.html adds a button, 'Log in with difi', that forwards the user to difi/bankid for authorization.
```
<input type='button'  value="Log in with difi" onclick="difi_login()">

<script>
function difi_login() {
  let url = new URL('https://oidc-ver1.difi.no/idporten-oidc-provider/authorize');
  url.searchParams.append('client_id', '52aa0c83-8ee0-......');
  url.searchParams.append('scope', 'openid');
  url.searchParams.append('response_type', 'code');
  url.searchParams.append('redirect_uri', 'https://{environment}.superoffice.com/{tenant}/CS/scripts/customer.fcgi?action=safeParse&includeId=difi-login&key={key}');
  url.searchParams.append('state', 'authorize');
  window.location.assign(url);
}

</script>
```

The redirect_uri defined is a crmscript that receives the authorization code.

### Step 2

The crmscript then exchanges this code for a token, fetches some userinfo and looks up the social security number in the database. If a person is found it uses Customer.login() and forwards the user to the customer center with `set-cookie: custSessionKey=validSession`.
