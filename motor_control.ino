int m2_f = 7;
int m2_b = 6;
int m1_b = 5;
int m1_f = 4;
int sensorf_trigger = 9;
int sensorf_echo = 8;
long distance;
int stopCount;
int duration;
void setup() {
  pinMode(m2_f, OUTPUT);
  pinMode(m2_b, OUTPUT);
  pinMode(m1_b, OUTPUT);
  pinMode(m1_f, OUTPUT);
  pinMode(sensorf_trigger,OUTPUT);
  pinMode(sensorf_echo,INPUT);
  Serial.begin(9600); // Starts the serial communication
}
void loop() {
//forward();
//reverse();
//rightTurn();
//leftTurn();
start();
}
void start(){
  detectFSensor();
  if (distance <= 70){stopCount++;}
  if (stopCount >= 3){
    stop();
    }else{
      forward();
      }
  
  }
void stop(){
  digitalWrite(m1_f, LOW);
  digitalWrite(m1_b, LOW);
  digitalWrite(m2_b, LOW);
  digitalWrite(m2_f, LOW);
}
void forward(){
digitalWrite(m2_f, HIGH);
delay(100);
digitalWrite(m1_f, HIGH);
delay(100);
}
void reverse(){
digitalWrite(m2_b, HIGH);
delay(100);
digitalWrite(m1_b, HIGH);
delay(100);
}
void rightTurn(){
digitalWrite(m1_f, HIGH);
delay(100);
}
void leftTurn(){
digitalWrite(m2_f, HIGH);
delay(100);
}
void detectFSensor(){
  ////////////
//Getting Distance
///////////
// Clears the trigPin
digitalWrite(sensorf_trigger, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(sensorf_trigger, HIGH);
delayMicroseconds(10);
digitalWrite(sensorf_trigger, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(sensorf_echo, HIGH);
// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
if (distance <= 50){
  //stop();
  }
////////////
//Getting Distance
///////////
  }





//this will cause left motor to turn. m1_2 backwards, m1_1 forwards
//digitalWrite(m1_1, HIGH);
//digitalWrite(m1_2, HIGH);
//this will cause right motor to turn. m2_4 forward, m2_3 backwards
//digitalWrite(m2_3, HIGH);
//digitalWrite(m2_4, HIGH);
