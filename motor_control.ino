// Motor Pins
const int rightMotor1 = 9;
const int rightMotor2 = 10;
const int rightSpeedPin = 3;

const int leftMotor1 = 5;
const int leftMotor2 = 6;
const int leftSpeedPin = 11;

// Speed values
int baseSpeed = 150;

void setup() {
  pinMode(rightMotor1, OUTPUT);
  pinMode(rightMotor2, OUTPUT);
  pinMode(rightSpeedPin, OUTPUT);

  pinMode(leftMotor1, OUTPUT);
  pinMode(leftMotor2, OUTPUT);
  pinMode(leftSpeedPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    char cmd = Serial.read();
    switch (cmd) {
      case 'F': moveForward(); break;
      case 'B': moveBackward(); break;
      case 'S': stopMotors(); break;
      case 'L': turnLeft(); break;
      case 'R': turnRight(); break;
    }
  }
}

void moveForward() {
  digitalWrite(rightMotor1, HIGH);
  digitalWrite(rightMotor2, LOW);
  analogWrite(rightSpeedPin, baseSpeed);

  digitalWrite(leftMotor1, HIGH);
  digitalWrite(leftMotor2, LOW);
  analogWrite(leftSpeedPin, baseSpeed);
}

void moveBackward() {
  digitalWrite(rightMotor1, LOW);
  digitalWrite(rightMotor2, HIGH);
  analogWrite(rightSpeedPin, baseSpeed);

  digitalWrite(leftMotor1, LOW);
  digitalWrite(leftMotor2, HIGH);
  analogWrite(leftSpeedPin, baseSpeed);
}

void stopMotors() {
  digitalWrite(rightMotor1, LOW);
  digitalWrite(rightMotor2, LOW);
  digitalWrite(leftMotor1, LOW);
  digitalWrite(leftMotor2, LOW);
  analogWrite(rightSpeedPin, 0);
  analogWrite(leftSpeedPin, 0);
}

void turnLeft() {
  digitalWrite(rightMotor1, HIGH);
  digitalWrite(rightMotor2, LOW);
  analogWrite(rightSpeedPin, baseSpeed);

  digitalWrite(leftMotor1, LOW);
  digitalWrite(leftMotor2, LOW);
  analogWrite(leftSpeedPin, 0);
}

void turnRight() {
  digitalWrite(rightMotor1, LOW);
  digitalWrite(rightMotor2, LOW);
  analogWrite(rightSpeedPin, 0);

  digitalWrite(leftMotor1, HIGH);
  digitalWrite(leftMotor2, LOW);
  analogWrite(leftSpeedPin, baseSpeed);
}
