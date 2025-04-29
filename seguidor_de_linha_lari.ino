void setup() {
  Serial.begin(9600);
  //motores
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);

  //sensor optico 1
  pinMode(8, INPUT);
  pinMode(A1, INPUT);

  //sensor optico 2
  pinMode(4, INPUT);
  pinMode(A2, INPUT);

}

void loop() {
  int opticAnalog1 = analogRead(A1);
  int opticAnalog2 = analogRead(A2);

  Serial.print(opticAnalog1);
  Serial.print(' ');
  Serial.println(opticAnalog2);

  if(opticAnalog1 >= 200){
      analogWrite(11, 500);
      digitalWrite(10, LOW);
      analogWrite(6, 500);
      digitalWrite(5, LOW); 
  } else if(opticAnalog2 >= 200){
      analogWrite(11, 500);
      digitalWrite(10, LOW);
      analogWrite(6, 500);
      digitalWrite(5, LOW); 
  } else{
      analogWrite(11, LOW);
      digitalWrite(10, LOW);
      analogWrite(6, LOW);
      digitalWrite(5, LOW); 
  };
  delay(10);
}
