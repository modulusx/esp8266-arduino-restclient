#include "restclient.h"
#include <WiFiClient.h>
#include "Arduino.h"

restclient::restclient(const char *host, int port) {
  _host = host;
  _port = port;
}

bool restclient::get(const char *path) {
  if (!_wfc.connect(_host, _port)) {
    return false;
  }

  _wfc.print("GET ");
  _wfc.print(path);
  _wfc.println(" HTTP/1.1");
  _wfc.print("Host: ");
  _wfc.println(_host);
  _wfc.println("Connection: close");
  _wfc.println();
  
  _wfc.stop();
  return true;
}

bool restclient::put(const char *path, const char *params) {
  if (!_wfc.connect(_host, _port)) {
    return false;
  }

  _wfc.print("PUT ");
  _wfc.print(path);
  _wfc.println(" HTTP/1.1");
  _wfc.print("Host: ");
  _wfc.println(_host);
  _wfc.println("Connection: close");
  _wfc.println("Content-Type: application/x-www-form-urlencoded");
  _wfc.print("Content-Length: ");
  _wfc.print(strlen(params));
  _wfc.println("\r\n");
  _wfc.print(params);

  delay(100);
  _wfc.stop();
  return true;
}

bool restclient::post(const char *path, const char *params) {
  if (!_wfc.connect(_host, _port)) {
    return false;
  }

  _wfc.print("POST ");
  _wfc.print(path);
  _wfc.println(" HTTP/1.1");
  _wfc.print("Host: ");
  _wfc.println(_host);
  _wfc.println("Connection: close");
  _wfc.println("Content-Type: application/x-www-form-urlencoded");
  _wfc.print("Content-Length: ");
  _wfc.print(strlen(params));
  _wfc.println("\r\n");
  _wfc.print(params);

  delay(100);
  _wfc.stop();
  return true;
}

bool restclient::del(const char *path) {
  if (!_wfc.connect(_host, _port)) {
    return false;
  }

  _wfc.print("DELETE ");
  _wfc.print(path);
  _wfc.println(" HTTP/1.1");
  _wfc.print("Host: ");
  _wfc.println(_host);
  _wfc.println("Connection: close");
  _wfc.println();
  
  _wfc.stop();
  return true;
}
