#define SolTOR1 2    //gauche
#define SolTOR2 3    //droit
#define SolTOR3 4    //derrière
#define DistANALOG1 A2  //devant
#define DistANALOG2 A1  //droit
#define DistANALOG3 A0  //gauche
#define M1sens 9     //droite
#define M2sens 8     //gauche
#define M1PWM 11     //droite  
#define M2PWM 10     //gauche
#define IR 13

#define MAX_SPEED 150
const bool sens = 1;
const bool nsens = 0 ;

void setup() {
  // Serial.begin(9600);
  pinMode(DistANALOG1, INPUT);
  pinMode(DistANALOG2, INPUT);
  pinMode(DistANALOG3, INPUT);
  pinMode(SolTOR1, INPUT);
  pinMode(SolTOR2, INPUT);
  pinMode(SolTOR3, INPUT);
  pinMode(IR, INPUT);
  pinMode(M1sens, OUTPUT);
  pinMode(M2sens, OUTPUT);
  pinMode(M1PWM, OUTPUT);
  pinMode(M2PWM, OUTPUT);
  while (digitalRead(IR)) {
  }
  Avancer();
  // attachInterrupt(digitalPinToInterrupt(SolTOR1), frontLeft, HIGH);
  // attachInterrupt(digitalPinToInterrupt(SolTOR2), frontRight, HIGH);
}

void loop() {
  // Avancer();
  // if (analogRead(DistANALOG1)>=300) {
  //   Avancer();
  //   delay(100);
  // }
  // if (analogRead(DistANALOG2)>=300) {
  //   Droite();
  //   delay(100);
  // }
  // if (analogRead(DistANALOG3)>=300) {
  //   Gauche();
  //   delay(100);
  // }
  // if(!digitalRead(SolTOR3)) {
  //   Avancer();
  // }
  
  if(SolTOR1) {
    Serial.println("gauche");
    Droite();
    delay(500);
  }

  if(SolTOR2) {
    Serial.println("droite");
    Gauche();
    delay(500);
  }
  Avancer();
}

void frontLeft() {
  Serial.println("gauche");
  Droite();
  delay(500);
}

void frontRight() {
  Serial.println("droite");
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