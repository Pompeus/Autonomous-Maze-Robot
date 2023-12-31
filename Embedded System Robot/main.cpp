#include <Arduino.h>

int distance, time, fsensor, rsensor, lsensor, rfLDR, lfLDR, rbLDR, lbLDR;

// Trigger
const int STF = 10;
const int STL = 8;
const int STR = 6;
// Echo
const int SEF = 11;
const int SEL = 9;
const int SER = 7;
// LDR
const int RFLDR = A2;
const int LFLDR = A1;
const int RBLDR = A0;
const int LBLDR = A7;

// Sonar function
long sonarSensor(int trig, int echo) {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  time = pulseIn(echo, HIGH);
  distance = time * 0.034 / 2;

  return distance;
}

class DCMotor {  
  int spd = 255, pin1, pin2;
  
  public:    
    void Pinout(int in1, int in2){
      pin1 = in1;
      pin2 = in2;
      pinMode(pin1, OUTPUT);
      pinMode(pin2, OUTPUT);
      }   
    void Speed(int in1){
      spd = in1;
      }     
    void Backward(){
      analogWrite(pin1, spd);
      digitalWrite(pin2, LOW);
      }   
    void Forward(){
      digitalWrite(pin1, LOW);
      analogWrite(pin2, spd);
      }
    void Stop(){
      digitalWrite(pin1, LOW);
      digitalWrite(pin2, LOW);
      }
   };
   DCMotor Motor1, Motor2;

void setup()
{
  Motor1.Pinout(2,3);
  Motor2.Pinout(4,5); 

  // Set front sensor
  pinMode(STF, OUTPUT);
  pinMode(SEF, INPUT);
  // Set left sensor
  pinMode(STL, OUTPUT);
  pinMode(SEL, INPUT);
  // Set right sensor
  pinMode(STR, OUTPUT);
  pinMode(SER, INPUT);
  // Set LDR
  pinMode(RFLDR, INPUT);
  pinMode(LFLDR, INPUT);
  pinMode(RBLDR, INPUT);
  pinMode(LBLDR, INPUT);
}

void loop(){

  Motor1.Speed(160);
  Motor2.Speed(160);
  fsensor = sonarSensor(STF, SEF);
  lsensor = sonarSensor(STL, SEL);
  rsensor = sonarSensor(STR, SER);
  rfLDR = analogRead(RFLDR);
  lfLDR = analogRead(LFLDR);
  rbLDR = analogRead(RBLDR);
  lbLDR = analogRead(LBLDR);
  
  if(fsensor <= 4){
    if (rsensor < lsensor){
      Motor1.Forward();
      Motor2.Backward();
      Serial.println(lsensor);
      delay(500);
    }
    else{
      Motor1.Backward();
      Motor2.Forward();
      delay(500);
    }
  }
  else if (rsensor <= 4){
    Motor1.Forward();
    Motor2.Backward();
  }
  else if (lsensor <=4 ){
    Motor1.Backward();
    Motor2.Forward();
  }
  else if (rsensor < 4 && lsensor < 4){
    Motor1.Forward();
    Motor2.Forward();
  }
  else if (rfLDR >=900 && lfLDR >= 900){
    Motor1.Backward();
    Motor2.Backward();
  }
    else if ((rfLDR >= 900) || (rbLDR >= 900)){
    Motor1.Forward();
    Motor2.Backward();
  }
  else if ((lfLDR >= 900) || (lbLDR >= 900)){
    Motor1.Backward();
    Motor2.Forward();
  }
  else {
    Motor1.Forward();
    Motor2.Forward();
  }
}
