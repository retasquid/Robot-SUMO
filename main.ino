#define SolTOR1 2    //gauche
#define SolTOR2 4    //droit
#define SolTOR3 3    //derrière
#define DistTOR1 A2  //devant
#define DistTOR2 A1  //droit
#define DistTOR3 A0  //gauche
#define M1sens 8     //droite
#define M2sens 9     //gauche
#define M1PWM 10     //droite  
#define M2PWM 11     //gauche
#define IR 13

#define MAX_SPEED 155

bool latch = 1;

void setup() {
  Serial.begin(9600);
  pinMode(DistTOR1, INPUT);
  pinMode(DistTOR2, INPUT);
  pinMode(DistTOR3, INPUT);
  pinMode(SolTOR1, INPUT_PULLUP);
  pinMode(SolTOR2, INPUT_PULLUP);
  pinMode(SolTOR3, INPUT_PULLUP);
  pinMode(IR, INPUT);
  pinMode(M1sens, OUTPUT);
  pinMode(M2sens, OUTPUT);
  pinMode(M1PWM, OUTPUT);
  pinMode(M2PWM, OUTPUT);
  Serial.println("Démarage");
  attachInterrupt(digitalPinToInterrupt(SolTOR1), frontLeft, LOW);
  attachInterrupt(digitalPinToInterrupt(SolTOR2), frontRight, LOW);
}

void frontLeft() {
  Serial.println("Capteur haut gauche ----------------------------------------");
  digitalWrite(M1sens, 0);
  digitalWrite(M2sens, 0);
  analogWrite(M1PWM, 0);
  analogWrite(M2PWM, MAX_SPEED);
  delay(5000);
}

void frontRight() {
  Serial.println("Capteur haut droit");
  digitalWrite(M1sens, 0);
  digitalWrite(M2sens, 0);
  analogWrite(M1PWM, MAX_SPEED);
  analogWrite(M2PWM, 0);
  delay(5000);
}

void loop() {
  while (latch) {
    if (digitalRead(IR)) {
      Avancer();
      Serial.println("DEBUT");
      latch = 0;
    }
  }
  if (AnalogRead(DistTOR1)>=100) {
    Serial.println("TOR1");
    Avancer();
  }
  if (AnalogRead(DistTOR2)>=100) {
    Serial.println("TOR2");
    Gauche();
  }
  if (AnalogRead(DistTOR3)>=100) {
    Serial.println("TOR3");
    Droite();
  }
  if (digitalRead(SolTOR3)) {
    Serial.println("Capteur bas");
    Reculer();
  }
  delay(100);
}

void Gauche() {
  digitalWrite(M1sens, 1);
  digitalWrite(M2sens, 0);
  analogWrite(M1PWM, MAX_SPEED);
  analogWrite(M2PWM, MAX_SPEED);
}
void Droite() {
  digitalWrite(M1sens, 1);
  digitalWrite(M2sens, 0);
  analogWrite(M1PWM, MAX_SPEED);
  analogWrite(M2PWM, MAX_SPEED);
}
void Avancer() {
  digitalWrite(M1sens, 1);
  digitalWrite(M2sens, 1);
  analogWrite(M1PWM, MAX_SPEED);
  analogWrite(M2PWM, MAX_SPEED);
}
void Reculer() {
  digitalWrite(M1sens, 0);
  digitalWrite(M2sens, 0);
  analogWrite(M1PWM, MAX_SPEED);
  analogWrite(M2PWM, MAX_SPEED);
}