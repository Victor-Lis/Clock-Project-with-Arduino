int botao1 = 2;
int botao2 = 3;
int led = 4;
const int debounceTime = 50; // Time in milliseconds to debounce button presses

void setup() {
  pinMode(botao1, INPUT_PULLUP);
  pinMode(botao2, INPUT_PULLUP);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

int hours = 0;
int minutes = 0;
unsigned long lastDebounceTime1 = 0;
unsigned long lastDebounceTime2 = 0;

void loop() {
  delay(150);

  // Debounce button presses
  unsigned long currentTime = millis();
  if (digitalRead(botao1) == LOW && (currentTime - lastDebounceTime1) > debounceTime) {
    lastDebounceTime1 = currentTime;
    sumHour();
  }
  if (digitalRead(botao2) == LOW && (currentTime - lastDebounceTime2) > debounceTime) {
    lastDebounceTime2 = currentTime;
    sumMin();
  }

  Serial.print(formatNum(hours));
  Serial.print(":");
  Serial.println(formatNum(minutes));
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

String formatNum(int number){
 if(number < 10){
  return "0"+number; 
 }else{
  return String(number); 
 }
}
