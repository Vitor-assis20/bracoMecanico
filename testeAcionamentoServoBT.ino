/*  Aula xx
 *  Projeto: GamePad - Controlando o carrinho
 *  By: Vander da Silva Gonçalves
 *  Data do projeto: 16/10/2022
 *  Atualizado: 17/10/2022
 *  Engenheiro: Vander Gonçalves
 *  Site: www.mamuteeletronica.com.br
 *  Informações: https://thestempedia.com/docs/dabble/game-pad-module/
 */

//================================================================================
//=================> Atenção!
/*
 * TX do HC05 para o pino digital 2 do Arduino Uno
 * RX do HC05 para o pino digital 3 do Arduino Uno
 */
#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <Dabble.h>
#include <Servo.h>
Servo meuServo; // Cria um objeto Servo para controlar o servo motor
int pos; // Declara uma variável para controlar a posição do servo motor 
 #define ledteste 11
 int incremento = 1;
 int dec=0;
Servo servo1;  // Cria um objeto Servo para o primeiro servo motor
Servo servo2;
Servo servobase1;  // Cria um objeto Servo para o primeiro servo motor
Servo servobase2;
Servo servo5;  // Cria um objeto Servo para o primeiro servo motor
Servo servo6;
void setup() {
 
  Serial.begin(115200);    //Taxa de transmissão de dados.
  Dabble.begin(9600);      //Taxa de transmissão do seu bluetooth.
  pinMode(ledteste,OUTPUT);
  servo1.attach(6);  // Associa o primeiro servo motor ao pino digital 9 do Arduino
  servo2.attach(7);
  servobase1.attach(8);  // Associa o primeiro servo motor ao pino digital 9 do Arduino
  servobase2.attach(9);
  servo5.attach(10);  // Associa o primeiro servo motor ao pino digital 9 do Arduino
  servo6.attach(11);
  servo1.write(100); // Define a posição inicial do servo motor para 0 graus
  servo2.write(100);
  servobase1.write(0); // Define a posição inicial do servo motor para 0 graus
  servobase2.write(180);
  servo5.write(100); // Define a posição inicial do servo motor para 0 graus
  servo6.write(100); 
  Serial.begin(9600);

  
}//fim_setup
void loop() {

  //Esta função é usada para atualizar os dados obtidos do smartphone.
  Dabble.processInput();  
  if (dec == 1){
if (GamePad.isUpPressed())     
  {
    servo1.write(pos);
    if (pos < 120) {
      pos = pos + incremento;  // Aumenta o ângulo
      servo1.write(pos);  // Move o servo para o novo ângulo
      delay(100);  // Delay para criar o efeito gradual (ajuste o valor conforme necessário)
    }
  }
  if (GamePad.isDownPressed())
  {
    if (pos > 90) {
      pos = pos - incremento;  // Aumenta o ângulo
      servo1.write(pos);  // Move o servo para o novo ângulo
      delay(100);  // Delay para criar o efeito gradual (ajuste o valor conforme necessário)
    }
  }
  }  
    if( dec == 2){
      if (GamePad.isUpPressed())     
  {
    servo2.write(pos);
    if (pos < 120) {
      pos = pos + incremento;  // Aumenta o ângulo
      servo2.write(pos);  // Move o servo para o novo ângulo
      delay(100);  // Delay para criar o efeito gradual (ajuste o valor conforme necessário)
    }
  }
  if (GamePad.isDownPressed())
  {
    if (pos > 90) {
      pos = pos - incremento;  // Aumenta o ângulo
      servo2.write(pos);  // Move o servo para o novo ângulo
      delay(100);  // Delay para criar o efeito gradual (ajuste o valor conforme necessário)
    }
  }
    }

if( dec == 3){
  if (GamePad.isUpPressed())     
  {
    servobase1.write(pos);
    if (pos < 120) {
      pos = pos + incremento;  // Aumenta o ângulo
      int pos1 = pos;
      pos1 = pos1 - incremento;
      servobase1.write(pos);  // Move o servo para o novo ângulo
      servobase2.write(pos1);
      delay(100);  // Delay para criar o efeito gradual (ajuste o valor conforme necessário)
    }
    
  }
  if (GamePad.isDownPressed())
  {
    if (pos > 0) {
      pos = pos - incremento;  // Aumenta o ângulo
      int pos2 = pos;
      pos2 = pos +  incremento;
      servobase1.write(pos);  // Move o servo para o novo ângulo
      servobase2.write(pos2);
      delay(100);  // Delay para criar o efeito gradual (ajuste o valor conforme necessário)
    }
  }
}
if(dec == 4){
  if (GamePad.isUpPressed())     
  {
    servo5.write(pos);
    if (pos < 120) {
      pos = pos + incremento;  // Aumenta o ângulo
      servo5.write(pos);  // Move o servo para o novo ângulo
      delay(100);  // Delay para criar o efeito gradual (ajuste o valor conforme necessário)
    }
  }
  if (GamePad.isDownPressed())
  {
    Serial.println("Botão pressionado2");
    if (pos > 90) {
      pos = pos - incremento;  // Aumenta o ângulo
      servo5.write(pos);  // Move o servo para o novo ângulo
      delay(100);  // Delay para criar o efeito gradual (ajuste o valor conforme necessário)
    }
  }
}
//=================> Para esquerda
  if (GamePad.isLeftPressed())
  {
    Serial.println("Botão pressionado3");
    
    servo6.write(pos);
    if (pos < 120) {
      pos = pos + incremento;  // Aumenta o ângulo
     
      servo6.write(pos);// Move o servo para o novo ângulo
      delay(100);  // Delay para criar o efeito gradual (ajuste o valor conforme necessário)
    }
  }

//=================> Para direita
  if (GamePad.isRightPressed())
  {
    if (pos > 90) {
      pos = pos - incremento;  // Aumenta o ângulo
       
      servo6.write(pos);  // Move o servo para o novo ângulo
      delay(100);  // Delay para criar o efeito gradual (ajuste o valor conforme necessário)
    }
  }

//=================> Quadrado
 if (GamePad.isSquarePressed())
  {
    dec = 1;
  }  

//=================> Circulo
  if (GamePad.isCirclePressed())
  {
    dec = 2;
  }

//=================> Cruz
  if (GamePad.isCrossPressed())
  {
    dec = 3;
  }

//=================> Triangulo
  if (GamePad.isTrianglePressed())
  {
    dec = 4;
  }

/*=================> Start
  if (GamePad.isStartPressed())
  {
    Serial.print("Start");
  }

//=================> Select
  if (GamePad.isSelectPressed())
  {
    Serial.print("Select");
  }
  */

}//fim_loop

