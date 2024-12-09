
#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <Dabble.h>
#include <Servo.h>
Servo meuServo; // Cria um objeto Servo para controlar o servo motor
int pos; // Declara uma variável para controlar a posição do servo mo

 int incremento = 1;
 int dec=0;
 int sel=0;
Servo servo1;  // Cria um objeto Servo para o primeiro servo motor
Servo servo2;
Servo servobase1;  // Cria um objeto Servo para o primeiro servo motor
Servo servobase2;
Servo servo5;  // Cria um objeto Servo para o primeiro servo motor
Servo servo6;

int pos2=150;
int  pos3 =100;
int pos4= 50;
int  pos5=90;
int pos6= 30;
void setup() {
 
  Serial.begin(115200);    //Taxa de transmissão de dados.
  Dabble.begin(9600);      //Taxa de transmissão do seu bluetooth.
  pinMode(13,INPUT);
  servo1.attach(6);  // Associa o primeiro servo motor ao pino digital 9 do Arduino
  servo2.attach(7);
  servobase1.attach(8);  // Associa o primeiro servo motor ao pino digital 9 do Arduino
  servobase2.attach(9);
  servo5.attach(12);  // Associa o primeiro servo motor ao pino digital 9 do Arduino
  servo6.attach(11);
  servo1.write(150); // Define a posição inicial do servo motor para 0 graus
  servo2.write(100);
  servobase1.write(50); // Define a posição inicial do servo motor para 0 graus
  servobase2.write(50);
  servo5.write(90); // Define a posição inicial do servo motor para 0 graus
  servo6.write(30); 
  Serial.begin(9600);

  
}//fim_setup
void loop() {

  //Esta função é usada para atualizar os dados obtidos do smartphone.
  Dabble.processInput();  
  if (GamePad.isStartPressed())
  {
    sel =1;
  }
  if (GamePad.isSelectPressed())
  {
    sel =0;
  }
  if(sel == 1){
    
    int sensor = digitalRead(13);
    Serial.println(sensor);
    if(sensor == 0){
      Serial.println(sensor);
    
    servo6.write(30);
    servo1.write(150);
    servo2.write(100);
    servobase2.write(50);
    servo5.write(90);
    }
  }
  if(sel == 0){
  if (dec == 1){
    
if (GamePad.isUpPressed())     
  {
    
    if (pos2 < 180) {
      pos2 = pos2 + incremento;  // quadrado
      servo1.write(pos2);  // Move o servo para o novo ângulo
      delay(20);  // Delay para criar o efeito gradual (ajuste o valor conforme necessário)
    }
  }
  if (GamePad.isDownPressed())
  {
    if (pos2 > 00) {
      pos2 = pos2 - incremento;  // ciculo
      servo1.write(pos2);  // Move o servo para o novo ângulo
      delay(20);  // Delay para criar o efeito gradual (ajuste o valor conforme necessário)
    }
   }
  }  
    if( dec == 2){
      if (GamePad.isUpPressed())     
  {
   
    if (pos3 < 150) {
      pos3 = pos3 + incremento;  // Aumenta o ângulo
      servo2.write(pos3);  // Move o servo para o novo ângulo
      delay(10);  // Delay para criar o efeito gradual (ajuste o valor conforme necessário)
    }
  }
  if (GamePad.isDownPressed())
  {
    if (pos3 > 0) {
      pos3 = pos3 - incremento;  // Aumenta o ângulo
      servo2.write(pos3);  // Move o servo para o novo ângulo
      delay(10);  // Delay para criar o efeito gradual (ajuste o valor conforme necessário)
    }
  }
    }

if( dec == 3){
  
  if (GamePad.isUpPressed())     
  {
    
    if (pos4 < 60) {
      pos4 = pos4 + incremento;  // XXXX
      servobase2.write(pos4);
      delay(30);  // Delay para criar o efeito gradual (ajuste o valor conforme necessário)
    }
    
  }
  if (GamePad.isDownPressed())
  {
    if (pos4 > 0) {
      pos4 = pos4 - incremento;  // Aumenta o ângulo
      servobase2.write(pos4);
      delay(60);  // Delay para criar o efeito gradual (ajuste o valor conforme necessário)
    }
  }
}
if(dec == 4){
  if (GamePad.isUpPressed())     
  {
   
    if (pos5 <= 180) {
      pos5 = pos5 + incremento;  // Aumenta o ângulo
      servo5.write(pos5);  // Move o servo para o novo ângulo
      delay(30);  // Delay para criar o efeito gradual (ajuste o valor conforme necessário)
    }
  }
  if (GamePad.isDownPressed())
  {
    Serial.println("Botão pressionado2");
    if (pos5 >= 0) {
      pos5 = pos5 - incremento;  // Aumenta o ângulo
      servo5.write(pos5);  // Move o servo para o novo ângulo
      delay(30);  // Delay para criar o efeito gradual (ajuste o valor conforme necessário)
    }
  }
}
//=================> Para esquerda
  if (GamePad.isLeftPressed())
  {
    Serial.println("Botão pressionado3");
    
    
    if (pos6 < 150) {
      pos6 = pos6 + incremento;  // Aumenta o ângulo
     
      servo6.write(pos6);// Move o servo para o novo ângulo
      delay(30);  // Delay para criar o efeito gradual (ajuste o valor conforme necessário)
    }
  }

//=================> Para direita
  if (GamePad.isRightPressed())
  {
    if (pos6 > 30) {
      pos6 = pos6 - incremento;  // Aumenta o ângulo
       
      servo6.write(pos6);  // Move o servo para o novo ângulo
      delay(30);  // Delay para criar o efeito gradual (ajuste o valor conforme necessário)
    }
  }

//=================> Quadrado
 if (GamePad.isSquarePressed())
  {
    dec = 1;
    pos2;
  }  

//=================> Circulo
  if (GamePad.isCirclePressed())
  {
    dec = 2;
    pos3;
  }

//=================> Cruz
  if (GamePad.isCrossPressed())
  {
    dec = 3;
    pos4;
  }

//=================> Triangulo
  if (GamePad.isTrianglePressed())
  {
    dec = 4;
    pos5;
  }
  }
}

  