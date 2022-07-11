# AutomatON: Monitoramento e Acionamento Remoto de Computadores ![Badge em Desenvolvimento](http://img.shields.io/static/v1?label=STATUS&message=FINALIZADO&color=GREEN&style=for-the-badge)

### Projeto acadêmico de um sistema embarcado em um microcontrolador ESP32 para acionamento remoto de computadores desktop por meio de mensagem de texto. <br> [Link do Artigo](https://drive.google.com/file/d/1ScTyarGfHrYJlSr69TWGFu8Z_T7S2iAk/view)

### Antes de utilizá-lo é necessário preencher as seguintes variáveis:
`wifi <string>` - SSID da rede wifi. <br>
`senha <string>` - Senha da rede wifi. <br>
`token <string>` - Token gerado pela [API BotFather](https://t.me/botfather). <br>
`rele <int8>` - Pino em que está conectado o Módulo Relé 3v. <br>
`ledConexao <int8>` - Pino em que está conectado o led que indica conexão. <br>
`ledComando <int8>` - Pino em que está conectado o led que execução de comando. <br>
`sensor <int8>` - Pino em que está conectado o Sensor de Tensão 5v. <br>
`valorSensor <float>` - Variável que a armazenado o valor de tensão analógica. <br>
`msg.sender.id` - Definir o User ID do Telegram no segundo IF dentro da função loop().

### Como funciona:
O sistema, em loop, verifica se há novas mensagens no Telegram utilizando o método `getNewMessage()` da biblioteca `CTBot.h`. <br>
Se houver uma nova mensagem, o código verifica se o remetente é autorizado (seu ID deve ser igual ao ID fornecido no código em "SEU ID AQUI"). Se o remetente for autorizado, o código verifica qual comando foi enviado pelo usuário, os comandos possíveis são:

`/start` - Inicia o bot, o usuário recebe uma mensagem de boas vindas e apresenta a lista de comandos. <br>
`Status` - Verifica a tensão diretamente no conector molex da fonte, retornando ao usuário se o computador está ligado ou desligado.<br>
`Ligar` - Fecha e abre o contato do módulo relé em um intervalo de 500ms, simulando o ato de pressionar o botão de ligar.<br>
`Desligar` - Fecha e abre o contato do módulo relé em um intervalo de 500ms, simulando o ato de pressionar o botão de desligar.<br>
`Desligamento forçado` - Fecha o contato do módulo relé por 7000ms, simulando o ato de segurar o botão de desligar.<br>

*Se o ID do usuário ou o comando não forem válidos, uma mensagem de erro é enviada.

<div align="center">

![image](https://github.com/AlexFlorenco/automatON/assets/92060682/81f1c47a-88fb-4590-9a35-d87daf05a613)
</div>

## 🛠 Técnicas e tecnologias utilizadas

- <img src="https://cdn1.telegram-cdn.org/file/l_lRZkvdxo3qI5q_Vro64BIDUYQ_5DCvER2R2rRYq1MReR6A1dr-rOLVUHBRI6hihR0QD3SfUWp3Ey_4Kq4UI7mebw82gK3HK1hoZU3NklW4JToTP9-fMc2Swdob5uU_dkpHBLi3O6FgsLAh9H01bQ6lQR5HC6Vcemn1B-t0XHE5LIE64O618kMyI2qyJBjnoIrTh_k3Z2sFo9_nwXAhoiVYRf6UT7wKW71Ho3ALRKysv73I45Cvh7dLRFzpp9bK41nHmbgB9TjXcIcwK2ejUtfUYcZkISdNNWP-rLHypSJeNIvsaUoRRdXKCItihuQRavI0vV5NhhDsRsUASdxFcQ.jpg" width="20" height="20"/> [API BotFather](https://t.me/botfather) 
- <img src="https://www.nicepng.com/png/detail/207-2079566_arduino-1-logo-png-transparent-arduino-logo-png.png" alt="java" width="20" height="20"/> [Biblioteca CTBot.h](https://github.com/shurillu/CTBot) 
- <img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/cplusplus/cplusplus-original.svg" width="20" height="20"/> C++

## 👨‍💻 Desenvolvedor

| [<img src="https://avatars.githubusercontent.com/u/92060682?v=4" width=115><br><sub>Alexandre Florenço</sub>](https://github.com/alexflorenco) |  
| :---: | 