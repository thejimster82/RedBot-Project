/* 
 *  This is part of the larger redbot project. 
 *  This part heads towards a dark part of the room, like a cockroach.
 */
#include <RedBot.h>
#define temt6000Pin2 A3 //Ambient light sensor reading
#define temt6000Pin A7 //Ambient light sensor reading

RedBotSensor left = RedBotSensor(A3);   // initialize a left sensor object on A3
RedBotSensor right = RedBotSensor(A7);  // initialize a right sensor object on A7
#define SPEED 60          // Sets nominal speed of motors.

RedBotMotors motors;
int leftSpeed;   // variable used to store the leftMotor speed
int rightSpeed;  // variable used to store the rightMotor speed
int diffVal = 0;


void setup() {
  pinMode(temt6000Pin2,  INPUT);  
  #define temt6000Pin A7 //Ambient light sensor reading

  Serial.begin(9600);
  Serial.println("Welcome to Cockroach - Finding a dark place");
  Serial.println("------------------------------------------");
  delay(2000);
  Serial.println("Ambient Light Sensor Readings: ");
  delay(500);
}

void loop() {
  // Show light sensor readings.
  Serial.print(left.read());
  Serial.print("\t");  // tab character
  Serial.print(right.read());
  Serial.println();
  diffVal = left.read() - right.read();
  motors.leftMotor(leftSpeed);
  motors.rightMotor(rightSpeed);
  // if heading towards dark part drive at the same speed (left is CCW / right is CW)
  
  if(diffVal > -10 && diffVal < 10)
  {
    leftSpeed = -SPEED; 
    rightSpeed = SPEED;
  }
  
  // if darker on right, adjust relative speeds to turn to the right
  else if(diffVal > 10)
  {
    leftSpeed = -(SPEED + 50);
    rightSpeed = SPEED - 50;
  }
  
  // if darker on left, adjust relative speeds to turn to the left
  else if(diffVal < -10)
  {
    leftSpeed = -(SPEED - 50);
    rightSpeed = SPEED + 50;
  }
  
}

