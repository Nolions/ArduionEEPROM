#include <EEPROM.h>

int ssinCahts[] = {5, 6, 7, 8, 9};
bool isOK = false;

void setup() {
  Serial.begin(9600);
  Serial.println("======eeprom_write======");

  clear();
}

void loop() {
  if (!isOK) {
    int size = sizeof(ssinCahts) / sizeof(int);
    writeSSIN(ssinCahts, size);
  }

  delay(1000);
}

void writeSSIN(int codes[], int size) {
  for (int i = 0; i < size; i++) {
    int num = codes[i];

    Serial.print("ssin_");
    Serial.print(i);
    Serial.print(":");
    Serial.println(num);
    EEPROM.write(i, num);
    isOK = true;
  }
}

void clear() {
  for (int i = 0; i < 512; i++) {
    EEPROM.write(i, 0);
  }
}
