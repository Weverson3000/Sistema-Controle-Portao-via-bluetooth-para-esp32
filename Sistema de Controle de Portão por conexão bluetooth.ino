#include <TB6612FNG.h>
#include <BluetoothSerial.h>

// 27 - Standby pin
// 14 - AIN1 pin
// 12 - AIN2 pin
// 13 - PWMA pin
// To reverse forward motor direction, switch the AIN1 and AIN2 pin numbers.
Tb6612fng motor(14, 26, 27, 12);
// Tb6612fng motor(27, 12, 14, 13); // Reversed forward motor direction.

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  motor.begin();
  SerialBT.begin("ESP32-MotorController");

  pinMode(26, OUTPUT);
  pinMode(27, OUTPUT);
}



/*void loop() {
  if (1==1) {
    char command = SerialBT.read();
    switch (command) {
      case 'F':
        moveFrente();
        break;
      case 'B':
        moveTras();
        break;
      case 'S':
        parar();
        break;
      default:
        break;
    }
  }
}*/

void loop() {
  char command = SerialBT.read();
  if (command == 'f')
  {
    Serial.print("Up");
    moveFrente();
  }else if (command == 'b')
  {
    Serial.print("Down");
    moveTras();
  } else{
    parar();
  }

}

void moveFrente(){
  motor.drive(0.5, 50);
}

void moveTras(){
  motor.drive(-0.5, 50);
}

void parar(){
  motor.brake();
  delay(1000);
}
