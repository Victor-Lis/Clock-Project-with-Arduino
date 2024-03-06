int botao1 = 3;
int led = 4;

void setup() {
  pinMode(botao1, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  boolean isPushed = (digitalRead(botao1) == LOW);
  Serial.println(isPushed);
  if(isPushed){
    digitalWrite(led, HIGH);
  }else{
    digitalWrite(led, LOW);
    delay(500);
  }
}
