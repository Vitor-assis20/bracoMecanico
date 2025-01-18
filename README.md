# Projeto: Braço Mecânico Controlado por Bluetooth  

![Foto do Protótipo](https://github.com/user-attachments/assets/8020e546-0a07-4cd2-b2f8-e6271fd51aeb)  

## Descrição  
Este projeto foi desenvolvido como parte da disciplina **DAS5412** do curso de Engenharia de Controle e Automação na **Universidade Federal de Santa Catarina (UFSC)**.  

O braço mecânico é controlado por dispositivos Android utilizando a biblioteca **Dabble**. Através do joystick do aplicativo, é possível variar os ângulos dos servos (de 0° a 180°) para controlar os movimentos do braço.  

### Funcionalidades principais:  
- **Seleção do Servo**: Os botões geométricos no joystick permitem selecionar o servo a ser ajustado.  
- **Controle do Ângulo**: As setas "cima" e "baixo" ajustam o ângulo do servo selecionado.  
- **Movimento Horizontal**: As setas "esquerda" e "direita" movimentam a estrutura horizontalmente em torno de seu eixo.  

---

## Componentes Utilizados  
- Estrutura impressa em **3D**  
- **Arduino Uno**  
- **Módulo Bluetooth HC-05**  
- **6 Motores Servo**  

---

## Como Executar  
1. **Configuração de Hardware**: Monte o braço mecânico conforme o esquema do projeto e conecte os componentes eletrônicos ao Arduino Uno.  
2. **Carregar o Código**: Faça o upload do código fornecido para o Arduino utilizando a IDE Arduino.  
3. **Conectar ao Bluetooth**: Emparelhe o módulo HC-05 ao dispositivo Android e inicie o aplicativo Dabble.  
4. **Controlar o Braço**: Utilize o joystick do aplicativo para movimentar o braço conforme as funcionalidades descritas.  

---

Contribuições, sugestões ou dúvidas são sempre bem-vindas!  
