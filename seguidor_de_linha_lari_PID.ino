#include <PID_v1.h>
double erro, correcao, setpoint = 0;
PID pid(&erro, &correcao, &setpoint, 30, 0, 20, DIRECT); //Kp, Ki, Kd
void setup() {
  Serial.begin(9600);


  //motor direito
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  //motor esquerdo
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);

  //sensor optico 1
  pinMode(A0, INPUT);

  //sensor optico 2
  pinMode(A2, INPUT);

  //sensor optico 3
  pinMode(A5, INPUT);

  pid.SetMode(AUTOMATIC);

}

void loop() {
  int basePWM = 150;

  int s1 = analogRead(A0); // Esquerdo
  int s2 = analogRead(A2); // Direito
  int s3 = analogRead(A5); // Centro

  int limiarPreto = 200;

  float posicao = 0;
  int total = 0;

  if(s1 > limiarPreto) {
    posicao -= 1;
    total++;
  }
  if(s2 > limiarPreto){
    posicao += 1;
    total++;
  }
  if(s3 > limiarPreto){
    total++;
  }

  if(total > 0){
    posicao = posicao / total;
  }

  erro = -posicao;

  pid.Compute();

  int pwmEsq = basePWM + correcao;
  int pwmDir = basePWM - correcao;

  pwmEsq = constrain(pwmEsq, 0, 255);
  pwmDir = constrain(pwmDir, 0, 255);

  analogWrite(10, pwmDir);
  digitalWrite(11, LOW);

  analogWrite(6, pwmEsq);
  digitalWrite(5, LOW);

  delay(10);
}
