#define ledPin 5 /* GPIO5 (D1) for LED /

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
  pinMode(4, OUTPUT);
  digitalWrite(4, HIGH);
  digitalWrite(LED_BUILTIN, HIGH);
}

// the loop function runs over and over again forever
void loop() {
  delay(4000);
  digitalWrite(ledPin, LOW);
  Serial.println("\nsleeping"); 
 // ESP.deepSleep(10e6); / Sleep for 5 seconds */
  //digitalWrite(4, LOW);
  delay(2000);
   Serial.println("\n no sleeping\n");
   digitalWrite(LED_BUILTIN, LOW);
   delay(2000);

}
