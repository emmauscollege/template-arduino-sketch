// definieer constanten voor je pinnen
const int LED_PIN = 12;
const int BUTTON_PIN = 2;


// definieer statussen
int ledStatus = LOW;
int buttonStatus = LOW;


// definieer eventuele overige globale variabelen



void setup() {
  // setup wordt eenmaal aangeroepen
  // stel hier in of een digital poort INPUT of OUTPUT is
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);

  // om te debuggen moet je berichten
  // naar je computer kunnen sturen:
  Serial.begin(9600);
}

void loop() {
  // update de status van je sensor(s)
  buttonStatus = digitalRead(KNOP_PIN);


  // update op basis van sensordata de actuatorstatus(sen)
  if (buttonStatus == HIGH) {
    ledStatus = LOW;
  }
  else {
    ledStatus = HIGH;
  }


  // doorvoeren van actuatorstatussen
  digitalWrite(LED_PIN, ledStatus);
}
