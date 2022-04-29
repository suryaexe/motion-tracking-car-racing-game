#include <Adafruit_SSD1306.h>
Adafruit_SSD1306 display(4);
int lap = 3;
int lap2 = 6;
int counter = 0;
int currentstate = 0;
int previousstate = 0;
int counter1 = 0;
int currentstate1 = 0;
int previousstate1 = 0;
long last_lap = 0;
long best_lap = 0;
long last_lap1 = 0;
long best_lap1 = 0;
unsigned long current_millis;
unsigned long prev_millis;
double lap_time = 0;
unsigned long current_millis1;
unsigned long prev_millis1;
double lap_time1 = 0;
void setup()
{
  pinMode(lap, INPUT);
  //pinMode(lap2, INPUT);
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3c);
  display.clearDisplay();
  display.setTextSize(1.5);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println("Lap counter");
  display.display();
  delay(5000);
}
void loop()
{
  int  lap1 = digitalRead(lap);
  int  lap3 = digitalRead(lap2);
  if (lap1 == 0) {
    currentstate = 1;
  }
  else {
    currentstate = 0;
  }
  if (lap3 == 0) {
    currentstate1 = 1;
  }
  else {
   currentstate1 = 0;
    delay(100);
  }
  if (currentstate != previousstate) {
    if (currentstate == 1) {
      counter = counter + 1;
      current_millis = millis();
      lap_time = current_millis - prev_millis;
      prev_millis = millis();
      Serial.print("lap = ");
      Serial.println(counter);
      //Serial.println(current_millis);
      //Serial.println(prev_millis);
      Serial.print("**LAP TIME** :");
      long lap_times = lap_time / 1000;
      lap_times = last_lap;
      if (best_lap <= last_lap ) {
        last_lap = best_lap;
        Serial.println(best_lap);
      }
      Serial.println(lap_times);
      //Serial.print(" Sec");

      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(WHITE);
      display.setCursor(0, 0);
      display.println("LAP = ");
      display.print(counter);
      display.println("**Lap Time**");
      display.print(lap_time / 1000);
      //display.print();

      display.display();
      delay(100);
    }
  }
  if (currentstate1 != previousstate1) {
   if (currentstate1 == 1) {
      counter1 = counter1 + 1;
      current_millis1 = millis();
      lap_time1 = current_millis1 - prev_millis1;
      prev_millis1 = millis();
      Serial.println("##############################################################");

      Serial.print("player2 lap = ");
      Serial.println(counter1);
      //Serial.println(current_millis1);
      //Serial.println(prev_millis1);

      Serial.print("**player2-LAP TIME** :");
     // Serial.println(lap_time1 / 1000);
      long lap_times1 =lap_time1 / 1000;
     lap_times1 = last_lap1;
      if (best_lap1 <= last_lap1 ) {
        last_lap1 = best_lap1;
        Serial.println(best_lap1);
      }
      Serial.println(lap_times1);
      //Serial.print(" Sec");

      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(WHITE);
      display.setCursor(0, 0);
      display.println("LAP = ");
      display.print(counter1);
      display.println("**Lap Time**");
      display.print(lap_time1 / 1000);
      display.display();
      delay(100);
    }
  }
}
