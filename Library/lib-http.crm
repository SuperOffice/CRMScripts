#setLanguageLevel 3;

/*
 * Frode Lillerud, Ganske Enkelt AS, may 2016
 * Methods for setting HTTP responses from Customer Service.
 */

//Set default headers. Disable caching for IE.
Map _headers = Map()
  .insert("Content-Type", "application/json;charset=utf-8")
  .insert("Cache-Control", "no-cache, no-store, must-revalidate")
  .insert("Pragma", "no-cache")
  .insert("Expires", "0");

Void AddHttpHeader(String key, String value)
{
  _headers.insert(key, value);
}

Void SetHttpStatus(String status)
{
  _headers.insert("Status", status);

  //If no Content-Type is set, then default to JSON.
  if (!_headers.exists("Content-Type"))
    _headers.insert("Content-Type", "application/json;charset=utf-8");

  String h;
  for (_headers.first(); !_headers.eof(); _headers.next())
    h += _headers.getKey() + ": " + _headers.getVal() + "\n";

  setParserVariable("ej.headers", h);
}

Void Ok(String data)
{
  SetHttpStatus("200 OK");
  print(data);
}

Void Ok()
{
  SetHttpStatus("200 OK");
}

Void Created(String location)
{
  AddHttpHeader("Location", location);
  SetHttpStatus("201 Created");
}

Void NoContent()
{
  SetHttpStatus("204 No Content");
}

Void BadRequest()
{
  SetHttpStatus("400 Bad Request");
}

Void BadRequest(String message)
{
  SetHttpStatus("400 Bad Request - " + message);
}

Void Unauthorized()
{
  SetHttpStatus("401 Unauthorized");
}

Void Forbidden() {
  SetHttpStatus("403 Forbidden");
}

Void NotFound()
{
  SetHttpStatus("404 Not Found");
}

Void MethodNotAllowed()
{
  SetHttpStatus("405 Method Not Allowed");
}

Void InternalError(String message)
{
  SetHttpStatus("500 Internal Error");
  print(message);
}

Void NotImplemented()
{
  SetHttpStatus("501 Not Implemented");
}

Void Redirect(String location)
{
  AddHttpHeader("Location", location);
  return SetHttpStatus("302 Found");
}

Void TooManyRequests(Integer retryAfter)
{
  AddHttpHeader("Retry-After", retryAfter.toString());
  return SetHttpStatus("429 Too Many Requests");
}