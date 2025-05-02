#include <avr/io.h>

#define SolTOR1 6           //gauche
#define SolTOR2 8          //droit
#define DistANALOG1 A0     //devant
#define DistANALOG2 A1    //droit
#define DistANALOG3 A3   //gauche
#define M1sens 11      //droite
#define M2sens 3      //gauche
#define M1PWM 5      //droite  
#define M2PWM 7     //gauche
#define IR 0

#define MAX_SPEED 160

#define start 0
#define finding 1
#define track 2
#define border 3

#define sens 1
#define nsens 0

char state = start;
bool tmp1,tmp2;

void setup_opti() {
  pinMode(DistANALOG1, INPUT);
  pinMode(DistANALOG2, INPUT);
  pinMode(DistANALOG3, OUTPUT);
  pinMode(SolTOR1, INPUT);
  pinMode(SolTOR2, INPUT);
  pinMode(IR, INPUT);
  pinMode(M1sens, OUTPUT);
  pinMode(M2sens, OUTPUT);
  pinMode(M1PWM, OUTPUT);
  pinMode(M2PWM, OUTPUT);
  analogWrite(M1PWM, 0);
  analogWrite(M2PWM, 0);
  // attachInterrupt(digitalPinToInterrupt(SolTOR1), statBorder, FALLING);
  // attachInterrupt(digitalPinToInterrupt(SolTOR2), statBorder, FALLING);

  TCCR1A |= (1 << COM1B1)|(1 << WGM10);
  TCCR1B |= (1 << WGM12)|(1 << CS11);
}

int main() {
  setup_opti();

  while(1){
    if(analogRead(DistANALOG2)>100){
      digitalWrite(DistANALOG3,1);
    }else{
      digitalWrite(DistANALOG3,0);
    }
    /*switch(state){
      case start :
        if(!digitalRead(IR)){
          state=finding;
          break;
        }
        analogWrite(M1PWM, 0);
        analogWrite(M2PWM, 0);
      case finding :
        if((analogRead(DistANALOG1)>300)||(analogRead(DistANALOG2)>300)||(analogRead(DistANALOG3)>300)){
          state=track;
          break;
        }
        Gauche();
      case track :
        if(analogRead(DistANALOG1)>300){
          Avancer();
          break;
        }else if(analogRead(DistANALOG2)>300){
          Droite();
          break;
        }else if(analogRead(DistANALOG3)>300){
          Gauche();
          break;
        }else{
          state=digitalRead(IR)?finding:start;
          break;
        }

      case border :
        if(!digitalRead(SolTOR1)){
          frontLeft();
          break;
        }else if(!digitalRead(SolTOR2)){
          frontRight();
        break;
        }else{
          state=digitalRead(IR)?finding:start;
        break;
        }
    }
    */
  }
  return 0;
}

void statBorder(){
  state=border;
}

void frontLeft() {
  Droite();
  delay(500);
}

void frontRight() {
  Gauche();
  delay(500);
}

void Gauche() {
  digitalWrite(M1sens, nsens);
  digitalWrite(M2sens, sens);
  analogWrite(M1PWM, MAX_SPEED);
  analogWrite(M2PWM, MAX_SPEED);
}
void Droite() {
  digitalWrite(M1sens, sens);
  digitalWrite(M2sens, nsens);
  analogWrite(M1PWM, MAX_SPEED);
  analogWrite(M2PWM, MAX_SPEED);
}
void Avancer() {
  digitalWrite(M1sens, sens);
  digitalWrite(M2sens, sens);
  analogWrite(M1PWM, MAX_SPEED);
  analogWrite(M2PWM, MAX_SPEED);
}
void Reculer() {
  digitalWrite(M1sens, nsens);
  digitalWrite(M2sens, nsens);
  analogWrite(M1PWM, MAX_SPEED);
  analogWrite(M2PWM, MAX_SPEED);
}

