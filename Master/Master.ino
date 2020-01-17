#include <SoftwareSerial.h>
enum Command {
  READ_A0,
  READ_A1,
  READ_A2,
  READ_A3
};

SoftwareSerial mySerial(10, 11); // RX, TX

int baudRate = 19200;

bool waitingForResponse = false;
String responseBuffer = "";

void setup() {
  Serial.begin(baudRate);
  while (!Serial) {
    ;
  }
  mySerial.begin(baudRate);
}

void getResponse(){
 if(mySerial.available()){
      char inputChar = mySerial.read();
      if(inputChar != '\n'){
        responseBuffer += inputChar;
      }
      else{
        Serial.print(responseBuffer.toInt());
        responseBuffer = "";
        waitingForResponse = false;
      }
  }
}

void sendCommand(Command command){
  mySerial.println(command);
  waitingForResponse = true;
  while(waitingForResponse){
    getResponse();
  }
}

void sendCommands(){
  Serial.print("A0:");
  sendCommand(READ_A0);
  Serial.print("\tA1:");
  sendCommand(READ_A1);
  Serial.print("\tA2:");
  sendCommand(READ_A2);
  Serial.print("\tA3:");
  sendCommand(READ_A3);
  Serial.println("");
}

void loop() {
  sendCommands();
  delay(10);
}
