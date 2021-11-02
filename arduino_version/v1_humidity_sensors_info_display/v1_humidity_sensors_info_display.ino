/* 
 *  V1 Sensor de Humedad para Tierra 
 *  
 *  Caso muy sencillo donde tenemos 3 sensores de humedad para plantas. 
 *  Las lecturas se hacen en Analógico, en los pines A0, A1 y A2
 *  Ademas mostramos los datos en una pantalla LCD
 *  
 *  Mostramos por Serial los datos de las plantas
 */

#include <LiquidCrystal.h>

LiquidCrystal lcd (7, 8, 9, 10, 11, 12);


// Pines para los sensores
int H1_PIN = A0;
int H2_PIN = A1;
int H3_PIN = A2;

void setup() {
  // Iniciamos el Serial
  Serial.begin(9600);
  // Indicamos el numero de filas y columnas de 
  // la pantalla
  lcd.begin(16, 2);

  // Inicio de mensaje
  lcd.print("Comenzando toma");
  lcd.setCursor (0, 1);
  lcd.print("de humedad...");

  delay(4000);

}

void loop() {

  // Cogemos el valor de A0
  int humedad_H1    = analogRead(H1_PIN);
  int humedad_H2    = analogRead(H2_PIN);
  int humedad_H3    = analogRead(H3_PIN);
  
  float pct_humedad_H1 =  abs( ( humedad_H1 / 1024.00 ) - 1.00 ) * 100.00;
  float pct_humedad_H2 =  abs( ( humedad_H2 / 1024.00 ) - 1.00 ) * 100.00;
  float pct_humedad_H3 =  abs( ( humedad_H3 / 1024.00 ) - 1.00 ) * 100.00;
  
  // Ponemos en la pantalla LCD humedad
  lcd.clear();
  lcd.setCursor (0, 0);
  lcd.print("Sensor 1: " + String( pct_humedad_H1, 2 ) +"%");

  delay(4000);

  lcd.clear();
  lcd.setCursor (0, 0);
  lcd.print("Sensor 2: " + String( pct_humedad_H2, 2 ) +"%");


  delay(4000);

  lcd.clear();
  lcd.setCursor (0, 0);
  lcd.print("Sensor 3: " + String( pct_humedad_H3, 2 ) +"%");

  delay(4000);
  
  delay(2000);
  

}
