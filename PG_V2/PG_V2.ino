//    LEMBRAR DE TROCAR O COMANDO DELAY POR MILLIS PARA EVITAR INTERRUPÇÃO NO CÓDIGO    //
 
//    BIBLIOTECAS   //
#include <SPI.h>
#include <Ethernet.h>
#include <SD.h>
#include <Wire.h>
#include <EmonLib.h>
#include <DS3231.h>

<<<<<<< HEAD
// size of buffer used to capture HTTP requests
#define REQ_BUF_SZ   50

=======
>>>>>>> 8c575131bce73c09f8a945a389e11b61ac8fd1e7
//    MEDIDOR 1   //
EnergyMonitor emon1;
float antigo_realPower1 = 0;
float realPower1;  
float apparentPower1;    
float powerFActor1;      
float supplyVoltage1;             
float Irms1;

//    MEDIDOR 2   //
float antigo_realPower2 = 0;
float realPower2;  
float apparentPower2;    
float powerFActor2;      
float supplyVoltage2;             
float Irms2;

//    MEDIDOR 3   //
float antigo_realPower3 = 0;
float realPower3;  
float apparentPower3;    
float powerFActor3;      
float supplyVoltage3;             
float Irms3;

//    MEDIDOR 4   //
float antigo_realPower4 = 0;
float realPower4;  
float apparentPower4;    
float powerFActor4;      
float supplyVoltage4;             
float Irms4;

//    MEDIDOR 5   //
float antigo_realPower5 = 0;
float realPower5;  
float apparentPower5;    
float powerFActor5;      
float supplyVoltage5;             
float Irms5;

//    MEDIDOR 6   //
float antigo_realPower6 = 0;
float realPower6;  
float apparentPower6;    
float powerFActor6;      
float supplyVoltage6;             
float Irms6;

//    MEDIDOR 7   //
float antigo_realPower7 = 0;
float realPower7;  
float apparentPower7;    
float powerFActor7;      
float supplyVoltage7;             
float Irms7;

//    MEDIDOR 8   //
float antigo_realPower8 = 0;
float realPower8;  
float apparentPower8;    
float powerFActor8;      
float supplyVoltage8;             
float Irms8;

//    MEDIDOR 9   //
float antigo_realPower9 = 0;
float realPower9;  
float apparentPower9;    
float powerFActor9;      
float supplyVoltage9;             
float Irms9;

//    MEDIDOR 10   //
float antigo_realPower10 = 0;
float realPower10;  
float apparentPower10;    
float powerFActor10;      
float supplyVoltage10;             
float Irms10;

//    TOTAIS    //
float realPowert;  
float apparentPowert;    
float powerFActort;      
float supplyVoltaget;             
float Irmst;

//    SENSORES   //
const int SensorCorrente_1 = A0;
const int SensorTensao_1 = A1;

//    SD    //
#define PIN_SD_CARD 4

//    RTC    //
DS3231 rtc;              
RTCDateTime dataehora;   

//    ENDEREÇO DISPOSITIVOS    //
int arduino_01 = 0x01;
int arduino_02 = 0x02;
int arduino_03 = 0x03;

//    TAMANHO MENSAGEM    //
int size_1;
int size_2;
int size_3;
int size_4;
int size_5;
int size_6;
int size_7;
int size_8;
int size_9;
int size_10;
int size_11;
int size_12;
int size_13;
int size_14;
int size_15;
int total_size_1;
int total_size_2;
int total_size_3;

//   MENSAGEM  //
char rP1[8];
char aP1[8];
char pF1[8];
char sV1[8];
char Ir1[8];
char mensagem;
String dados;
String data_completa;
String hora_completa;
String data_hora;
<<<<<<< HEAD
String aux_data_completa;
String aux_hora_completa;
String aux_data_hora;
=======
>>>>>>> 8c575131bce73c09f8a945a389e11b61ac8fd1e7
String dados_arduino_0X00_01;
String dados_arduino_0X01_01;
String dados_arduino_0X01_02;
String dados_arduino_0X01_03;
String dados_arduino_0X02_01;
String dados_arduino_0X02_02;
String dados_arduino_0X02_03;
String dados_arduino_0X03_01;
String dados_arduino_0X03_02;
String dados_arduino_0X03_03;

//   DATA HORA   //
byte data;

//    MENSURAR AS GRANDEZAS    //
void medir(){
  emon1.calcVI(20,2000);

   //    MEDIDOR 01    //
  realPower1       = emon1.realPower;        
  apparentPower1   = emon1.apparentPower;    
  powerFActor1     = emon1.powerFactor;      
  supplyVoltage1   = emon1.Vrms;             
  Irms1            = emon1.Irms;
}

//    CALCULOS PARA OS GRÁFICOS    //
void totais(){
  realPowert = (realPower1 + realPower2 + realPower3 + realPower4 + realPower5 + realPower6 + realPower7 + realPower8 + realPower9 + realPower10)/10;
  apparentPowert = (apparentPower1 + apparentPower2 + apparentPower3 + apparentPower4 + apparentPower5 + apparentPower6 + apparentPower7 + apparentPower8 + apparentPower9 + apparentPower10)/10;
  powerFActort = (powerFActor1 + powerFActor2 + powerFActor3 + powerFActor4 + powerFActor5 + powerFActor6 + powerFActor7 + powerFActor8 + powerFActor9 + powerFActor10)/10;
  supplyVoltaget = (supplyVoltage1 + supplyVoltage2 + supplyVoltage3 + supplyVoltage4 + supplyVoltage5 + supplyVoltage6 + supplyVoltage7 + supplyVoltage8 + supplyVoltage9 + supplyVoltage10)/10;
  Irmst = (Irms1 + Irms2 + Irms3 + Irms4 + Irms5 + Irms6 + Irms7 + Irms8 + Irms9 + Irms10);
}

