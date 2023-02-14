
const int INPUT_PIN = 8; //This is the pin where the input signal from the button goes
//This is actually a *digital* input pin

const int OUTPUT_PIN = 3; //This is the pin where the output into the LED goes
//This is actually an *analog* write pin

int buttonRead = 0; //This variable allows us to store whether the button is pressed or not

void setup() {
  // put your setup code here, to run once:
  pinMode(OUTPUT_PIN, OUTPUT); //Sets the LED pin to be an output

  pinMode(INPUT_PIN, INPUT_PULLUP); //Sets the input pin to be an input
  //Note: don't worry about what "pullup" means for now
}

void loop() {
  // put your main code here, to run repeatedly:

  buttonRead = digitalRead(INPUT_PIN); //Reads whether the button is on or off based on the voltage going into the pin

  //This code segment is responsible for the LED lighting up
  if(buttonRead == LOW) { //If the button is pressed then the voltage is low
    digitalWrite(OUTPUT_PIN, HIGH); //Then the LED pin will receive a large voltage written digitally to light it up
  }
  else { //Otherwise the LED shouldn't light up
    digitalWrite(OUTPUT_PIN, LOW); //The voltage is set to ~0V for the positive LED lead
  }
}
