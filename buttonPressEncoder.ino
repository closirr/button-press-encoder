const int signalAPin = 5; 
const int signalBPin = 7; 
const int signalCPin = 8; 

int signalSequence[4][2] = {
    {1, 0}, 
    {0, 0}, 
    {0, 1}, 
    {1, 1}  
};

int signalSequenceQuiet[4][2] = {
    {0, 1}, 
    {0, 0}, 
    {1, 0}, 
    {1, 1} 
};

void setup() {
  pinMode(signalAPin, OUTPUT); 
  pinMode(signalBPin, OUTPUT); 
  pinMode(signalCPin, INPUT);
  digitalWrite(signalCPin, LOW);
}

void changeVolume(int sequence[4][2]){
 for (int i = 0; i < 4; i++) {
      digitalWrite(signalAPin, sequence[i][0]);
      digitalWrite(signalBPin, sequence[i][1]);
      delay(45);
    }
    delay(150);
}

void makeLouder(int count) {
  for (int i = 0; i < count; i++) {
    changeVolume(signalSequence);
  }
}

void makeQuiet(int count) {
  for (int i = 0; i < count; i++) {
    changeVolume(signalSequenceQuiet);
  }
}

void switchMode(){
    pinMode(signalCPin, OUTPUT);
    digitalWrite(signalCPin, HIGH);
    delay(100);
    digitalWrite(signalCPin, LOW);
    delay(100);
    pinMode(signalCPin, INPUT);
}

bool stop = false;
void loop() {
  delay(2000);
  if (stop == false){
  makeLouder(12);
  delay(300);
  switchMode();
  makeLouder(5);
  switchMode();
  makeLouder(7);
  switchMode();
  stop = true;
  }
}