//    PREPARA OS DADOS PARA O XML    //
void subString_para_float(int alterna){
  int ind1;
  int ind2;
  int ind3;
  int ind4;
  int ind5;
  
  switch (alterna){
    case 1:
    //  Serial.print("NOVO: ");
    //  Serial.println(realPower1);
      if(antigo_realPower1 == 0){
        antigo_realPower1 = realPower1;
      } else {
        realPower1 += antigo_realPower1;
        realPower1 /= 2;
    //    Serial.print("ANTIGO: ");
    //    Serial.println(antigo_realPower1);
        antigo_realPower1 = realPower1;
      }
    //  Serial.print("MEDIA: ");
    //  Serial.println(realPower1);

      ind1 = dados_arduino_0X01_01.indexOf(",");
      realPower2 = dados_arduino_0X01_01.substring(0, ind1).toFloat();
    //  Serial.print("NOVO: ");
    //  Serial.println(realPower2);
      if(antigo_realPower2 == 0){
        antigo_realPower2 = realPower2;
      } else {
        realPower2 += antigo_realPower2;
        realPower2 /= 2;
    //    Serial.print("ANTIGO: ");
    //    Serial.println(antigo_realPower2);
        antigo_realPower2 = realPower2;
      }
    //  Serial.print("MEDIA: ");
    //  Serial.println(realPower2);
      ind2 = dados_arduino_0X01_01.indexOf(",", ind1 + 1);
      apparentPower2 = dados_arduino_0X01_01.substring(ind1 + 1, ind2).toFloat();
      ind3 = dados_arduino_0X01_01.indexOf(",", ind2 + 1);
      powerFActor2 = dados_arduino_0X01_01.substring(ind2 + 1, ind3).toFloat();
      ind4 = dados_arduino_0X01_01.indexOf(",", ind3 + 1);
      supplyVoltage2 = dados_arduino_0X01_01.substring(ind3 + 1, ind4).toFloat();
      ind5 = dados_arduino_0X01_01.indexOf(",", ind4 + 1);
      Irms2 = dados_arduino_0X01_01.substring(ind4 + 1, ind5).toFloat();

      ind1 = dados_arduino_0X01_02.indexOf(",");
      realPower3 += dados_arduino_0X01_02.substring(0, ind1).toFloat();
      
      if(antigo_realPower3 == 0){
        antigo_realPower3 = realPower3;
      } else {
        realPower3 += antigo_realPower3;
        realPower3 /= 3;
        antigo_realPower3 = realPower3;
      }
      ind2 = dados_arduino_0X01_02.indexOf(",", ind1 + 1);
      apparentPower3 = dados_arduino_0X01_02.substring(ind1 + 1, ind2).toFloat();
      ind3 = dados_arduino_0X01_02.indexOf(",", ind2 + 1);
      powerFActor3 = dados_arduino_0X01_02.substring(ind2 + 1, ind3).toFloat();
      ind4 = dados_arduino_0X01_02.indexOf(",", ind3 + 1);
      supplyVoltage3 = dados_arduino_0X01_02.substring(ind3 + 1, ind4).toFloat();
      ind5 = dados_arduino_0X01_02.indexOf(",", ind4 + 1);
      Irms3 = dados_arduino_0X01_02.substring(ind4 + 1, ind5).toFloat();

      ind1 = dados_arduino_0X01_03.indexOf(",");
      realPower4 += dados_arduino_0X01_03.substring(0, ind1).toFloat();
      if(antigo_realPower4 == 0){
        antigo_realPower4 = realPower4;
      } else {
        realPower4 += antigo_realPower4;
        realPower4 /= 4;
        antigo_realPower4 = realPower4;
      }
      ind2 = dados_arduino_0X01_03.indexOf(",", ind1 + 1);
      apparentPower4 = dados_arduino_0X01_03.substring(ind1 + 1, ind2).toFloat();
      ind3 = dados_arduino_0X01_03.indexOf(",", ind2 + 1);
      powerFActor4 = dados_arduino_0X01_03.substring(ind2 + 1, ind3).toFloat();
      ind4 = dados_arduino_0X01_03.indexOf(",", ind3 + 1);
      supplyVoltage5 = dados_arduino_0X01_03.substring(ind3 + 1, ind4).toFloat();
      ind5 = dados_arduino_0X01_03.indexOf(",", ind4 + 1);
      Irms5 = dados_arduino_0X01_03.substring(ind4 + 1, ind5).toFloat();

      break;
    
    case 2:

      ind1 = dados_arduino_0X02_01.indexOf(",");
      realPower5 += dados_arduino_0X02_01.substring(0, ind1).toFloat();
      if(antigo_realPower5 == 0){
        antigo_realPower5 = realPower5;
      } else {
        realPower5 += antigo_realPower5;
        realPower5 /= 5;
        antigo_realPower5 = realPower5;
      }
      ind2 = dados_arduino_0X02_01.indexOf(",", ind1 + 1);
      apparentPower5 = dados_arduino_0X02_01.substring(ind1 + 1, ind2).toFloat();
      ind3 = dados_arduino_0X02_01.indexOf(",", ind2 + 1);
      powerFActor5 = dados_arduino_0X02_01.substring(ind2 + 1, ind3).toFloat();
      ind4 = dados_arduino_0X02_01.indexOf(",", ind3 + 1);
      supplyVoltage5 = dados_arduino_0X02_01.substring(ind3 + 1, ind4).toFloat();
      ind5 = dados_arduino_0X02_01.indexOf(",", ind4 + 1);
      Irms5 = dados_arduino_0X02_01.substring(ind4 + 1, ind5).toFloat();

      ind1 = dados_arduino_0X02_02.indexOf(",");
      realPower6 += dados_arduino_0X02_02.substring(0, ind1).toFloat();
      if(antigo_realPower6 == 0){
        antigo_realPower6 = realPower6;
      } else {
        realPower6 += antigo_realPower6;
        realPower6 /= 6;
        antigo_realPower6 = realPower6;
      }
      ind2 = dados_arduino_0X02_02.indexOf(",", ind1 + 1);
      apparentPower6 = dados_arduino_0X02_02.substring(ind1 + 1, ind2).toFloat();
      ind3 = dados_arduino_0X02_02.indexOf(",", ind2 + 1);
      powerFActor6 = dados_arduino_0X02_02.substring(ind2 + 1, ind3).toFloat();
      ind4 = dados_arduino_0X02_02.indexOf(",", ind3 + 1);
      supplyVoltage6 = dados_arduino_0X02_02.substring(ind3 + 1, ind4).toFloat();
      ind5 = dados_arduino_0X02_02.indexOf(",", ind4 + 1);
      Irms6 = dados_arduino_0X02_02.substring(ind4 + 1, ind5).toFloat();

      ind1 = dados_arduino_0X02_03.indexOf(",");
      realPower7 += dados_arduino_0X02_03.substring(0, ind1).toFloat();
      if(antigo_realPower7 == 0){
        antigo_realPower7 = realPower7;
      } else {
        realPower7 += antigo_realPower7;
        realPower7 /= 7;
        antigo_realPower7 = realPower7;
      }
      ind2 = dados_arduino_0X02_03.indexOf(",", ind1 + 1);
      apparentPower7 = dados_arduino_0X02_03.substring(ind1 + 1, ind2).toFloat();
      ind3 = dados_arduino_0X02_03.indexOf(",", ind2 + 1);
      powerFActor7 = dados_arduino_0X02_03.substring(ind2 + 1, ind3).toFloat();
      ind4 = dados_arduino_0X02_03.indexOf(",", ind3 + 1);
      supplyVoltage7 = dados_arduino_0X02_03.substring(ind3 + 1, ind4).toFloat();
      ind5 = dados_arduino_0X02_03.indexOf(",", ind4 + 1);
      Irms7 = dados_arduino_0X02_03.substring(ind4 + 1, ind5).toFloat();
    
      break;
    
    case 3:

      ind1 = dados_arduino_0X03_01.indexOf(",");
      realPower8 += dados_arduino_0X03_01.substring(0, ind1).toFloat();
      if(antigo_realPower8 == 0){
        antigo_realPower8 = realPower8;
      } else {
        realPower8 += antigo_realPower8;
        realPower8 /= 8;
        antigo_realPower8 = realPower8;
      }
      ind2 = dados_arduino_0X03_01.indexOf(",", ind1 + 1);
      apparentPower8 = dados_arduino_0X03_01.substring(ind1 + 1, ind2).toFloat();
      ind3 = dados_arduino_0X03_01.indexOf(",", ind2 + 1);
      powerFActor8 = dados_arduino_0X03_01.substring(ind2 + 1, ind3).toFloat();
      ind4 = dados_arduino_0X03_01.indexOf(",", ind3 + 1);
      supplyVoltage8 = dados_arduino_0X03_01.substring(ind3 + 1, ind4).toFloat();
      ind5 = dados_arduino_0X03_01.indexOf(",", ind4 + 1);
      Irms8 = dados_arduino_0X03_01.substring(ind4 + 1, ind5).toFloat();

      ind1 = dados_arduino_0X03_02.indexOf(",");
      realPower9 += dados_arduino_0X03_02.substring(0, ind1).toFloat();
      if(antigo_realPower9 == 0){
        antigo_realPower9 = realPower9;
      } else {
        realPower9 += antigo_realPower9;
        realPower9 /= 9;
        antigo_realPower9 = realPower9;
      }
      ind2 = dados_arduino_0X03_02.indexOf(",", ind1 + 1);
      apparentPower9 = dados_arduino_0X03_02.substring(ind1 + 1, ind2).toFloat();
      ind3 = dados_arduino_0X03_02.indexOf(",", ind2 + 1);
      powerFActor9 = dados_arduino_0X03_02.substring(ind2 + 1, ind3).toFloat();
      ind4 = dados_arduino_0X03_02.indexOf(",", ind3 + 1);
      supplyVoltage9 = dados_arduino_0X03_02.substring(ind3 + 1, ind4).toFloat();
      ind5 = dados_arduino_0X03_02.indexOf(",", ind4 + 1);
      Irms9 = dados_arduino_0X03_02.substring(ind4 + 1, ind5).toFloat();

      ind1 = dados_arduino_0X03_03.indexOf(",");
      realPower10 += dados_arduino_0X03_03.substring(0, ind1).toFloat();
      if(antigo_realPower10 == 0){
        antigo_realPower10 = realPower10;
      } else {
        realPower10 += antigo_realPower10;
        realPower10 /= 10;
        antigo_realPower10 = realPower10;
      }
      ind2 = dados_arduino_0X03_03.indexOf(",", ind1 + 1);
      apparentPower10 = dados_arduino_0X03_03.substring(ind1 + 1, ind2).toFloat();
      ind3 = dados_arduino_0X03_03.indexOf(",", ind2 + 1);
      powerFActor10 = dados_arduino_0X03_03.substring(ind2 + 1, ind3).toFloat();
      ind4 = dados_arduino_0X03_03.indexOf(",", ind3 + 1);
      supplyVoltage10 = dados_arduino_0X03_03.substring(ind3 + 1, ind4).toFloat();
      ind5 = dados_arduino_0X03_03.indexOf(",", ind4 + 1);
      Irms10 = dados_arduino_0X03_03.substring(ind4 + 1, ind5).toFloat();

      break;
  }
}

