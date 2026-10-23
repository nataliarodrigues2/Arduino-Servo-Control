
#include <Servo.h>

Servo meuServo;

const int POT_ANGULO = A0;
const int POT_VELOCIDADE = A1;
const int PINO_SERVO = 9;

int anguloAtual = 0;

void setup() {
  meuServo.attach(PINO_SERVO);
}

void loop() {
  int leituraAngulo = analogRead(POT_ANGULO);

  // Define o angulo maximo entre 10 e 180 graus
  int anguloMaximo = map(leituraAngulo, 0, 1023, 10, 180);

  // Define a velocidade do movimento
  int leituraVelocidade = analogRead(POT_VELOCIDADE);
  int intervalo = map(leituraVelocidade, 0, 1023, 40, 5);

  // Vai ate o angulo escolhido
  for (anguloAtual = 0; anguloAtual <= anguloMaximo; anguloAtual++) {
    meuServo.write(anguloAtual);
    delay(intervalo);
  }

  // Volta para a posicao inicial
  for (anguloAtual = anguloMaximo; anguloAtual >= 0; anguloAtual--) {
    meuServo.write(anguloAtual);
    delay(intervalo);
  }
}
