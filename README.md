# esp8266-arduino-restclient
Crappy library to enable Sparkfun ESP8266 Thing to blindly get/put/post/delete

The library ignores all return values and does NOT support HTTPS, but since I'm only using it internally, I don't mind.

Here is an [example](https://github.com/modulusx/esp8266-arduino-hueremote) using it to control Hue lights.

You'll also need to do your own URL encoding if you're going to try to send any restricted characters, sorry.