//    RECEBE AS MENSAGENS    //
void recebe_dados(){
  
  recebe_tamanho(arduino_01);
  dados_arduino_0X01_01 = recebe_escravo_1(arduino_01);
  dados = "";
  dados_arduino_0X01_02 = recebe_escravo_2(arduino_01);
  dados = "";
  dados_arduino_0X01_03 = recebe_escravo_3(arduino_01);
  dados = "";

  recebe_tamanho(arduino_02);
  dados_arduino_0X02_01 = recebe_escravo_1(arduino_02);
  dados = "";
  dados_arduino_0X02_02 = recebe_escravo_2(arduino_02);
  dados = "";
  dados_arduino_0X02_03 = recebe_escravo_3(arduino_02);
  dados = "";

  recebe_tamanho(arduino_03);
  dados_arduino_0X03_01 = recebe_escravo_1(arduino_03);
  dados = "";
  dados_arduino_0X03_02 = recebe_escravo_2(arduino_03);
  dados = "";
  dados_arduino_0X03_03 = recebe_escravo_3(arduino_03);
  dados = "";
  
}

//    ENVIAR OS DADOS    //
void envia_dados(){  
  banco_de_dados(data_completa);
  banco_de_dados(dados_arduino_0X00_01);
  banco_de_dados(dados_arduino_0X01_01);
  banco_de_dados(dados_arduino_0X01_02);
  banco_de_dados(dados_arduino_0X01_03);
  banco_de_dados(dados_arduino_0X02_01);
  banco_de_dados(dados_arduino_0X02_02);
  banco_de_dados(dados_arduino_0X02_03);
  banco_de_dados(dados_arduino_0X03_01);
  banco_de_dados(dados_arduino_0X03_02);
  banco_de_dados(dados_arduino_0X03_03);
}

//    LIMPAR MENSAGENS    //
void limpar_string(){
  data_hora = "";
  hora_completa = "";    
  data_completa = "";
  dados_arduino_0X00_01 = "";
  dados_arduino_0X01_01 = "";
  dados_arduino_0X01_02 = "";
  dados_arduino_0X01_03 = "";
  dados_arduino_0X02_01 = "";
  dados_arduino_0X02_02 = "";
  dados_arduino_0X02_03 = "";
  dados_arduino_0X03_01 = "";
  dados_arduino_0X03_02 = "";
  dados_arduino_0X03_03 = "";
}

//    RTC    //
void relogio(){
    dataehora = rtc.getDateTime();
    
    data_hora = dataehora.hour;
<<<<<<< HEAD
    aux_data_hora = data_hora;

    hora_completa += dataehora.hour;
    hora_completa += ":";
    hora_completa += dataehora.minute;
    hora_completa += ":";
    hora_completa += dataehora.second;
    aux_hora_completa = hora_completa;
    
=======

    hora_completa += dataehora.hour;
    hora_completa += ",";
    hora_completa += dataehora.minute;
    hora_completa += ",";
    hora_completa += dataehora.second;

>>>>>>> 8c575131bce73c09f8a945a389e11b61ac8fd1e7
    data_completa += dataehora.year;
    data_completa += "/";
    data_completa += dataehora.month;
    data_completa += "/";
    data_completa += dataehora.day;
    data_completa += " ";
    data_completa += dataehora.hour;
    data_completa += ":";
    data_completa += dataehora.minute;
    data_completa += ":";
    data_completa += dataehora.second;
<<<<<<< HEAD
    aux_data_completa = data_completa;
=======
>>>>>>> 8c575131bce73c09f8a945a389e11b61ac8fd1e7
  }
  

