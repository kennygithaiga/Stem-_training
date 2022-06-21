int ENA = 14;     // MOTOR 1 connections
int IN1 = 12;
int IN2 = 13;

int ENB = 5;      // MOTOR 2 connections
int IN3 = 19;
int IN4= 21;

void setup() {
 // put your setup code here, to run once:
Serial.begin(115200);
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
  // put your main code here, to run repeatedly:
  Serial.println(" ROBOT CAR MOVING FORWARD...");
  Forward();
  delay(2000);
  Brake();
  //done

  Serial.println(" ROBOT CAR MOVING BACKWARD...");
  Backward();
  delay(2000);
  Brake();
  //done

  Serial.println(" ROBOT CAR MOVING LEFT...");
  Left();
  delay(2000);
  Brake();
  //done

  Serial.println(" ROBOT CAR MOVING RIGHT...");
  Right();
  delay(2000);
  Brake();
  //done

  Serial.println(" ROBOT CAR STOPPED...");
  Brake();
  delay(2000);
  //done

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
