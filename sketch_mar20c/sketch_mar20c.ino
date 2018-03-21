  int ledR = 8;
  int ledB = 9;
  int ledG = 10;
  int ledY = 11;
  int SW2 = 6;
  int SW3 = 7;
  int SW2state = HIGH;
  int SW3state = HIGH;
  bool LedsON = false;
  unsigned long StartMillis = 0;
  const long interval = 1200;
  
  


void setup() {
// inicializando os pinos digitais de saída.
  pinMode(ledR, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledY, OUTPUT);
// inicializando os pinos digitais de entrada.
  pinMode(SW2, INPUT);
    pinMode(SW3, INPUT);
  Serial.begin (9600);
}
// conteúdo do loop.
void loop() {
  SW2state = digitalRead (SW2);
    SW3state = digitalRead (SW3);
if (SW2state == LOW && LedsON == false )
  {

  digitalWrite(ledR, HIGH); // acender o led vermelho.
    WaitMillis();
  digitalWrite(ledB, HIGH); // acender o led azul.
    WaitMillis();
  digitalWrite(ledG, HIGH); // acender o led verde.
    WaitMillis();
  digitalWrite(ledY, HIGH); // acender o led amarelo.
  Serial.write('H');
  LedsON = true;
  }
  
if (SW3state == LOW && LedsON == true)
  {

  digitalWrite(ledY, LOW); // apagar o led amarelo.
    WaitMillis();
  digitalWrite(ledG, LOW); // apagar o led verde.
    WaitMillis();
  digitalWrite(ledB, LOW); // apagar o led azul.
    WaitMillis();
  digitalWrite(ledR, LOW); // apagar o led vermelho.
  Serial.write('L');
  LedsON = false;
  
  }
  } 
void WaitMillis() {
StartMillis = millis();
  do{}
  while (millis() - StartMillis < interval);
  return;
}


