
/*
  Plays a tone on an Arduino buzzer when a button is pressed

  The button should be connected to pin 3

  The buzzer should be connected to pin 8

  The sound played is a middle C, also known as C4, which has a frequency of ~262Hz

  This example code is modified from the Arduino public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/toneMelody

*/

const int INPUT_PIN = 3;  //This is the pin where the input signal from the button goes
//This is actually a *digital* input pin

const int OUTPUT_PIN = 8;  //This is the pin where the output into the LED goes
//This is actually an *analog* write pin

int buttonRead = 0;  //This variable allows us to store whether the button is pressed or not

void setup() {

  pinMode(INPUT_PIN, INPUT_PULLUP);  //Sets the input pin to be an input
  //Note: don't worry about what "pullup" means for now
}

void loop() {
  buttonRead = digitalRead(INPUT_PIN);  //Reads whether the button is on or off based on the voltage going into the pin

  if (buttonRead == LOW) {

    tone(OUTPUT_PIN, 262);

  }

  else {
    noTone(OUTPUT_PIN);
    buttonRead = digitalRead(INPUT_PIN);
  }
}
