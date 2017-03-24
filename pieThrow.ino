//
#include <SoftwareSerial.h>
#include <SerialCommand.h>


SerialCommand comm; 

void setup() {
  
  //Setup Channel A
  Serial.begin(9600);
  pinMode(12, OUTPUT); //Initiates Motor Channel A pin
  pinMode(9, OUTPUT); //Initiates Brake Channel A pin
  comm.addCommand("MOVE",throwPie);
  comm.addDefaultHandler(unrecognized);
  
}

void freeze(){
    digitalWrite(9, HIGH);
}

void loop(){
  
  //forward @ full speed
  freeze();
  // Serial.print("\ntest\n");  
  //throwPie();
  if (Serial.available() > 0) {

    comm.readSerial();
    Serial.println("I received ");

  }

  
}

void throwPie(){
    Serial.print("PIE");
    digitalWrite(12, HIGH); //Establishes forward direction of Channel A
    digitalWrite(9, LOW);   //Disengage the Brake for Channel A
    analogWrite(3, 255);   //Spins the motor on Channel A at full speed
  
    delay(200);  
    digitalWrite(9, HIGH); 
  
    //delay(7000);
}

void unrecognized() {
    Serial.println("Command not recognized.");
}
