/* 
   Gamepad module provides three different mode namely Digital, JoyStick and Accelerometer.
 
   Explore more on: https://thestempedia.com/docs/dabble/game-pad-module/
    Modified by GM.
*/
#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <DabbleESP32.h>

// INITIALIZING VARIABLES
int ENA = 25;     // MOTOR 1
int IN1 = 26;
int IN2 = 27;

int ENB = 5;      // MOTOR 2
int IN3 = 19;
int IN4 = 21;

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);      // make sure your Serial Monitor is also set at this baud rate.
Dabble.begin("ROBOCAR.G");       //set bluetooth name of your device

Serial.println("ROBOT CAR..\n\n");
pinMode(ENA, OUTPUT);  // MOTOR 1 AS OUTPUT
pinMode(IN1, OUTPUT);
pinMode(IN2, OUTPUT);

pinMode(ENB, OUTPUT);  // MOTOR 2 AS OUTPUT
pinMode(IN3, OUTPUT);
pinMode(IN4, OUTPUT);

Serial.println(" SWITCHING ON ");
Switch_ON();



}

void loop() {
  Dabble.processInput();             //this function is used to refresh data obtained from smartphone.Hence calling this function is mandatory in order to get data properly from your mobile.
  Serial.print("KeyPressed: ");
  if (GamePad.isUpPressed())
  {
    Serial.print("Up");
    Serial.println(" ROBOT CAR MOVING FORWARD...");
    Forward();
    delay(200);
    Brake();
  //done
    
  }

  if (GamePad.isDownPressed())
  {
    Serial.print("Down");
    Serial.println(" ROBOT CAR MOVING BACKWARD...");
    Backward();
    delay(200);
    Brake();
    
  }

  if (GamePad.isLeftPressed())
  {
    Serial.print("Left");
      Serial.println(" ROBOT CAR MOVING LEFT...");
      Left();
      delay(200);
      Brake();
  }

  if (GamePad.isRightPressed())
  {
    Serial.print("Right");
    Serial.println(" ROBOT CAR MOVING RIGHT...");
    Right();
    delay(200);
    Brake();
  }

  if (GamePad.isSquarePressed())
  {
    Serial.print("Square");
  }

  if (GamePad.isCirclePressed())
  {
    Serial.print("Circle");
  }

  if (GamePad.isCrossPressed())
  {
    Serial.print("Cross");
    
    Serial.print("ROBOT CAR TURNED OFF");
    Switch_OFF();
  }

  if (GamePad.isTrianglePressed())
  {
    Serial.print("Triangle");
  }

  if (GamePad.isStartPressed())
  {
    Serial.print("Start");
     Serial.print("ROBOT CAR TURNED ON");
    Switch_ON();
    
  }

  if (GamePad.isSelectPressed())
  {
    Serial.print("Select");
  }
  Serial.print('\t');

  int a = GamePad.getAngle();
  Serial.print("Angle: ");
  Serial.print(a);
  Serial.print('\t');
  int b = GamePad.getRadius();
  Serial.print("Radius: ");
  Serial.print(b);
  Serial.print('\t');
  float c = GamePad.getXaxisData();
  Serial.print("x_axis: ");
  Serial.print(c);
  Serial.print('\t');
  float d = GamePad.getYaxisData();
  Serial.print("y_axis: ");
  Serial.println(d);
  Serial.println();
}

// TURN ON MOTORS
void Switch_ON()
{
 digitalWrite(ENA, HIGH );
 digitalWrite(ENB, HIGH );
}

// TURN OFF MOTORS
void Switch_OFF()
{
 digitalWrite(ENA, LOW );
 digitalWrite(ENB, LOW );
} 

// Forward 
void Forward(){
  digitalWrite(IN1, HIGH); // TURNING MOTOR 1 FORWARD 
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH); // TURNING MOTOR 2 FORWARD 
  digitalWrite(IN4, LOW);
} 

// BACKWARD
void Backward(){
  digitalWrite(IN1, LOW); // TURNING MOTOR 1  BACK
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, LOW); // TURNING MOTOR 2  BACK 
  digitalWrite(IN4, HIGH);
} 

// RIGHT
void Right(){
  digitalWrite(IN1, HIGH ); // TURNING MOTOR 1  FORWARD
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW); // TURNING MOTOR 2  BACKWARD 
  digitalWrite(IN4, HIGH);
} 

// TURN ROBOT LEFT
void Left(){
  digitalWrite(IN1, LOW); // TURNING MOTOR 1  BACKWARD
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, HIGH); // TURNING MOTOR 2  FORWAR.D
  digitalWrite(IN4, LOW);
} 

// BRAKE 
void Brake(){
  digitalWrite(IN1, LOW); // TURNING MOTOR 1 off  
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW); // TURNING MOTOR 2 off 
  digitalWrite(IN4, LOW);
} 


 
