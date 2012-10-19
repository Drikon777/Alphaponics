#define SENSEPIN_A 4
#define SENSEPIN_B 3
#define RELAY_PIN 2 //Switches the relay on or off
#define LED_PIN 0 //Can drive more LEDs from this 
#define LED_PING 1 //Green surface mount LED on PCB
#define THRESHOLD 200
#define DELAY 1500000 //Time to wait before starting the pump after the last fill == 25min 1000*60*25

void setup(){
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(LED_PING, OUTPUT);
  digitalWrite(LED_PING, HIGH);
  digitalWrite(RELAY_PIN, HIGH);
}

void loop() {
   
  pinMode(SENSEPIN_A, OUTPUT);
  pinMode(SENSEPIN_B, INPUT);
  digitalWrite(SENSEPIN_A, HIGH);
  delay(100);
  int PinB = analogRead(SENSEPIN_B);
  if(PinB > THRESHOLD){
     digitalWrite(RELAY_PIN, LOW);
     digitalWrite(LED_PING, LOW);
     digitalWrite(SENSEPIN_A, LOW);
  delay(DELAY);   
  }
  if(PinB < THRESHOLD){
     digitalWrite(RELAY_PIN, HIGH);
     digitalWrite(LED_PING, HIGH);
     digitalWrite(SENSEPIN_A, LOW);
     delay(100);
  }
  
  //This could be used to switch the 5V between the sensors rods if electrolysis becomes a problem although I have not seen evidance of it happening.
   /*
 
  pinMode(SENSEPIN_A, INPUT);
  pinMode(SENSEPIN_B, OUTPUT);
  digitalWrite(SENSEPIN_B, HIGH);
  delay(100);
  int PinA = analogRead(SENSEPIN_A); 
  if(PinA > THRESHOLD){
     digitalWrite(RELAY_PIN, LOW);
     digitalWrite(SENSEPIN_B, LOW);
  delay(DELAY);
  }
if(PinA < THRESHOLD){
     digitalWrite(RELAY_PIN, HIGH);
     digitalWrite(SENSEPIN_B, LOW);
  }*/
}
  
