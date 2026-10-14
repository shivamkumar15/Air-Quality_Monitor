#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

#define MQ135_PIN     A0
#define DHT_PIN       2
#define DHT_TYPE      DHT11
#define RED_LED_PIN   7
#define GREEN_LED_PIN 6   // Optional: Normal indicator LED
#define BUZZER_PIN    8

const bool IS_PASSIVE_BUZZER = true; 

// Initial demonstration threshold (adjust based on your Serial Monitor readings)
const int GAS_THRESHOLD = 300;

DHT dht(DHT_PIN, DHT_TYPE);

void activateAlarm() {
  digitalWrite(RED_LED_PIN, HIGH);
  digitalWrite(GREEN_LED_PIN, LOW);

  if (IS_PASSIVE_BUZZER) {
    // Generate an audible 1500 Hz alarm tone
    tone(BUZZER_PIN, 1500); 
  } else {
    // Turn on active buzzer
    digitalWrite(BUZZER_PIN, HIGH);
  }
}

void deactivateAlarm() {
  digitalWrite(RED_LED_PIN, LOW);
  digitalWrite(GREEN_LED_PIN, HIGH);

  if (IS_PASSIVE_BUZZER) {
    noTone(BUZZER_PIN);
  } else {
    digitalWrite(BUZZER_PIN, LOW);
  }
}

void setup() {
  Serial.begin(9600);

  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  deactivateAlarm();
  dht.begin();

  lcd.init();
  lcd.backlight();
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Air Quality");
  lcd.setCursor(0, 1);
  lcd.print("Warming up...");

  // Quick self-test: beeps and flashes once at startup to confirm wiring
  digitalWrite(RED_LED_PIN, HIGH);
  if (IS_PASSIVE_BUZZER) tone(BUZZER_PIN, 1000);
  else digitalWrite(BUZZER_PIN, HIGH);
  delay(300);
  deactivateAlarm();

  delay(1700);
  lcd.clear();
}

void loop() {
  int gasValue = analogRead(MQ135_PIN);
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  bool gasAlert = (gasValue >= GAS_THRESHOLD);

  if (gasAlert) {
    activateAlarm();
  } else {
    deactivateAlarm();
  }

  Serial.print("MQ135 Gas: ");
  Serial.print(gasValue);
  Serial.print(" | Threshold: ");
  Serial.print(GAS_THRESHOLD);
  Serial.print(" | Status: ");
  Serial.println(gasAlert ? "ALERT!" : "OK");

  lcd.setCursor(0, 0);
  lcd.print("Gas:");
  lcd.print(gasValue);
  lcd.print("   "); 

  lcd.setCursor(10, 0);
  if (gasAlert) {
    lcd.print("ALERT ");
  } else {
    lcd.print("NORMAL");
  }

  lcd.setCursor(0, 1);
  if (isnan(temperature) || isnan(humidity)) {
    lcd.print("DHT11 Error     ");
  } else {
    lcd.print("T:");
    lcd.print((int)temperature);
    lcd.print((char)223); 
    lcd.print("C H:");
    lcd.print((int)humidity);
    lcd.print("%   ");
  }

  delay(1000);
}
