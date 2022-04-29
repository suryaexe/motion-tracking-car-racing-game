const int IN3 = 12; 
const int IN4 = 5;

int inputPin = 9; // signal receiver pin ECHO to D4
int outputPin = 8; // signal transmitter pin TRIG to D5

int myspeed = 0;
int olddistance = 0;
int steps = 0;
int buzzer = 4;
unsigned long current_millis;
unsigned long prev_millis;

void setup() {
  Serial.begin(9600);
  pinMode(inputPin, INPUT);
  pinMode(outputPin, OUTPUT);
  digitalWrite(outputPin, LOW);
  delayMicroseconds(2);
  digitalWrite(outputPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(outputPin, LOW);
  olddistance = pulseIn(inputPin, HIGH);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(buzzer,OUTPUT);
  //delay(100);// put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
 digitalWrite(outputPin, LOW);
  delayMicroseconds(2);
  digitalWrite(outputPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(outputPin, LOW);
  int distance = pulseIn(inputPin, HIGH);
  distance = distance / 58;
  int diff = abs(distance - olddistance);



  current_millis = millis();
  if (millis() - prev_millis >= 2000) {
    prev_millis = millis();
    myspeed = 100 + steps * 30;
    if (myspeed > 200) myspeed = 255;
    if (myspeed < 100) myspeed = 100;

    steps = 0;
  }
  if (diff > 70) {
    //Serial.println(diff);
    olddistance = distance;
    steps++;
  }
  if (steps > 1){
    digitalWrite(buzzer,HIGH);
    delay(50);
    digitalWrite(buzzer,LOW);
    delay(50);
  }
  //delay(10);
  Serial.print("Speed=");
  Serial.print(myspeed);
  Serial.println(" ");
  Serial.println(steps);
  digitalWrite(IN3, HIGH);
  digitalWrite(7, LOW);
  analogWrite(IN4, myspeed);
  // Serial.print("Speed=");
  //Serial.print(myspeed);
  // Serial.println(" ");
  //digitalWrite(IN1, HIGH);
  //digitalWrite(4, LOW);
  //analogWrite(IN2, 240);
  //delay(100);
}
