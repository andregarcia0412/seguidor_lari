void setup() {
  Serial.begin(9600);
  //motores direitos
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  //motor esquerdos
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);

  //sensor optico 1
  pinMode(8, INPUT);
  pinMode(A0, INPUT);

  //sensor optico 2
  pinMode(3, INPUT);
  pinMode(A2, INPUT);

}

void loop() {
  int pwm = 230;
  int opticAnalog1 = analogRead(A0);
  int opticAnalog2 = analogRead(A2);

  Serial.print(opticAnalog1); //esquerda, 500
  Serial.print(' ');
  Serial.println(opticAnalog2); //direita, 200


//  for(int i = 1; i <= 1000; i++){
//         digitalWrite(11,HIGH);
//         digitalWrite(10,LOW);
//         digitalWrite(6,HIGH);
//         digitalWrite(5,LOW);
//         delay(200);
//         digitalWrite(11,LOW);
//         digitalWrite(10,HIGH);
//         digitalWrite(6,LOW);
//         digitalWrite(5,HIGH);
//         delay(200);
//       } //emote

  if(opticAnalog1 < 500 && opticAnalog2 < 200){ //se nao detectar o preto, vai reto
      digitalWrite(11, LOW);
      analogWrite(10, pwm);
      analogWrite(6, pwm);
      digitalWrite(5, LOW); 
  } 
  if(opticAnalog1 >= 500){ //volta para tras, girar a roda da esquerda para tras e da direita para frente
  //diminuir a rotação do motor da esquerda
      digitalWrite(11, HIGH);
      digitalWrite(10, LOW);
      digitalWrite(6, LOW);
      digitalWrite(5, HIGH);
      delay(100);
      digitalWrite(11, LOW);
      digitalWrite(10, HIGH);
      digitalWrite(6, LOW);
      digitalWrite(5, HIGH);
      delay(100);
  } 
  if(opticAnalog2 > 200){ //volta para tras, gira a roda da esquerda para frente e a da direita para tras
  // diminuir a rotação do motor da direita
      digitalWrite(11, HIGH);
      digitalWrite(10, LOW);
      digitalWrite(6, LOW);
      digitalWrite(5, HIGH);
      delay(100);
      digitalWrite(11, HIGH);
      digitalWrite(10, LOW);
      digitalWrite(6, HIGH);
      digitalWrite(5, LOW);
      delay(100);
   }
   
   if(opticAnalog1 >= 500 && opticAnalog2 >= 200){
      digitalWrite(11, LOW);
      analogWrite(10, pwm);
      analogWrite(6, pwm);
      digitalWrite(5, LOW); 
   }
   
  delay(1);
}
