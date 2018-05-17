//------------------------------------ 
//SEMAFORO CON ARDUINO 
//------------------------------------
//---------Declara puertos de entradas y salidas  
int pulsador=2; //Pin donde se encuentra el pulsador, entrada 
int ledRojoPeaton=8; //Pin donde se encuentra el LED ROJO_PEATON, salida
int ledVerdePeaton=9; //Pin donde se encuentra el LED VERDE_PEATON, salida
int ledRojoAuto=10; //Pin donde se encuentra el LED ROJO_AUTO, salida
int ledAmbarAuto=11; //Pin donde se encuentra el LED AMBAR_AUTO, salida
int ledVerdeAuto=12; //Pin donde se encuentra el LED VERDE_AUTO, salida  
//---------Funcion principal 
void setup(){  // Se ejecuta cada vez que el Arduino se inicia  
Serial.begin(9600);//Inicia serial con el potenciometro
pinMode(pulsador, INPUT); //Configurar el pulsador como una entrada 
pinMode(ledRojoPeaton,OUTPUT); //Configurar el LED como una salida 
pinMode(ledVerdePeaton,OUTPUT); //Configurar el LED como una salida 
pinMode(ledRojoAuto,OUTPUT); //Configurar el LED como una salida 
pinMode(ledAmbarAuto,OUTPUT); //Configurar el LED como una salida 
pinMode(ledVerdeAuto,OUTPUT); //Configurar el LED como una salida 
} 
//----------Funcion ciclicla 
void loop(){  // Esta funcion se mantiene ejecutando  
int Tiempo= analogRead(A0)*5; //Tiempo que se multiplica por 5 para que se prolongue mas
if (digitalRead(pulsador)==HIGH){  //Condicional para saber estado del pulsador 
//Pulsador NO oprimido 
digitalWrite(ledRojoPeaton,HIGH); //Enciende el LED 
digitalWrite(ledVerdePeaton,LOW); //Apaga el LED 
digitalWrite(ledRojoAuto,LOW); //Apaga el LED 
digitalWrite(ledAmbarAuto,LOW); //Apaga el LED 
digitalWrite(ledVerdeAuto,HIGH); //Enciende el LED 
} 
else 
{ 
//Pulsador oprimido 
digitalWrite(ledVerdeAuto,LOW); //Apaga el LED 
digitalWrite(ledAmbarAuto,HIGH); //Enciende el LED 
delay(5000);
digitalWrite(ledAmbarAuto,LOW);//Apaga el LED
digitalWrite(ledRojoPeaton,LOW); //Apaga el LED
digitalWrite(ledRojoAuto,HIGH); //Enciende el LED  
digitalWrite(ledVerdePeaton,HIGH); //Enciende el LED 
delay(5000);
delay(Tiempo);
Serial.println(Tiempo);
} 
} 
//Fin programa 