//    DATALOG SD  //
void banco_de_dados(String dataString){
  File dataFile = SD.open("datalog.txt", FILE_WRITE);
  if (dataFile) {
    dataFile.println(dataString);
    dataFile.close();
//    Serial.println(dataString);
  } else {
      Serial.println("error opening datalog.txt");
    }
}

//    ORGANIZA OS DADOS MEDIDOS    //
void float_para_String(float rP, float aP, float pF, float sV, float Ir){

  //   CONVERTE FLOAT PARA STRING   //
  dtostrf(rP, String(rP1).length(), 2, rP1);
  dtostrf(aP, String(aP1).length(), 2, aP1);
  dtostrf(pF, String(pF1).length(), 2, pF1);
  dtostrf(sV, String(sV1).length(), 2, sV1);
  dtostrf(Ir, String(Ir1).length(), 2, Ir1);
  
  dados_arduino_0X00_01 += rP1;
  dados_arduino_0X00_01 += ", ";
  dados_arduino_0X00_01 += aP1;
  dados_arduino_0X00_01 += ", ";
  dados_arduino_0X00_01 += pF1;
  dados_arduino_0X00_01 += ", ";
  dados_arduino_0X00_01 += sV1;
  dados_arduino_0X00_01 += ", ";
  dados_arduino_0X00_01 += Ir1;
}

//   VERIFICAR O TAMANHO DA MENSAGEM  //
void recebe_tamanho(int endereco){
  Wire.requestFrom(endereco,15);
  while (Wire.available()){
    mensagem = Wire.read();
    size_1 = String(mensagem).toInt();
    mensagem = Wire.read();
    size_2 = String(mensagem).toInt();
    mensagem = Wire.read();
    size_3 = String(mensagem).toInt();
    mensagem = Wire.read();
    size_4 = String(mensagem).toInt();
    mensagem = Wire.read();
    size_5 = String(mensagem).toInt();
    mensagem = Wire.read();
    size_6 = String(mensagem).toInt();
    mensagem = Wire.read();
    size_7 = String(mensagem).toInt();
    mensagem = Wire.read();
    size_8 = String(mensagem).toInt();
    mensagem = Wire.read();
    size_9 = String(mensagem).toInt();
    mensagem = Wire.read();
    size_10 = String(mensagem).toInt();
    mensagem = Wire.read();
    size_11 = String(mensagem).toInt();
    mensagem = Wire.read();
    size_12 = String(mensagem).toInt();
    mensagem = Wire.read();
    size_13 = String(mensagem).toInt();
    mensagem = Wire.read();
    size_14 = String(mensagem).toInt();
    mensagem = Wire.read();
    size_15 = String(mensagem).toInt();
  }
  total_size_1 = size_1 + size_2 + size_3 + size_4 + size_5;
  total_size_2 = size_6 + size_7 + size_8 + size_9 + size_10;
  total_size_3 = size_11 + size_12 + size_13 + size_14 + size_15;
}

//    RECEBE OS DADOS DO DISPOSITIVO ESCRAVO    //
String recebe_escravo_1(int endereco){ 
  Wire.requestFrom(endereco,total_size_1);    // (ENDEREÇO,QUANTIDADE DE BYTES)
  while (Wire.available()){
    for(int i = 0; i < size_1; i++){
      mensagem = Wire.read(); 
      dados += mensagem;
    }
    dados += ", "; 
    for(int i = 0; i < size_2; i++){
      mensagem = Wire.read(); 
      dados += mensagem;
    }
    dados += ", "; 
    for(int i = 0; i < size_3; i++){
      mensagem = Wire.read(); 
      dados += mensagem;
    }
    dados += ", "; 
    for(int i = 0; i < size_4; i++){
      mensagem = Wire.read(); 
      dados += mensagem;
    }
    dados += ", "; 
    for(int i = 0; i < size_5; i++){
      mensagem = Wire.read(); 
      dados += mensagem;
    }
  }
  return dados;
}

//    RECEBE OS DADOS DO DISPOSITIVO ESCRAVO    //
String recebe_escravo_2(int endereco){ 
  Wire.requestFrom(endereco,total_size_2);    // (ENDEREÇO,QUANTIDADE DE BYTES)
  while (Wire.available()){
    for(int i = 0; i < size_6; i++){
      mensagem = Wire.read(); 
      dados += mensagem;
    }
    dados += ", "; 
    for(int i = 0; i < size_7; i++){
      mensagem = Wire.read(); 
      dados += mensagem;
    }
    dados += ", "; 
    for(int i = 0; i < size_8; i++){
      mensagem = Wire.read(); 
      dados += mensagem;
    }
    dados += ", "; 
    for(int i = 0; i < size_9; i++){
      mensagem = Wire.read(); 
      dados += mensagem;
    }
    dados += ", "; 
    for(int i = 0; i < size_10; i++){
      mensagem = Wire.read(); 
      dados += mensagem;
    }
  }
  return dados;
}

//    RECEBE OS DADOS DO DISPOSITIVO ESCRAVO    //
String recebe_escravo_3(int endereco){ 
  Wire.requestFrom(endereco,total_size_3);    // (ENDEREÇO,QUANTIDADE DE BYTES)
  while (Wire.available()){ 
    for(int i = 0; i < size_11; i++){
      mensagem = Wire.read(); 
      dados += mensagem;
    }
    dados += ", "; 
    for(int i = 0; i < size_12; i++){
      mensagem = Wire.read(); 
      dados += mensagem;
    }
    dados += ", "; 
    for(int i = 0; i < size_13; i++){
      mensagem = Wire.read(); 
      dados += mensagem;
    }
    dados += ", "; 
    for(int i = 0; i < size_14; i++){
      mensagem = Wire.read(); 
      dados += mensagem;
    }
    dados += ", "; 
    for(int i = 0; i < size_15; i++){
      mensagem = Wire.read(); 
      dados += mensagem;
    }       
  }
  return dados;  
}

<<<<<<< HEAD

