const int buttonPin = 2;
int count = 0;
volatile int reading = 1;
volatile int buttonState = 1;

unsigned long lastDebounceTime = 0;
unsigned long lastPressed = 0;

unsigned long debounceDelay = 200;
void buttonPressed() {
  
  reading = digitalRead(buttonPin);
  if (reading < buttonState){
    Serial.print(reading);
    Serial.print(' ');
    Serial.println(buttonState);
    
    lastDebounceTime = millis();
  }
  if((millis()-lastDebounceTime) > debounceDelay){
    if(reading == 0){
      Serial.print("Interrupt ");
    Serial.print(++count);
    Serial.println(" times");
    }
    
//    lastDebounceTime = millis();
    
  }

  buttonState = reading;
  
}

void buttonPressed2() {
  if ((millis() - lastPressed) >  debounceDelay) {
    Serial.print("Interrupt ");
    Serial.print(++count);
    Serial.println(" times");
  }
  lastPressed = millis();
}

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);

  // Interrupts can happen on "edges" of signals.  
  // Three edge types are supported: CHANGE, RISING, and FALLING 
  attachInterrupt(digitalPinToInterrupt(buttonPin), buttonPressed2, FALLING);
  Serial.begin(9600);
}

void loop() {
  for(int i=0;i<100;i++) {
    Serial.println(i);
    delay(1000);
  }
}
