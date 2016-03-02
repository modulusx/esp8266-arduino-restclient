#ifndef restclient_h
#define restclient_h

#include <WiFiClient.h>
#include "Arduino.h"

class restclient {
  public:
    restclient(const char *host,int port);
    bool get(const char *path);
    bool put(const char *path,const char *params);
    bool post(const char *path,const char *params);
    bool del(const char *path);
  private:
    WiFiClient _wfc;
    const char *_host;
    int _port;
};

#endif
