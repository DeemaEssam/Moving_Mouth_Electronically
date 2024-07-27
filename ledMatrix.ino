#include <LedControl.h>

int DIN = 12;
int CS =  11;
int CLK = 10;
LedControl lc = LedControl(DIN, CLK, CS, 0); // Create LedControl object

void setup() {
  lc.shutdown(0, false);       
  lc.setIntensity(0, 15);
  lc.clearDisplay(0);
}

void loop() {
  delay(100);

  // Pattern for TALK1
  byte TALK1[8] = {  
    B00111100,
    B01000010,
    B10100101,
    B10000001,
    B10011001,
    B10100101,
    B01011010,
    B00111100
  };
  printByte(TALK1);
  delay(100);
  
  // Pattern for TALK2
  byte TALK2[8] = {
    B00111100,
    B01000010,
    B10100101,
    B10000001,
    B10000001,
    B10111101,
    B01000010,
    B00111100
};
  printByte(TALK2);
  delay(100);
}

void printByte(byte character[]) {
  for (int i = 0; i < 8; i++) {
    lc.setRow(0, i, character[i]); // Set each row of the display
  }
}
