int botao1 = 2;
int botao2 = 3;
int led = 4;

void setup() {
  pinMode(botao1, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

int hours = 0;
int minutes = 0;

void loop() {
  delay(500);
  
  boolean isPushed1 = (digitalRead(botao1) == LOW);
  boolean isPushed2 = (digitalRead(botao2) == LOW);

  if(isPushed2){
    sumMin();
  }else if(isPushed1){
    sumHour();  
  }

  Serial.print(hours);
  Serial.print(":");
  Serial.println(minutes);
}

void sumHour(){
  if((hours+1) == 24){
    hours = 0;
  }else{
    hours++;
  } 
}

void sumMin() {
  if((minutes+1) >= 60){
    hours++;
    minutes = 0;
  }else{
    minutes++;
  }
}

String formatNum(number){
 if(number < 10){
  return "0"+number; 
 }else{
  return number; 
 }
}
