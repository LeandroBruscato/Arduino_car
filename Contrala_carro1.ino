//Programa : Controle 2 motores DC usando Ponte H L298N
//Autor : Leandro Bruscato
 
//Definicoes pinos Arduino ligados a entrada da Ponte H
//Motor A, DIREITA
int IN1 = 4;
int IN2 = 5;
//////////////
//Motor B, ESQUERDA
int IN3 = 6;
int IN4 = 7;
/////////////  
void setup()
{
  //Define os pinos como saida
 pinMode(IN1, OUTPUT);
 pinMode(IN2, OUTPUT);
 pinMode(IN3, OUTPUT);
 pinMode(IN4, OUTPUT);
}

void GiraMotorHorario(char Motor){
  if (Motor =='A'){
     digitalWrite(IN1, HIGH);
     digitalWrite(IN2, LOW);
  }
  if (Motor =='B'){
     digitalWrite(IN3, HIGH);
     digitalWrite(IN4, LOW);
  }
}
void GiraMotorAntiHorario(char Motor){
  if (Motor =='A'){
     digitalWrite(IN1, LOW);
     digitalWrite(IN2, HIGH);
  }
  if (Motor =='B'){
     digitalWrite(IN3, LOW);
     digitalWrite(IN4, HIGH);
  }
}
void ParaMotor(char Motor){
  if (Motor =='A'){
     digitalWrite(IN1, HIGH);
     digitalWrite(IN2, HIGH);
  }
  if (Motor =='B'){
     digitalWrite(IN3, HIGH);
     digitalWrite(IN4, HIGH);
  }
}

void CarrinhoAndaParaFrente(){
  //Faz o carrinho ir para frente
  GiraMotorHorario('A');
  GiraMotorHorario('B');
  delay(2000);
  PararCarrinho();
  delay(500);
}
void CarrinhoAndaParaTras(){
  // Faz o carrinho ir para tras
  GiraMotorAntiHorario('A');
  GiraMotorAntiHorario('B');
  delay(2000);
  PararCarrinho();
  delay(500);
}
void CarrinhoGiraParaEsquerda(){
  // Gira o carrinho para a Esquerda
  GiraMotorHorario('A');
  GiraMotorAntiHorario('B');
  delay(2000);
  PararCarrinho();
  delay(500);
}
void CarrinhoGiraParaDireita(){
  // Gira o carrinho para a Direita
  GiraMotorAntiHorario('A');
  GiraMotorHorario('B');
  delay(2000);
  PararCarrinho();
  delay(500);
}

void PararCarrinho(){
  //Faz o carrinho para
  ParaMotor('A');
  ParaMotor('B');
}

void loop()
{
  CarrinhoAndaParaFrente();
  
  CarrinhoAndaParaTras();
  
  CarrinhoGiraParaDireita();
  
  CarrinhoGiraParaEsquerda();

}
