const int flame = 3;
const int buzzer = 4;
const int BLUE_LED = 6;
const int RED_LED =7;


void setup() {
  Serial.begin(9600);

  Serial.println("This is my fire alarm project");

  
  pinMode(buzzer,OUTPUT);
  pinMode(flame,INPUT);
  pinMode(BLUE_LED,OUTPUT);
  pinMode(RED_LED,OUTPUT);
  
}

void loop() {

  int fire = digitalRead (flame);

  if(fire == HIGH) {
    
   digitalWrite(buzzer,HIGH);
   digitalWrite(BLUE_LED,LOW);
   digitalWrite(RED_LED,HIGH),

   Serial.println("FIRE! FIRE! PLEASE EVACUATE");
   
   delay,2000;
    
  }

  else {
    
    digitalWrite(buzzer ,LOW);
    digitalWrite(BLUE_LED,HIGH);
    digitalWrite(RED_LED,LOW),
    
    Serial.println("THIS IS A FIRE_FREE PLACE");
 
  }
  delay,2000;


}
