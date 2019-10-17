// definieer constanten voor je pinnen
const int LED_PIN = 13;
const int POTMETER_PIN = A0;


// definieer statussen
int potmeterWaarde = 0;
// de volgende variabele houdt bij wat de millis waren toen de LED de laatste keer werd omgezet
// een unsigned long is een int, maar dan voor veel grotere (positieve) getallen
unsigned long vorigeLEDToggleMillis = 0;
int ledStatus = LOW;



// definieer eventuele overige globale variabelen
int wachtTijdVoorLED = 0;


void setup() {
  // setup wordt eenmaal aangeroepen
  // stel hier in of een digital poort INPUT of OUTPUT is
  pinMode(LED_PIN, OUTPUT);

  // om te debuggen moet je berichten
  // naar je computer kunnen sturen:
  Serial.begin(9600);
}

void loop() {
  // update de status van je sensor(s)
  potmeterWaarde = analogRead(POTMETER_PIN);
  wachtTijdVoorLED = potmeterWaarde * 10;     // de LED staat dus max 10230 milliseconden aan of uit

  unsigned long huidigeMillis = millis();
  int verstrekenTijd = huidigeMillis - vorigeLEDToggleMillis;



  // update op basis van sensordata de actuatorstatus(sen)
  if (verstrekenTijd > wachtTijdVoorLED) {
    if (LEDStatus == HIGH) {
      ledStatus = LOW;
    }
    else {
      ledStatus = HIGH;
    }

    // stel vorigeLEDToggleMillis in op de milliseconden van nu
    vorigeLEDToggleMillis = huidigeMillis;
  }



  // doorvoeren van actuatorstatussen
  digitalWrite(LED_PIN, ledStatus);
}
