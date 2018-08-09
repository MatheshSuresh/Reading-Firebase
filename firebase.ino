
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

#define FIREBASE_HOST "HOST"
#define FIREBASE_AUTH "AUTH_KEY"
#define wifi_ssid "SSID"
#define wifi_pass "PASS"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  WiFi.begin(wifi_ssid,wifi_pass);
  Serial.print("Connecting...");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");    
    delay(500);    
    }
  Serial.println("Connected");
  Serial.println(WiFi.localIP());
  Firebase.begin(FIREBASE_HOST,FIREBASE_AUTH);
  Firebase.setInt("LEDStatus",0);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Firebase.getInt("LEDStatus")){
    digitalWrite(LED_BUILTIN, HIGH);
    }
  else{
    digitalWrite(LED_BUILTIN,LOW);
    }

  if (Firebase.failed()){
    Serial.println("Setting Number Failed...");
    Serial.println(Firebase.error());
    }
    delay(1000);
}
