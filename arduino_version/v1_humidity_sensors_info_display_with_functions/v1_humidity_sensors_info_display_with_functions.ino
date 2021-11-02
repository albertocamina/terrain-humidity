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

void represent_humidity( int sensor, int num_sensor ) {
/*
 * Funcion que toma la cantidad de humedad de un sensor y la pinta en un display
 * 
 * Args:
 *  - sensor      : pin del sensor que tenemos que leer
 *  - num_sensor  : numero del sensor para printearlo en el display
 */

  // Tomamos la humedad del sensor
  int humedad           = analogRead(sensor);
  // Sacamos el % de humedad total
  float pct_humedad     = abs( ( humedad / 1024.00 ) - 1.00 ) * 100.00;

  // Limpiamos la pantalla
  lcd.clear();
  lcd.setCursor (0, 0);
  lcd.print("Sensor " + String( num_sensor ) + ": " + String( pct_humedad, 2 ) +"%");

    
  
}

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


  // Llamada para el sensor 1
  represent_humidity( H1_PIN, 1 );

  delay(4000);

  // Llamada para el sensor 2
  represent_humidity( H2_PIN, 2 );

  delay(4000);

  // Llamada para el sensor 3
  represent_humidity( H3_PIN, 3 );
  delay(4000);
  
  delay(2000);
  

}
