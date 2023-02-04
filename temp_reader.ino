#include<LiquidCrystal.h>
#include<Wire.h>

//TC74 connected to pins SDA-A5  SCL-A4 VCC-5v GND-GND


LiquidCrystal lcd(2,3,4,5,6,7);

int temp=72;
void setup() {
  lcd.begin(16,2);
  Wire.begin();

}

void loop() {
lcd.setCursor(0,1);
Wire.beginTransmission(temp);
Wire.write(0);
Wire.endTransmission();
Wire.requestFrom(temp,1);
while (Wire.available>0){
  int c=Wire.read();
}
lcd.print(c);
lcd.print("C");
delay(1000);
}
