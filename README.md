# Esp8266_DDNSv6
An IPv6 ddns client for esp8266  

If you don't have a NAS or an openwrt router, you can run the DDNS client on a cheap esp8266 chip.  

You should register at https://dynv6.com/ and add a `HTTP Token` at https://dynv6.com/keys.  
It can change the prefix of all records in a zone.
Remenber to change the const strings in `main.cpp`.

If you are using `PlatformIO`, add `-D PIO_FRAMEWORK_ARDUINO_LWIP2_IPV6_LOW_MEMORY` to `build_flags` in `platformio.ini`.
```
build_flags =
    -D PIO_FRAMEWORK_ARDUINO_LWIP2_IPV6_LOW_MEMORY
```

If you are using `Arduino IDE`, select a LwIP option with IPv6.
![image](https://user-images.githubusercontent.com/31466039/152389799-9d08b210-bed6-482b-b7f9-7cfaeaad1749.png)

