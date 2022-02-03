#include <ESP8266HTTPClient.h>

class dynv6
{
private:
    String token;
    String zone;

public:
    dynv6(String _token,String _zone)
    {
        token = _token;
        zone = _zone;
    }
    int update(String ip)
    {
        WiFiClient client;
        HTTPClient http;

        String path = "http://dynv6.com/api/update?token="+token+"&zone="+zone+"&ipv6prefix="+ip;

        http.begin(client, path.c_str());
        http.GET();
        String payload = http.getString();
        http.end();
        if (payload == "addresses updated")
            return 0;
        if (payload == "addresses unchanged")
            return 1;
        return -1;
    }
};
