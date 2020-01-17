#include <SoftwareSerial.h>
enum Command {
  READ_A0,
  READ_A1,
  READ_A2,
  READ_A3
};

SoftwareSerial mySerial(10, 11);
String commandBuffer = "";
void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; 
  }
  mySerial.begin(9600);
}

void processCommand(Command command){
  switch (command){
    case READ_A0:
      mySerial.println(analogRead(A0));
      break;      
    case READ_A1:
      mySerial.println(analogRead(A1));
      break;    
    case READ_A2:
      mySerial.println(analogRead(A2));
      break;    
    case READ_A3:
      mySerial.println(analogRead(A3));
      break;    
  }
}
void listenMaster(){
  if(mySerial.available()){
    char inputChar = mySerial.read();
    if(inputChar != '\n'){
      commandBuffer += inputChar;
    }
    else{
      processCommand(commandBuffer.toInt());
      commandBuffer = "";
    }
  }
}
void loop() { // run over and over
  listenMaster();
}
