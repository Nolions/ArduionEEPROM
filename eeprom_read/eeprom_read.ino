#include <EEPROM.h>

void setup() {
  Serial.begin(9600);
  Serial.println("======eeprom_read setup======");

  Serial.println(getSSINCode());
}

void loop() {
  // todo
  delay(1000);
}

String getSSINCode() {
  String ssin = "";
  for (int i = 0; i < 5; i++) {
    int num = EEPROM.read(i);
    //    Serial.println(num);
    ssin[i] = num;
    ssin = String(ssin + num);
  }

  return ssin;
}
