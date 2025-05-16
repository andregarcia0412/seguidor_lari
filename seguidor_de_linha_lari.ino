void setup() {
  Serial.begin(9600);
  //motor direito
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  //motor esquerdo
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);

  //sensor optico 1
  pinMode(8, INPUT);
  pinMode(A0, INPUT);

  //sensor optico 2
  pinMode(3, INPUT);
  pinMode(A2, INPUT);

  //sensor optico 3
  pinMode(9, INPUT);
  pinMode(A5, INPUT);

}

void loop() {
  int pwm = 160;
  int opticAnalog1 = analogRead(A0);
  int opticAnalog2 = analogRead(A2);
  int opticAnalog3 = analogRead(A5);

  Serial.print(opticAnalog1); //esquerda, 500
  Serial.print(' ');
  Serial.print(opticAnalog2); //direita, 200
  Serial.print(' ');
  Serial.println(opticAnalog3); //centro


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

if (opticAnalog3 >= 200){
  if(opticAnalog1 >= 500 && opticAnalog2 >= 200){
      digitalWrite(11, LOW);
      analogWrite(10, pwm);
      analogWrite(6, pwm);
      digitalWrite(5, LOW); 
  }
  else if(opticAnalog1 >= 500 && opticAnalog2 < 200){
    digitalWrite(11, LOW);
    digitalWrite(10, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(5, HIGH);
  }
  else if(opticAnalog1 < 500 && opticAnalog2 >= 200){
    digitalWrite(11, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(5, LOW);
  }
} else{
  if(opticAnalog1 >= 500 && opticAnalog2 < 200){
    digitalWrite(11, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
  }
  else if(opticAnalog1 < 500 && opticAnalog2 >= 200){
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, HIGH);
  }
  else if(opticAnalog1 < 500 && opticAnalog2 < 200){
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
  }
}
   
  delay(5);
}
