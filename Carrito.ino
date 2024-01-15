
//#define LEFT A0
//#define RIGHT A3

//Infrarrojo
#define ND A0
#define ID 4

#define NI A2
#define II 5


//Ultrasonico
#define echoPin 2
#define trigPin 3

//Motores
#define motordpin1 6
#define motordpin2 9
#define motoripin1 10
#define motoripin2 11

long duration;
int distance;

int irizq = digitalRead(NI);
int irder = digitalRead(ND);

int pos = 0;
long time;

void setup(){
pinMode(trigPin,OUTPUT);
pinMode(echoPin, INPUT);

pinMode(ND, INPUT);
pinMode(NI, INPUT);
pinMode(ID, OUTPUT);
pinMode(II, OUTPUT);

//pinMode(RIGHT, INPUT);
//pinMode(LEFT, INPUT);
Serial.begin(9600);
Serial.println("Ultrasonic Sensor HC-SR04 Test");
Serial.println("with Arduino UNO");
Serial.println("Lectura Infrarrojo");

}

void loop() {

digitalWrite(trigPin,LOW);
delayMicroseconds(5);

digitalWrite(trigPin,HIGH);
delayMicroseconds(1);
digitalWrite(trigPin,LOW);
duration = pulseIn(echoPin, HIGH);
distance = duration * 0.034 / 2;
Serial.print("Distance: ");
Serial.print(distance);
Serial.println(" cm");

Serial.print("Lateral: ");
Serial.print(irizq);
Serial.print(irder);


  if(distance > 25){analogWrite(motordpin1, 0);
                    analogWrite(motordpin2, 158);
                    analogWrite(motoripin1, 158);
                    analogWrite(motoripin2, 0);}
                    
  if(distance <= 25){digitalWrite(motordpin1, LOW);
                     digitalWrite(motordpin2, LOW);
                     digitalWrite(motoripin1, LOW);
                     digitalWrite(motoripin2, LOW);} 

  while(irizq == 1){analogWrite(motoripin1, 200);
                    analogWrite(motoripin2, 0);}

  while(irder == 1){analogWrite(motordpin1, 0);
                    analogWrite(motordpin2, 200);}                 
                                
}
  
                     
                 
                     
                
