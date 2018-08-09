
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include <Servo.h>

#define FIREBASE_HOST "alarmclock-e7478.firebaseio.com"
#define FIREBASE_AUTH "FGXx5q7eMlInj1gof5eiL2xe9ZA1xY6WJkEV7Njg"
#define wifi_ssid "Hoi"
#define wifi_pass "abcdefgh"

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
