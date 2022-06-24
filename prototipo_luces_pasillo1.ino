//Declaración de pines
int pingPin = 6;  // pin connected to Echo Pin in the ultrasonic distance sensor
int trigPin  = 4; // pin connected to trig Pin in the ultrasonic distance sensor
int led1 = 13;
int led2 = 12;
int led3 = 11;
int led4 = 10;
int led5 = 9;
//Variable para determinar el cambio de encendido/apagado
bool led1c = true;
bool led2c = true;
bool led3c = true;
bool led4c = true;
bool led5c = true;
//Variables para calcular los tiempos de encendido
unsigned long l1i = 0;
unsigned long l1f = 0;
unsigned long l2i = 0;
unsigned long l2f = 0;
unsigned long l3i = 0;
unsigned long l3f = 0;
unsigned long l4i = 0;
unsigned long l4f = 0;
unsigned long l5i = 0;
unsigned long l5f = 0;
//Variables del tiempo de encendido de un led
float t1 = 0;
float t2 = 0;
float t3 = 0;
float t4 = 0;
float t5 = 0;

//Declaración del serial y uso de pines
void setup() 
{
   Serial.begin(3600);
   pinMode(pingPin, INPUT); //Set the connection pin output mode Echo pin
   pinMode(trigPin, OUTPUT);//Set the connection pin output mode trog pin
   pinMode(led1, OUTPUT);
   pinMode(led2, OUTPUT);
   pinMode(led3, OUTPUT);
   pinMode(led4, OUTPUT);
   pinMode(led5, OUTPUT);
   delay(1000);             //delay 1000ms
} 

/*Función loop en la que se corre el Arduino donde se 
verificarán las distancias y determinará si un le debe estar
apagado o encendido*/
void loop() 
{ 
   int cm = ping(pingPin);
   //Serial.println(String(cm) + " cm.");
   //Distancia en la que prenderá cada led
   int Limite1 = 300; 
   int Limite2 = 240;   
   int Limite3 = 180;
   int Limite4 = 120;
   int Limite5 = 60;
  
  //LED1
  if ( cm > Limite2 && cm <= Limite1){
       //Se enciende el led y se imprime en el serial
       digitalWrite ( led1 , HIGH) ;
  	   if(led1c == true){
         led1c = false;
         l1i = millis();
         Serial.print("Led 1 encendido \n");
       }
  }
  else{
       //Se apaga el led y se imprime el tiempo encendido en el serial
       digitalWrite( led1 , LOW) ;
       if(led1c == false){
         led1c = true;
         l1f = millis();
         t1 = (l1f-l1i)/1000.0f;
         Serial.print("Led 1 apagado, estuvo encendido ");
         Serial.print(t1);
         Serial.print(" segundos \n");
       }
  }
  //LED2
  if ( cm > Limite3 && cm <= Limite2){
       //Se enciende el led y se imprime en el serial
       digitalWrite ( led2 , HIGH);
       if(led2c == true){
         led2c = false;
         l2i = millis();
         Serial.print("Led 2 encendido \n");
       }
  }
  else{
       //Se apaga el led y se imprime el tiempo encendido en el serial
       digitalWrite( led2 , LOW);
       if(led2c == false){
         led2c = true;
         l2f = millis();
         t2 = (l2f-l2i)/1000.0f;
         Serial.print("Led 2 apagado, estuvo encendido ");
         Serial.print(t2);
         Serial.print(" segundos \n");
       }
  }
  //LED3
  if ( cm > Limite4 && cm <= Limite3){
       //Se enciende el led y se imprime en el serial
       digitalWrite ( led3 , HIGH) ;
       if(led3c == true){
         led3c = false;
         l3i = millis();
         Serial.print("Led 3 encendido \n");
       }
  }
  else{
       //Se apaga el led y se imprime el tiempo encendido en el serial
       digitalWrite( led3 , LOW) ;
       if(led3c == false){
         led3c = true;
         l3f = millis();
         t3 = (l3f-l3i)/1000.0f;
         Serial.print("Led 3 apagado, estuvo encendido ");
         Serial.print(t3);
         Serial.print(" segundos \n");
       }
  }
  //LED4
  if ( cm > Limite5 && cm <= Limite4){
       //Se enciende el led y se imprime en el serial
       digitalWrite ( led4 , HIGH) ;
       if(led4c == true){
         led4c = false;
         l4i = millis();
         Serial.print("Led 4 encendido \n");
       }
  }
  else{
       //Se apaga el led y se imprime el tiempo encendido en el serial
       digitalWrite( led4 , LOW) ;
       if(led4c == false){
         led4c = true;
         l4f = millis();
         t4 = (l4f-l4i)/1000.0f;
         Serial.print("Led 4 apagado, estuvo encendido ");
         Serial.print(t4);
         Serial.print(" segundos \n");
       }
  }
  //LED5
  if ( cm <= Limite5){
       //Se enciende el led y se imprime en el serial
       digitalWrite ( led5 , HIGH) ;
       if(led5c == true){
         led5c = false;
         l5i = millis();
         Serial.print("Led 5 encendido \n");
       }
  }
  else {
       //Se apaga el led y se imprime el tiempo encendido en el serial
       digitalWrite( led5 , LOW) ;
       if(led5c == false){
         led5c = true;
         l5f = millis();
         t5 = (l5f-l5i)/1000.0f;
         Serial.print("Led 5 apagado, estuvo encendido ");
         Serial.print(t5);
         Serial.print(" segundos \n");
       }
   }
   delay(100);
}

//Función para calcular distancia del sensor ultrasónico
int ping(int pingPin) 
{ 
   // establish variables for duration of the ping, 
   // and the distance result in inches and centimeters: 
   long duration, cm; 
   // The PING))) is triggered by a HIGH pulse of 2 or more microseconds. 
   // Give a short LOW pulse beforehand to ensure a clean HIGH pulse: 
   pinMode(trigPin, OUTPUT); 
   digitalWrite(trigPin, LOW); 
   delayMicroseconds(2); 
   digitalWrite(trigPin, HIGH); 
   delayMicroseconds(5); 
   digitalWrite(trigPin, LOW); 

   pinMode(pingPin, INPUT); 
   duration = pulseIn(pingPin, HIGH); 

   // convert the time into a distance 
   cm = microsecondsToCentimeters(duration); 
   return cm ; 
} 

long microsecondsToCentimeters(long microseconds) 
{ 
   // The speed of sound is 340 m/s or 29 microseconds per centimeter. 
   // The ping travels out and back, so to find the distance of the 
   // object we take half of the distance travelled. 
   return microseconds / 29 / 2; 
} 