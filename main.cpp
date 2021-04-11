/*
Horta Auto Irrigavel  
*UPinC.Makers
*Auto: Rafhael Monteiro 
 */
/*Biblioteca Arduino*/
#include <Arduino.h>
/*definindo o pino A0 como Dados_sensor de solo*/
#define Dados_sensor_solo A0
/*Pino do Sensor*/
#define Dados_sensor_water_level A2
int ativa_sensor_da_agua = 6;
/*definindo pino para a Bonba de água*/
int Ativa_bomba = 7;
void setup() {
  /*Iniciando a serial*/
  Serial.begin(9600);
  /*definindo pino como saída*/
  pinMode(Ativa_bomba,OUTPUT);
  pinMode(ativa_sensor_da_agua,OUTPUT);
  /*Bomba da agua desligada*/
  digitalWrite(Ativa_bomba,LOW);
  digitalWrite(ativa_sensor_da_agua,LOW);
}
void loop() {
  /*Variavel auxiliar*/
  int Dados_sensor_agua;
  int Dados_Auxiliar_sensor_solo;
  /*Recebendo o valor do sensor  */
  Dados_Auxiliar_sensor_solo = analogRead(Dados_sensor_solo);
  /* Comparação de valores */
   if ( Dados_Auxiliar_sensor_solo < 700)
  {
    Serial.println("solo umido");
  }
  if (Dados_Auxiliar_sensor_solo > 700 && Dados_Auxiliar_sensor_solo < 1020)
  {
    Serial.println("Solo seco");
    /*Mostra o valor obtido no sensor*/
    Serial.println(Dados_Auxiliar_sensor_solo);

    /*ligar o sensor*/
    digitalWrite(ativa_sensor_da_agua,HIGH);
    delay(20);

    /*Coletando dados do sensor*/
    Dados_sensor_agua = analogRead(Dados_sensor_water_level);
    Serial.println(Dados_sensor_agua);
    if (Dados_sensor_agua > 160 )
    {
      digitalWrite(Ativa_bomba,HIGH);
      delay(8000);
      digitalWrite(Ativa_bomba,LOW);
      digitalWrite(ativa_sensor_da_agua,LOW);
    }

  }
  if(Dados_sensor_agua <= 160){
    /*mostrar dados via serial*/
    Serial.print("Nivel de Água: ");
    Serial.println("Sem água - ");
    Serial.println(Dados_sensor_agua);
    delay(10);
  }
  delay(1000);
} 