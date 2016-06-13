#include <Arduino.h>


/* entrada valor del servo
1º caracter motor
2,3,4 angulo de movimiento
*/
// http://diymakers.es/usando-el-puerto-serie-del-arduino/

#define LED 13

#include <Servo.h> 10

Servo myservo1;  // create servo object to control a servo
Servo myservo2;
Servo myservo3;
Servo myservo4;
Servo myservo5;
Servo myservo6;
                // a maximum of eight servo objects can be created
int mssg = 0; //variable para guardar el mensaje

char cadena[5]; //Creamos un array que almacenará los caracteres que escribiremos en la consola del PC. Le asignamos  un tope de caracteres, en este caso 30
char cadena2[5];
char char_angulo;  //angulo del servo
byte posicion=0;  //Variable para cambiar la posición de los caracteres del array
int valor_angulo;  //Variable del valor entero
 int i;
 int valor;
 int sw;

//Pulso servo
const int pulsoMin = 300;
const int pulsoMax = 3900;
//Pulso servo grande futuba
const int pulsoMin2 = 550;
const int pulsoMax2 = 3000;
// pulso MG996R digital
const int pulsoMin3 = 800;
const int pulsoMax3 = 2500;

int pinQ = A0;
int pinW = A1;
int pinE = A2;
int pinR = A0;
int pinT = A1;
int pinY = A2;

void setup()
{
  // myservo.attach(9);  // attaches the servo on pin 9 to the servo object
     myservo1.attach(9, pulsoMin, pulsoMax);  // Q attaches the servo on pin 9 to the servo object
     myservo2.attach(8, pulsoMin, pulsoMax);  // W attaches the servo on pin 9 to the servo object
     myservo3.attach(7, pulsoMin2, pulsoMax2);  // E attaches the servo on pin 9 to the servo object
     myservo4.attach(6, pulsoMin3, pulsoMax3);  // R attaches the servo on pin 9 to the servo object
     myservo5.attach(5, pulsoMin, pulsoMax);  // T attaches the servo on pin 9 to the servo object
     myservo6.attach(4, pulsoMin3, pulsoMax3);  // Y attaches the servo on pin 9 to the servo object


   pinMode(LED, OUTPUT); //establecemos 13 como salida
   Serial.begin(9600); //iniciando Serial
}

void loop()
{
   if(Serial.available()) //Nos dice si hay datos dentro del buffer
   {
      memset(cadena, 0,sizeof(cadena));//memset borra el contenido del array  "cadena" desde la posición 0 hasta el final sizeof
      memset(cadena2, 0,sizeof(cadena));//memset borra el contenido del array  "cadena" desde la posición 0 hasta el final sizeof

 //     mssg = Serial.read(); //leemos el serial
     while(Serial.available()>0) //Mientras haya datos en el buffer ejecuta la función
      {
        delay(50); //Poner un pequeño delay para mejorar la recepción de datos
        cadena[posicion]=Serial.read();//Lee un carácter del string "cadena" de la "posicion", luego lee el siguiente carácter con "posicion++"
        posicion++;
      }

         //Serial.println(mssg);
         //Serial.print(mssg);
         //Serial.write(mssg);
     //Serial.write(cadena[0]);
          // pasamos el resto de entrada a char_angulo para convertir a int
          //char_angulo = cadena[1];
      for (i = 1; i < sizeof(cadena) - 1; i++){
       // Serial.print(i, DEC);
       // Serial.print(" = ");
       // Serial.write(cadena[i]);
        //Serial.println();
        cadena2[i-1] = cadena[i];
      }



      //valor_angulo = cadena[1] + cadena[2] + cadena[3] ;
      valor_angulo = atoi(cadena2);
      //valor_angulo = cadena[2];

    //  myservo.write(valor_angulo);       // tell servo to go to position in variable 'pos'
    //delay(50);
      Serial.write( valor_angulo);
      //char_angulo[1] = cadena[2];
      //char_angulo[2] = cadena[3];
      //valor_angulo=atoi(char_angulo);//Convertimos la cadena de caracteres en enteros
      //Serial.write(valor_angulo +1);

 //myservo3.write(valor_angulo);
      if(cadena[0] == 'e')
      {
         digitalWrite(13, HIGH); //si entra una 'e' encendemos
         myservo3.write(valor_angulo);
         delay(50);
          // tell servo to go to position in variable 'pos'
        // delay(2000);
        // myservo3.write(0);
        // delay(2000);
        // myservo3.write(180);
      }
      else if(cadena[0] == 'a')
      {
         digitalWrite(13, LOW); //si entra una 'a' apagamos
      }else if(cadena[0] == 'q')
      {
         myservo1.write(valor_angulo);       // tell servo to go to position in variable 'pos'
         delay(50);
      }else if(cadena[0] == 'w')
      {
        myservo2.write(valor_angulo);       // tell servo to go to position in variable 'pos'
        delay(50);
      }else if(cadena[0] == 'r')
      {
        myservo4.write(valor_angulo);       // tell servo to go to position in variable 'pos'
        delay(50);
       }else if(cadena[0] == 't')
      {
        myservo5.write(valor_angulo);       // tell servo to go to position in variable 'pos'
        delay(50);
      }else if(cadena[0] == 'y')
      {
        myservo6.write(valor_angulo);       // tell servo to go to position in variable 'pos'
        delay(50);
      }

      posicion=0;//Ponemos la posicion a 0
      //Serial.println(valor_angulo);   // saltamos linea
   }

   // mandamos el valor del puerto analogico

   //Serial.println(analogRead(pinA));
   sw = 0;
   if(analogRead(pinQ) >= 1) { sw = analogRead(pinQ); }
   if(analogRead(pinW) >= 1) { sw = analogRead(pinW); }
   if(analogRead(pinE) >= 1) { sw = analogRead(pinE); }
   if(analogRead(pinR) >= 1) { sw = analogRead(pinR); }
   if(analogRead(pinT) >= 1) { sw = analogRead(pinT); }
   if(analogRead(pinY) >= 1) { sw = analogRead(pinY); }
   Serial.println(analogRead(sw));
   Serial.println("\n");
   delay(400);
}

