/*
AutomatON - Sistema Embarcado para Monitoramento e Acionamento de Cargas Via Chatbot (Telegram)
Autor: Alexandre Florenço
*/

#include "CTBot.h" 
CTBot bot; 

//Parâmetros para conexão com wifi e Telegram
String wifi  = "SEU SSID AQUI";
String senha  = "SUA SENHA AQUI";
String token = "SEU TOKEN AQUI";

//Pinos
uint8_t rele = 25;
uint8_t ledConexao = 13;
uint8_t ledComando = 12;
uint8_t sensor = 36;
float valorSensor;

void setup(){
    Serial.begin(115200);
    Serial.println("INICIANDO AUTOMATON...");
    pinMode(sensor, INPUT);
    pinMode(rele, OUTPUT);
    pinMode(ledConexao, OUTPUT);
    pinMode(ledComando, OUTPUT);

    //Conexão com wifi e Telegram
    bot.wifiConnect(wifi, senha);
    bot.setTelegramToken(token);
   
    if (bot.testConnection()){
        Serial.println("\nCONEXÃO BEM-SUCEDIDA");
        digitalWrite(ledConexao, HIGH);
    }
    else
        Serial.println("\nFALHA NA CONEXÃO"); 
}    

void loop(){
  TBMessage msg;
  String usuario;
  valorSensor = analogRead(sensor);
  
  if (bot.getNewMessage(msg)){
    usuario = msg.sender.username;
    Serial.println(usuario + ": " + msg.text);

    if (msg.sender.id != SEU ID AQUI){
      bot.sendMessage(msg.sender.id, "Acesso negado");
    }
    else {
      if (msg.text.equalsIgnoreCase("/start")){
        bot.sendMessage(msg.sender.id, "Olá, " + msg.sender.username + "!");      
        bot.sendMessage(msg.sender.id, "Ligue ou desligue o seu computador remotamente.\n\nUtilize os comandos:\n\t\t\t\t\tStatus\n\t\t\t\t\tLigar\n\t\t\t\t\tDesligar\n\t\t\t\t\tDesligamento forçado");
      }
      
      else if (msg.text.equalsIgnoreCase("Status")){
        if (valorSensor != 0){
          Serial.println(valorSensor);
          bot.sendMessage(msg.sender.id, "O computador está ligado");
        }
        else if (valorSensor == 0){
          Serial.println(valorSensor);
          bot.sendMessage(msg.sender.id, "O computador está desligado");
        }
      }

      
      else if (msg.text.equalsIgnoreCase("Ligar")){
        bot.sendMessage(msg.sender.id, "Ligando computador...");
        digitalWrite(rele, HIGH);
        digitalWrite(ledComando, HIGH);
        delay(500);
        digitalWrite(rele, LOW);
        digitalWrite(ledComando, LOW);
      }

      else if (msg.text.equalsIgnoreCase("Desligar")){
        bot.sendMessage(msg.sender.id, "Desligando computador...");
        digitalWrite(rele, HIGH);
        digitalWrite(ledComando, HIGH);
        delay(500);
        digitalWrite(rele, LOW);
        digitalWrite(ledComando, LOW);
      }

      else if (msg.text.equalsIgnoreCase("Desligamento foru00e7ado")){
        bot.sendMessage(msg.sender.id, "Desligando computador...");
        digitalWrite(rele, HIGH);
        digitalWrite(ledComando, HIGH);
        delay(7000);
        digitalWrite(rele, LOW);
        digitalWrite(ledComando, LOW);
      }

      else{
        bot.sendMessage(msg.sender.id, "Comando inválido");
        bot.sendMessage(msg.sender.id, "Utilize os comandos:\n\t\t\t\t\tLigar\n\t\t\t\t\tDesligar\n\t\t\t\t\tDesligamento forçado");
      }
    }
  }
  delay(500);
}
