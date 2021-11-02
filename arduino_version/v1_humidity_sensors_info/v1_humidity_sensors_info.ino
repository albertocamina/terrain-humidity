/* 
 *  V1 Sensor de Humedad para Tierra 
 *  
 *  Caso muy sencillo donde tenemos 3 sensores de humedad para plantas. 
 *  Las lecturas se hacen en Analógico, en los pines A0, A1 y A2
 *  
 *  Mostramos por Serial los datos de las plantas
 */


// Pines para los sensores
int H1_PIN = A0;
int H2_PIN = A1;
int H3_PIN = A2;

void setup() {
  // Iniciamos el Serial
  Serial.begin(9600);

}

void loop() {

  // Cogemos el valor de A0
  int humedad_H1    = analogRead(H1_PIN);
  int humedad_H2    = analogRead(H2_PIN);
  int humedad_H3    = analogRead(H3_PIN);
  
  float pct_humedad_H1 =  abs( ( humedad_H1 / 1024.00 ) - 1.00 ) * 100.00;
  float pct_humedad_H2 =  abs( ( humedad_H2 / 1024.00 ) - 1.00 ) * 100.00;
  float pct_humedad_H3 =  abs( ( humedad_H3 / 1024.00 ) - 1.00 ) * 100.00;
  
  Serial.println( "Humedad Actual para PIN 1: " );
  Serial.println( String( pct_humedad_H1, 2 ) + "%" );

  delay(2000);

  Serial.println( "Humedad Actual para PIN 2: " );
  Serial.println( String( pct_humedad_H2, 2 ) + "%" );

  delay(2000);

  Serial.println( "Humedad Actual para PIN 3: ");
  Serial.println( String( pct_humedad_H3, 2 ) + "%" );

  delay(2000);
  
  delay(1000);
  

}