=======
//    USUARIO E SENHA   // 
boolean validar_usuario(char * linebuf){
  char usuario_senha[] = "admin:admin"; //"usuario:senha";
  byte t = strlen(usuario_senha);
  int tamanhoEnc = (((t-1) / 3) + 1) * 4; //tamanho da string codificada
  char *out = base64_encode(usuario_senha, t);
  char out2[tamanhoEnc];
  for (t=0; t<(tamanhoEnc); t++) { out2[t] = linebuf[21+t]; }
  return (strstr(out2, out)>0);
}
 
>>>>>>> 8c575131bce73c09f8a945a389e11b61ac8fd1e7
//    SD CARD   //   
boolean iniciar_sd_card() {
  pinMode(10, OUTPUT);
  digitalWrite(10, HIGH); 
  if (!SD.begin(PIN_SD_CARD)){ return false; }  
  return true;
}

<<<<<<< HEAD
// MAC address from Ethernet shield sticker under board
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192, 168, 15, 115); // IP address, may need to change depending on network
EthernetServer server(80);  // create a server at port 80
File webFile;               // the web page file on the SD card
char HTTP_req[REQ_BUF_SZ] = {0}; // buffered HTTP request stored as null terminated string
char req_index = 0;              // index into HTTP_req buffer

void exec_ethernet(){
  EthernetClient client = server.available();  // try to get client

    if (client) {  // got client?
        boolean currentLineIsBlank = true;
        while (client.connected()) {
            if (client.available()) {   // client data available to read
                char c = client.read(); // read 1 byte (character) from client
                // buffer first part of HTTP request in HTTP_req array (string)
                // leave last element in array as 0 to null terminate string (REQ_BUF_SZ - 1)
                if (req_index < (REQ_BUF_SZ - 1)) {
                    HTTP_req[req_index] = c;          // save HTTP request character
                    req_index++;
                }
                // last line of client request is blank and ends with \n
                // respond to client only after last line received
                if (c == '\n' && currentLineIsBlank) {
                    // send a standard http response header
                    client.println("HTTP/1.1 200 OK");
                    // remainder of header follows below, depending on if
                    // web page or XML page is requested
                    // Ajax request - send XML file
                    if (StrContains(HTTP_req, "ajax_inputs")) {
                        // send rest of HTTP header
                        client.println("Content-Type: text/xml");
                        client.println("Connection: keep-alive");
                        client.println();
                        // send XML file containing input states
                        XML_response(client);
                    }
                    else {  // web page request
                        // send rest of HTTP header
                        client.println("Content-Type: text/html");
                        client.println("Connection: keep-alive");
                        client.println();
                        // send web page
                        webFile = SD.open("index.htm");        // open web page file
                        if (webFile) {
                            while(webFile.available()) {
                                client.write(webFile.read()); // send web page to client
                            }
                            webFile.close();
                        }
                    }
                    // display received HTTP request on serial port
                    Serial.print(HTTP_req);
                    // reset buffer index and all buffer elements to 0
                    req_index = 0;
                    StrClear(HTTP_req, REQ_BUF_SZ);
                    break;
                }
                // every line of text received from the client ends with \r\n
                if (c == '\n') {
                    // last character on line of received text
                    // starting new line with next character read
                    currentLineIsBlank = true;
                } 
                else if (c != '\r') {
                    // a text character was received from client
                    currentLineIsBlank = false;
                }
            } // end if (client.available())
        } // end while (client.connected())
        delay(1);      // give the web browser time to receive the data
        client.stop(); // close the connection
    } // end if (client)
}

