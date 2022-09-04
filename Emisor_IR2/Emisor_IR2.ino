/************ EMISOR INFRARROJO***********/
/*
 * Pin Para el Emisor Arduino UNO, NANO, Pro Mini = D3 o 3
 * Pin Para el Emisor Arduino MEGA = 9
 * 
 */
 
//Incluimos las Libreria 

#include <IRLib.h>
#include <IRLibMatch.h>
#include <IRLibTimer.h>


//Declaramos Variables
int Boton_ON_OFF = A4; // Declaramos el PIN del pulsador "Boton"
int Canal_UP = A3;     // Declaramos el PIN del pulsador "Boton"
int Canal_DOWN = A1;   // Declaramos el PIN del pulsador "Boton"
int Volumen_UP = 2;    // Declaramos el PIN del pulsador "Boton"
int Volumen_DOWN = A2; // Declaramos el PIN del pulsador "Boton"

int Valor1; //Declaramos una variable en la cual guardaremos los valores leidos del pulsador
int Valor2; //Declaramos una variable en la cual guardaremos los valores leidos del pulsador
int Valor3; //Declaramos una variable en la cual guardaremos los valores leidos del pulsador
int Valor4; //Declaramos una variable en la cual guardaremos los valores leidos del pulsador
int Valor5; //Declaramos una variable en la cual guardaremos los valores leidos del pulsador


IRsend emisor; //Activamos el emisor

void setup(){  
  
  Serial.begin(9600); //Iniciamos el monitor serial
  pinMode(Boton_ON_OFF,INPUT_PULLUP); //Declaramos como entrada y activamos una resistencia interna
  pinMode(Canal_UP,INPUT_PULLUP); //Declaramos como entrada y activamos una resistencia interna
  pinMode(Canal_DOWN,INPUT_PULLUP); //Declaramos como entrada y activamos una resistencia interna
  pinMode(Volumen_UP,INPUT_PULLUP); //Declaramos como entrada y activamos una resistencia interna
  pinMode(Volumen_DOWN,INPUT_PULLUP); //Declaramos como entrada y activamos una resistencia interna
  
}

void loop() {  //Bucle infinito
  
  Valor1 = digitalRead(Boton_ON_OFF); //Almacenamos los valores leidos del Pulsador
  Valor2 = digitalRead(Canal_UP); //Almacenamos los valores leidos del Pulsador
  Valor3 = digitalRead(Canal_DOWN); //Almacenamos los valores leidos del Pulsador
  Valor4 = digitalRead(Volumen_UP); //Almacenamos los valores leidos del Pulsador
  Valor5 = digitalRead(Volumen_DOWN); //Almacenamos los valores leidos del Pulsador

  if(Valor1 == LOW){         //Si el pulso es bajo "LOW" o "0" se
  emisor.send(NEC,0x807F02FD,32); //envia el codigo e
  Serial.println("ENCENDIDO");    //imprimimos en la termial
  delay(100);                  // declaramos un tiempo de espera de 0,1 Sg
  }
  
  if(Valor2 == LOW){         //Si el pulso es bajo "LOW" o "0" se
  emisor.send(NEC,0x2FDD827,32); //envia el codigo e
  Serial.println("Canal UP");    //imprimimos en la termial
  delay(100);                  // declaramos un tiempo de espera de 0,1 Sg
  }

  if(Valor3 == LOW){         //Si el pulso es bajo "LOW" o "0" se
  emisor.send(NEC,0x2FDF807,32); //envia el codigo e
  Serial.println("Canal DOWN");    //imprimimos en la termial
  delay(100);                  // declaramos un tiempo de espera de 0,1 Sg
  }
  
  if(Valor4 == LOW){         //Si el pulso es bajo "LOW" o "0" se
  emisor.send(NEC,0x2FD58A7,32); //envia el codigo e
  Serial.println("Volumen +");    //imprimimos en la termial
  delay(100);                  // declaramos un tiempo de espera de 0,1 Sg
  }
  
  if(Valor5 == LOW){         //Si el pulso es bajo "LOW" o "0" se
  emisor.send(NEC,0x2FD7887,32); //envia el codigo e
  Serial.println("Volumen -");    //imprimimos en la termial
  delay(100);                  // declaramos un tiempo de espera de 0,1 Sg
  }
}
