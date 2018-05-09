#define MAX 400

// Right and left motor controled by DRV8835.

#define PWM_L 10
#define PWM_R 9
#define DIR_L 8
#define DIR_R 7

boolean flipLeft = false;
boolean flipRight = false;

void setup() {
  // put your setup code here, to run once:

  pinMode(PWM_L,  OUTPUT);
  pinMode(PWM_R,  OUTPUT);
  pinMode(DIR_L, OUTPUT);
  pinMode(DIR_R, OUTPUT);

  setSpeeds(400, 400);
}

void loop() {
  // put your main code here, to run repeatedly:

}

void flipLeftMotor(boolean flip) {
  flipLeft = flip;
}

void flipRightMotor(boolean flip) {
  flipRight = flip;
}

void setLeftSpeed(int speed) {
  if (speed > MAX)
    speed = MAX;

  analogWrite(PWM_L, speed * 51 / 80);

  if(flipLeft == true)
    digitalWrite(DIR_L, HIGH);
  else
    digitalWrite(DIR_L, LOW);
}

void setRightSpeed(int speed) {
  if (speed > MAX)
    speed = MAX;

  analogWrite(PWM_R, speed * 51 / 80);

  if(flipRight == true)
    digitalWrite(DIR_R, HIGH);
  else
    digitalWrite(DIR_R, LOW);
}

void setSpeeds(int leftSpeed, int rightSpeed) {
  setLeftSpeed(leftSpeed);
  setRightSpeed(rightSpeed);
}