// send the XML file with switch statuses and analog value
void XML_response(EthernetClient cl)
{
  cl.print("<?xml version = \"1.0\" ?>");
    cl.print("<inputs>");
    cl.print("<dtc>");
    cl.print(aux_data_completa);
    cl.print("</dtc>");
    cl.print("<dt>");
    cl.print(aux_hora_completa);
    cl.print("</dt>");
    cl.print("<h_>");
    cl.print(aux_data_hora);
    cl.print("</h_>");
    cl.print("<p1>");
    cl.print(realPower1);
    cl.print("</p1>");
    cl.print("<p2>");
    cl.print(realPower2);
    cl.print("</p2>");
    cl.print("<p3>");
    cl.print(realPower3);
    cl.print("</p3>");
    cl.print("<p4>");
    cl.print(realPower4);
    cl.print("</p4>");
    cl.print("<p5>");
    cl.print(realPower5);
    cl.print("</p5>");
    cl.print("<p6>");
    cl.print(realPower6);
    cl.print("</p6>");
    cl.print("<p7>");
    cl.print(realPower7);
    cl.print("</p7>");
    cl.print("<p8>");
    cl.print(realPower8);
    cl.print("</p8>");
    cl.print("<p9>");
    cl.print(realPower9);
    cl.print("</p9>");
    cl.print("<p10>");
    cl.print(realPower10);
    cl.print("</p10>");
    cl.print("<pt>");
    cl.print(realPowert);
    cl.print("</pt>");
    cl.print("<s1>");
    cl.print(apparentPower1);
    cl.print("</s1>");
    cl.print("<s2>");
    cl.print(apparentPower2);
    cl.print("</s2>");
    cl.print("<s3>");
    cl.print(apparentPower3);
    cl.print("</s3>");
    cl.print("<s4>");
    cl.print(apparentPower4);
    cl.print("</s4>");
    cl.print("<s5>");
    cl.print(apparentPower5);
    cl.print("</s5>");
    cl.print("<s6>");
    cl.print(apparentPower6);
    cl.print("</s6>");
    cl.print("<s7>");
    cl.print(apparentPower7);
    cl.print("</s7>");
    cl.print("<s8>");
    cl.print(apparentPower8);
    cl.print("</s8>");
    cl.print("<s9>");
    cl.print(apparentPower9);
    cl.print("</s9>");
    cl.print("<s10>");
    cl.print(apparentPower10);
    cl.print("</s10>");
    cl.print("<st>");
    cl.print(apparentPowert);
    cl.print("</st>");
    cl.print("<fp1>");
    cl.print(powerFActor1);
    cl.print("</fp1>");
    cl.print("<fp2>");
    cl.print(powerFActor2);
    cl.print("</fp2>");
    cl.print("<fp3>");
    cl.print(powerFActor3);
    cl.print("</fp3>");
    cl.print("<fp4>");
    cl.print(powerFActor4);
    cl.print("</fp4>");
    cl.print("<fp5>");
    cl.print(powerFActor5);
    cl.print("</fp5>");
    cl.print("<fp6>");
    cl.print(powerFActor6);
    cl.print("</fp6>");
    cl.print("<fp7>");
    cl.print(powerFActor7);
    cl.print("</fp7>");
    cl.print("<fp8>");
    cl.print(powerFActor8);
    cl.print("</fp8>");
    cl.print("<fp9>");
    cl.print(powerFActor9);
    cl.print("</fp9>");
    cl.print("<fp10>");
    cl.print(powerFActor10);
    cl.print("</fp10>");
    cl.print("<fpt>");
    cl.print(powerFActort);
    cl.print("</fpt>");
    cl.print("<v1>");
    cl.print(supplyVoltage1);
    cl.print("</v1>");
    cl.print("<v2>");
    cl.print(supplyVoltage2);
    cl.print("</v2>");
    cl.print("<v3>");
    cl.print(supplyVoltage3);
    cl.print("</v3>");
    cl.print("<v4>");
    cl.print(supplyVoltage4);
    cl.print("</v4>");
    cl.print("<v5>");
    cl.print(supplyVoltage5);
    cl.print("</v5>");
    cl.print("<v6>");
    cl.print(supplyVoltage6);
    cl.print("</v6>");
    cl.print("<v7>");
    cl.print(supplyVoltage7);
    cl.print("</v7>");
    cl.print("<v8>");
    cl.print(supplyVoltage8);
    cl.print("</v8>");
    cl.print("<v9>");
    cl.print(supplyVoltage9);
    cl.print("</v9>");
    cl.print("<v10>");
    cl.print(supplyVoltage10);
    cl.print("</v10>");
    cl.print("<vt>");
    cl.print(supplyVoltaget);
    cl.print("</vt>");
    cl.print("<a1>");
    cl.print(Irms1);
    cl.print("</a1>");
    cl.print("<a2>");
    cl.print(Irms2);
    cl.print("</a2>");
    cl.print("<a3>");
    cl.print(Irms3);
    cl.print("</a3>");
    cl.print("<a4>");
    cl.print(Irms4);
    cl.print("</a4>");
    cl.print("<a5>");
    cl.print(Irms5);
    cl.print("</a5>");
    cl.print("<a6>");
    cl.print(Irms6);
    cl.print("</a6>");
    cl.print("<a7>");
    cl.print(Irms7);
    cl.print("</a7>");
    cl.print("<a8>");
    cl.print(Irms8);
    cl.print("</a8>");
    cl.print("<a9>");
    cl.print(Irms9);
    cl.print("</a9>");
    cl.print("<a10>");
    cl.print(Irms10);
    cl.print("</a10>");
    cl.print("<at>");
    cl.print(Irmst);
    cl.print("</at>");
    cl.print("</inputs>");
=======
//    WEBSERVER    //
EthernetServer * server;
 
void write_from_file(EthernetClient &client, char * filename){
  File webFile = SD.open(filename);
  if (webFile) {
    while(webFile.available()) { client.write(webFile.read()); }
    webFile.close();
  } 
  else {
    Serial.print("Erro SD CARD: ");
    Serial.println(filename);
  }
}
 
void iniciar_ethernet(){
  byte ip[4]      = {192,168,0,40};                    
  byte gateway[4] = {192,168,0,1};
  byte subnet[4]  = {255,255,255,0};
  byte mac[6]     = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
  int  porta      = 80;
  server = new EthernetServer(porta);
  Ethernet.begin(mac, ip, gateway, subnet);
  server->begin();
}
 
void html_cab_200_ok(EthernetClient &client){   
  client.println(F("HTTP/1.1 200 OK\n"
                   "Content-Type: text/html\n"
                   "Connection: keep-alive\n\n"));
}
 
void html_logoff(EthernetClient &client){
    client.print(F(
                 "HTTP/1.1 401 Authorization Required\n"  
                 "Content-Type: text/html\n"  
                 "Connnection: close\n\n"  
                 "<!DOCTYPE HTML>\n"  
                 "<html><head><title>Logoff</title>\n"  
                 "<script>document.execCommand('ClearAuthenticationCache', 'false');</script>"  //IE logoff
                 "<script>try {"                                                                //mozila logoff
                 "   var agt=navigator.userAgent.toLowerCase();"
                 "   if (agt.indexOf(\"msie\") != -1) { document.execCommand(\"ClearAuthenticationCache\"); }"
                 "   else {"
                 "     var xmlhttp = createXMLObject();"
                 "      xmlhttp.open(\"GET\",\"URL\",true,\"logout\",\"logout\");"
                 "     xmlhttp.send(\"\");"
                 "     xmlhttp.abort();"
                 "   }"
                 " } catch(e) {"
                 "   alert(\"erro ao fazer logoff\");"
                 " }"
                 "function createXMLObject() {"
                 "  try {if (window.XMLHttpRequest) {xmlhttp = new XMLHttpRequest();} else if (window.ActiveXObject) {xmlhttp=new ActiveXObject(\"Microsoft.XMLHTTP\");}} catch (e) {xmlhttp=false;}"
                 "  return xmlhttp;"
                 "}</script>"
                 "</head><body><h1>Voce nao esta mais conectado</h1></body></html>\n"));
}
 
void html_autenticar(EthernetClient &client) {
  client.print(F("HTTP/1.1 401 Authorization Required\n"  
               "WWW-Authenticate: Basic realm=\"Area Restrita\"\n"  
               "Content-Type: text/html\n"  
               "Connnection: close\n\n"  
               "<!DOCTYPE HTML>\n"  
               "<html><head><title>Error</title>\n"  
               "</head><body><h1>401 Acesso nao autorizado</h1></body></html>\n"));
}
 
void html_autenticado(EthernetClient &client, char * filename){
  client.println(F("HTTP/1.1 200 OK\n"
                   "Content-Type: text/html\n"
                   "Connection: keep-alive\n")); 
  write_from_file(client, filename);
}
 
void js_file(EthernetClient &client, char * filename){
  client.println(F("HTTP/1.1 200 OK\n"
                   "Content-Type: text/javascript\n"
                   "Connection: keep-alive\n")); 
  write_from_file(client, filename);
}

void chart_file(EthernetClient &client, char * filename){
  client.println(F("HTTP/1.1 200 OK\n"
                   "Content-Type: text/javascript\n"
                   "Connection: keep-alive\n")); 
  write_from_file(client, filename);
}
 
void css_file(EthernetClient &client, char * filename){
  client.println(F("HTTP/1.1 200 OK\n"
                   "Content-Type: text/css\n"
                   "Connection: keep-alive\n"));
  write_from_file(client, filename);
}
 
void favicon_file(EthernetClient &client, char * filename){
  client.println(F("HTTP/1.1 200 OK\n"
                   "Content-Type: image/x-icon\n"
                   "Connection: keep-alive\n"));
  write_from_file(client, filename);
}
  
void pdf_file_download(EthernetClient &client, char * filename){
  client.println(F("HTTP/1.1 200 OK\n"
                   "Content-Type: application/download\n"
                   "Connection: close\n"));    
  write_from_file(client, filename);
}
 
void jpg_file(EthernetClient &client, char * filename){
  client.println(F("HTTP/1.1 200 OK\n"
                   "Content-Type: file/jpg\n"
                   "Connection: close\n"));    
  write_from_file(client, filename);
}
  
void exec_ethernet() {
  EthernetClient client = server->available();
  if (client) {
    char linebuf[80];
    memset(linebuf, 0, sizeof(linebuf));  
    int     charCount          = 0;
    boolean autenticado        = false;
    boolean currentLineIsBlank = true;
    boolean logoff             = false;
    boolean indCss             = false;
    boolean indJs              = false;
    boolean indChart           = false;
    boolean indAjax            = false;
    boolean indPdfDataSheet    = false;
    boolean indJpgUno          = false;
    boolean indFavicon         = false; 
    while (client.connected()){
      if (client.available()){
        char c = client.read(); 
        linebuf[charCount] = c;
        if (charCount<sizeof(linebuf)-1){ charCount++; }
        Serial.write(c); 
        if (c == '\n' && currentLineIsBlank){
          if (autenticado && !logoff ){
            if (indJs){
              js_file(client, "js.js");                          //js file
            } else if(indChart){
              chart_file(client, "chart.js");
            } else if(indAjax){
              chart_file(client, "ajax.js");
            } else if(indCss){
              css_file(client, "css.css");                       //css file  
            } else if(indPdfDataSheet){
              pdf_file_download(client, "atmel.pdf");        //datasheet download
            } else if(indJpgUno){
              jpg_file(client, "uno.jpg");                       //jpg file
            } else if(indFavicon){
              jpg_file(client, "favicon.ico");                   //icone do browser
            } else if(StrContains(linebuf, "ajax_inputs")){
              // send rest of HTTP header
              client.println("Content-Type: text/xml");
              client.println("Connection: keep-alive");
              client.println();
              // send XML file containing input states
              XML_response(client);
            } else {
              html_autenticado(client, "index.htm");             //página inicial
            }
          } else {
            logoff ? html_logoff(client) : html_autenticar(client);
          }
          break;
        }
        if (c == '\n') { 
          currentLineIsBlank = true;               
          if (strstr(linebuf, "GET /logoff"         )>0 ) { logoff = true; }
          if (strstr(linebuf, "Authorization: Basic")>0 ) { if ( validar_usuario(linebuf) )   {  autenticado = true;   } }  
          if (strstr(linebuf, "GET /css.css"        )>0 ) { indCss = true; }
          if (strstr(linebuf, "GET /js.js"          )>0 ) { indJs = true; }
          if (strstr(linebuf, "GET /chart.js"       )>0 ) { indChart = true; }
          if (strstr(linebuf, "GET /ajax.js"        )>0 ) { indAjax = true; }
          if (strstr(linebuf, "GET /atmel.pdf"      )>0 ) { indPdfDataSheet = true; }
          if (strstr(linebuf, "GET /uno.jpg"        )>0 ) { indJpgUno = true; }
          if (strstr(linebuf, "GET /favicon.ico"    )>0 ) { indFavicon = true; } 
          memset(linebuf, 0, sizeof(linebuf));
          charCount = 0;
        } else if (c != '\r') {
          currentLineIsBlank = false;
        }
      }
    }
    delay(1);           
    client.stop();      
  }
}

// send the XML file with switch statuses and analog value
void XML_response(EthernetClient &client)
{
    int analog_val;
    
    client.print("<?xml version = \"1.0\" ?>");
    client.print("<inputs>");
    client.print("<dtc>");
    client.print(data_completa);
    client.print("</dtc>");
    client.print("<dt>");
    client.print(hora_completa);
    client.print("</dt>");
    client.print("<h_>");
    client.print(data_hora);
    client.print("</h_>");
    client.print("<p1>");
    client.print(realPower1);
    client.print("</p1>");
    client.print("<p2>");
    client.print(realPower2);
    client.print("</p2>");
    client.print("<p3>");
    client.print(realPower3);
    client.print("</p3>");
    client.print("<p4>");
    client.print(realPower4);
    client.print("</p4>");
    client.print("<p5>");
    client.print(realPower5);
    client.print("</p5>");
    client.print("<p6>");
    client.print(realPower6);
    client.print("</p6>");
    client.print("<p7>");
    client.print(realPower7);
    client.print("</p7>");
    client.print("<p8>");
    client.print(realPower8);
    client.print("</p8>");
    client.print("<p9>");
    client.print(realPower9);
    client.print("</p9>");
    client.print("<p10>");
    client.print(realPower10);
    client.print("</p10>");
    client.print("<pt>");
    client.print(realPowert);
    client.print("</pt>");
    client.print("<s1>");
    client.print(apparentPower1);
    client.print("</s1>");
    client.print("<s2>");
    client.print(apparentPower2);
    client.print("</s2>");
    client.print("<s3>");
    client.print(apparentPower3);
    client.print("</s3>");
    client.print("<s4>");
    client.print(apparentPower4);
    client.print("</s4>");
    client.print("<s5>");
    client.print(apparentPower5);
    client.print("</s5>");
    client.print("<s6>");
    client.print(apparentPower6);
    client.print("</s6>");
    client.print("<s7>");
    client.print(apparentPower7);
    client.print("</s7>");
    client.print("<s8>");
    client.print(apparentPower8);
    client.print("</s8>");
    client.print("<s9>");
    client.print(apparentPower9);
    client.print("</s9>");
    client.print("<s10>");
    client.print(apparentPower10);
    client.print("</s10>");
    client.print("<st>");
    client.print(apparentPowert);
    client.print("</st>");
    client.print("<fp1>");
    client.print(powerFActor1);
    client.print("</fp1>");
    client.print("<fp2>");
    client.print(powerFActor2);
    client.print("</fp2>");
    client.print("<fp3>");
    client.print(powerFActor3);
    client.print("</fp3>");
    client.print("<fp4>");
    client.print(powerFActor4);
    client.print("</fp4>");
    client.print("<fp5>");
    client.print(powerFActor5);
    client.print("</fp5>");
    client.print("<fp6>");
    client.print(powerFActor6);
    client.print("</fp6>");
    client.print("<fp7>");
    client.print(powerFActor7);
    client.print("</fp7>");
    client.print("<fp8>");
    client.print(powerFActor8);
    client.print("</fp8>");
    client.print("<fp9>");
    client.print(powerFActor9);
    client.print("</fp9>");
    client.print("<fp10>");
    client.print(powerFActor10);
    client.print("</fp10>");
    client.print("<fpt>");
    client.print(powerFActort);
    client.print("</fpt>");
    client.print("<v1>");
    client.print(supplyVoltage1);
    client.print("</v1>");
    client.print("<v2>");
    client.print(supplyVoltage2);
    client.print("</v2>");
    client.print("<v3>");
    client.print(supplyVoltage3);
    client.print("</v3>");
    client.print("<v4>");
    client.print(supplyVoltage4);
    client.print("</v4>");
    client.print("<v5>");
    client.print(supplyVoltage5);
    client.print("</v5>");
    client.print("<v6>");
    client.print(supplyVoltage6);
    client.print("</v6>");
    client.print("<v7>");
    client.print(supplyVoltage7);
    client.print("</v7>");
    client.print("<v8>");
    client.print(supplyVoltage8);
    client.print("</v8>");
    client.print("<v9>");
    client.print(supplyVoltage9);
    client.print("</v9>");
    client.print("<v10>");
    client.print(supplyVoltage10);
    client.print("</v10>");
    client.print("<vt>");
    client.print(supplyVoltaget);
    client.print("</vt>");
    client.print("<a1>");
    client.print(Irms1);
    client.print("</a1>");
    client.print("<a2>");
    client.print(Irms2);
    client.print("</a2>");
    client.print("<a3>");
    client.print(Irms3);
    client.print("</a3>");
    client.print("<a4>");
    client.print(Irms4);
    client.print("</a4>");
    client.print("<a5>");
    client.print(Irms5);
    client.print("</a5>");
    client.print("<a6>");
    client.print(Irms6);
    client.print("</a6>");
    client.print("<a7>");
    client.print(Irms7);
    client.print("</a7>");
    client.print("<a8>");
    client.print(Irms8);
    client.print("</a8>");
    client.print("<a9>");
    client.print(Irms9);
    client.print("</a9>");
    client.print("<a10>");
    client.print(Irms10);
    client.print("</a10>");
    client.print("<at>");
    client.print(Irmst);
    client.print("</at>");
    client.print("</inputs>");
>>>>>>> 8c575131bce73c09f8a945a389e11b61ac8fd1e7
}

// sets every element of str to 0 (clears array)
void StrClear(char *str, char length)
{
    for (int i = 0; i < length; i++) {
        str[i] = 0;
    }
}

// searches for the string sfind in the string str
// returns 1 if string found
// returns 0 if string not found
char StrContains(char *str, char *sfind)
{
    char found = 0;
    char index = 0;
    char len;

    len = strlen(str);
    
    if (strlen(sfind) > len) {
        return 0;
    }
    while (index < len) {
        if (str[index] == sfind[found]) {
            found++;
            if (strlen(sfind) == found) {
                return 1;
            }
        }
        else {
            found = 0;
        }
        index++;
    }

    return 0;
}

<<<<<<< HEAD
=======
//    BASE 64 CODE/DECODE   //
static const char b64all[] =
"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdef"
"ghijklmnopqrstuvwxyz0123456789+/";

const char *base64_encode(const char *original, int length) {
  if (length == 0)
  length = strlen(original);
  
  // Inteiro com o tamanho do código a ser gerado
  int b64length = ((length + 2) / 3) * 4 + 1;
  
  // Contadores para percorrer as strings
  int i=0, j=0;
  
  // Alocando memória para o código
  char *b64 = (char *) malloc(sizeof(char) * b64length);
  memset(b64, 0, b64length);
  
  while (i < length) {
  // Codifica um grupo de três bytes...
  _encode(
  (uint8_t *) b64 + j,
  (const uint8_t *) original + i,
  (length - i)
  );
  
  // E segue para o próximo grupo
  i += 3;
  j += 4;
  }
  
  // Retorna o código
  return (const char *) b64;
}

void _encode(uint8_t *dest, const uint8_t *src, int len) {
// Menor que 1, nada a fazer
if (len < 1)
return;

// Dados a serem retornados
int aux[] = { 0, 0, 0, 0 };

// Primeiro elemento: os 6 bits mais significativos do primeiro
// byte
aux[0] = src[0] >> 2;

// Segundo elemento: os 2 bits menos significativos do primeiro e
// os quatro bits mais significativos do segundo byte
aux[1] = (src[0] & 0x03) << 4;

if (len > 1) {
// SE houver um segundo...
aux [1] |= (src[1] & 0xf0) >> 4;

// Terceiro elemento: os quatro bits menos significativos do
// segundo e os dois mais significativos do terceiro byte
aux [2] = (src[1] & 0x0f) << 2;

if (len > 2) {
// Se houver um terceiro...
aux[2] |= src[2] >> 6;

// Quarto elemento: os seis bits menos significatos do
// terceiro byte
aux[3] = src[2] & 0x3f;
}
}

// Codifica agora os valores numéricos para string
dest[0] = b64all[aux[0]];
dest[1] = b64all[aux[1]];
dest[2] = '=';
dest[3] = '=';
if (len > 1) {
dest[2] = b64all[aux[2]];
if (len > 2)
dest[3] = b64all[aux[3]];
}
}

>>>>>>> 8c575131bce73c09f8a945a389e11b61ac8fd1e7
//INCIALIZAÇÃO// 
void setup() {
  
  //    PINOS ANALÓGICOS    //
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  
  //    BIBLIOTECAS   //
  Wire.begin();  
  Serial.begin(9600);
  rtc.begin();
//  rtc.setDateTime(__DATE__, __TIME__);  //  COMENTAR APOS A PRIMEIRA COMPILAÇÃO
  iniciar_sd_card(); 
<<<<<<< HEAD
  Ethernet.begin(mac, ip);  // initialize Ethernet device
  server.begin();           // start to listen for clients
=======
  iniciar_ethernet();
>>>>>>> 8c575131bce73c09f8a945a389e11b61ac8fd1e7

  //    MEDIDORES   //
  emon1.current(SensorCorrente_1,0.98); // (PINO,GANHO/CALIBRAÇÃO)
  emon1.voltage(SensorTensao_1,475,1.7); // (PINO,GANHO/CALIBRAÇÃO, PHASE SHIFT)
}

//LOOP// 
void loop() {

  //    RELÉS   //
  

  //    SERVIDOR    //
  exec_ethernet();

  //    MEDIDOR DE ENERGIA    //
  medir();

  //    AQUISIÇÃO DE DADOS    //
  float_para_String(realPower1,apparentPower1,powerFActor1,supplyVoltage1,Irms1);
  
  relogio();
<<<<<<< HEAD
  //Serial.println(data_completa);
=======
  Serial.println(data_completa);
>>>>>>> 8c575131bce73c09f8a945a389e11b61ac8fd1e7
  recebe_dados();
  
  //    EXTRAI OS DADOS DAS STRINGS    //
  subString_para_float(1);
  subString_para_float(2);
  subString_para_float(3);
  totais();
  
  //    BANCO DE DADOS    //
  envia_dados();
  
  //    REINICIAR AS MENSAGENS    //
  limpar_string();
}

 
