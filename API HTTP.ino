#include<WiFi.h>
#include <HTTPClient.h>
const char* ssid = "Wokwi-GUEST";
const char* pass = "";

unsigned const long interval = 2000;
unsigned long zero = 0;

void setup(){
  Serial.begin(115200);
  WiFi.begin(ssid, pass);
  while(WiFi.status() != WL_CONNECTED){
    delay(100);
    Serial.println(".");
  }
  Serial.println("WiFi Connected!");
  Serial.println(WiFi.localIP());

}

void loop(){

  if(millis()-zero > interval){

    HTTPClient http;
    http.begin("https://spm.com.np/json.php/1");
    int httpResponCode = http.GET();
    Serial.println(httpResponCode);
    if(httpResponCode > 0){
      String payload = http.getString();
      Serial.print(payload);
    }else{
      Serial.print("error ");
      Serial.println(httpResponCode);
    }

    zero = millis();
  }
  
}