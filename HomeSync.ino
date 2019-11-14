
String inputString  = "";
int MAX_INPUT_SIZE = 10000;
int FLASH_DELAY = 400;

//indicator light
int indicatorPin = 13;

//blinds
int blindsStop = 6; // yellow
int blindsDown = 8; // white
int blindsUp = 7; //blue

//Relays
int porchLight = 4;
int dinningRoomLight = 2;
int livingRoomLight = 11;
int bedroomLight = 3;
int kitchenLight = 9;

//DEFINE ARRAYS FOR SENDING
void setup() {
  Serial.begin(115200);
  inputString.reserve(MAX_INPUT_SIZE+1);

  // SET AS OUTPUT

  //indicator
  pinMode(indicatorPin,OUTPUT);

  //lights
  pinMode(porchLight, OUTPUT);
  pinMode(dinningRoomLight, OUTPUT);
  pinMode(livingRoomLight, OUTPUT);
  pinMode(bedroomLight, OUTPUT);
  pinMode(kitchenLight, OUTPUT);

  //blinds
  pinMode(blindsStop, OUTPUT);
  pinMode(blindsDown, OUTPUT);
  pinMode(blindsUp, OUTPUT);

  //SET INITIAL VALUES

  //indicator
  digitalWrite(indicatorPin,LOW);

  //lights
  digitalWrite(porchLight, LOW);
  digitalWrite(dinningRoomLight, LOW);
  digitalWrite(livingRoomLight, LOW);
  digitalWrite(bedroomLight, LOW);
  digitalWrite(kitchenLight, LOW);


  //blinds
  digitalWrite(blindsStop, HIGH);
  digitalWrite(blindsDown, HIGH);
  digitalWrite(blindsUp, HIGH);

  flashIndicator(4);
}

void loop(){}

void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();

    if(inputString.length() == MAX_INPUT_SIZE-1) {
      
        sendMessage(inputString);
        inputString = "";
    }

    // add it to the inputString:
    if(isValidChar(inChar)){
      inputString += inChar;
    }

    if (inChar == '\n' || inChar == ';') {
      
      Serial.println("inputString: " + inputString);
      sendMessage(inputString);
      inputString = "";

    }
  }
}

void sendMessage(String msg) {

      Serial.println("SEND MSG: " + msg);
  
    if (contains(msg,"ELECTRONICS_BLINDS_UP")) {
      Serial.println("SEND ELECTRONICS_BLINDS_UP");
      click_blinds_button(blindsUp);
      flashIndicator(1);
    }
    if (contains(msg,"ELECTRONICS_BLINDS_STOP")){
      click_blinds_button(blindsStop);
      flashIndicator(2);
    }
    if (contains(msg,"ELECTRONICS_BLINDS_DOWN")){
      click_blinds_button(blindsDown);
      flashIndicator(3);
    }
    if (contains(msg,"ELECTRONICS_BEDROOM_LIGHTS")){
      changeRelay(bedroomLight);
      flashIndicator(4);
    }
    if (contains(msg,"ELECTRONICS_LIVINGROOM_LIGHTS")){
      changeRelay(livingRoomLight);
      flashIndicator(5);
    }
    if (contains(msg,"ELECTRONICS_KITCHENK_LIGHTS")){
      changeRelay(kitchenLight);
      flashIndicator(6);
    }
    if (contains(msg,"ELECTRONICS_DINING_LIGHTS")){
      changeRelay(dinningRoomLight);
      flashIndicator(7);
    }
    if (contains(msg,"ELECTRONICS_PATIO_LIGHTS")){
      changeRelay(porchLight);
      flashIndicator(8);
    }
}

bool contains(String source, String target) {

    // TODO improve contains
     return source.equals(target);
}
void click_blinds_button(int button){
  digitalWrite(button,LOW);
  delay(500);
  digitalWrite(button,HIGH);
}

void changeRelay(int relayPin){
  digitalWrite(relayPin, !digitalRead(relayPin));
}

void flashIndicator(int rep){
    for(int i = 0; i < rep; i++){
      digitalWrite(indicatorPin,HIGH);
      delay(FLASH_DELAY);
      digitalWrite(indicatorPin,LOW);
      delay(FLASH_DELAY);
  }
}

boolean isValidChar(char c){
  int ci = c+0;

  //see if letter is capital
  if(ci >= 65 && ci <= 90)
    return true;

  //see if letter is an underscore
  if(ci == 95)
    return true;

  return false;
}
