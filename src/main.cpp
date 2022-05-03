#include <Arduino.h>
#include <OneButton.h>

OneButton button(16);

bool status = false;
bool stellung = false;

void letAn(){
  digitalWrite(19, HIGH);
  Serial.println("Kurzer Tapser");
}

void letAus(){
  status = true;
}

// Taster G16

void ampel(){
  for (size_t i = 0; i < 20; i++)
  {
    if (status == false)
    {
      if (stellung == false)
    {
      digitalWrite(19, LOW);
      digitalWrite(17, HIGH);
      stellung = true;
      Serial.println("Rot");
    }else{
      digitalWrite(19, HIGH);
      digitalWrite(17, LOW);
      stellung = false;
      Serial.println("Gruen");
    }
    delay(1000);
    }else{
      digitalWrite(19, HIGH);
      digitalWrite(17, HIGH);
      Serial.println("Beide");
    }
    
    
  }
  
}

void changeBetweenLED(){

      if (stellung == false)
    {
      digitalWrite(19, LOW);
      digitalWrite(17, HIGH);
      stellung = true;
      Serial.println("Rot");
    }else{
      digitalWrite(19, HIGH);
      digitalWrite(17, LOW);
      stellung = false;
      Serial.println("Gruen");
    }
}

void setup() {
  Serial.begin(9600);
  pinMode(19, OUTPUT);
  pinMode(17, OUTPUT);

  pinMode(16, INPUT_PULLUP);

  digitalWrite(19, LOW);
  digitalWrite(17, LOW);

  button.attachClick(changeBetweenLED);
  button.attachDoubleClick(letAus);
}

void loop() {
  button.tick();
  // put your main code here, to run repeatedly:
}