/*
  Morse Code

  Plays "Hello World!" in Morse Code when a button is pressed

  Circuitry:
  1 x active buzzer connected to pin 8 and ground
  1 x push button connected to pin 3 and ground

  This code is modified from:

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/toneMelody

*/

const int INPUT_PIN = 3;  //This is the pin where the input signal from the button goes
//This is actually a *digital* input pin

const int OUTPUT_PIN = 8;  //This is the pin where the output into the LED goes
//This is actually an *analog* write pin

int buttonRead = 0;  //This variable allows us to store whether the button is pressed or not

double speedFactor = 2.0; //This variable controls how long your message is. The higher this number, the longer each tone is.

/* 

  No array of notes is needed because the code recognizes a rest as a note of a length other than 4 or 8, meaning that for these lengths noTone(); is played.

*/

// note durations: 4 = short sound, 12 = long sound,
// 5 = rest between sounds in same letter, 13 = rest between letters, 28 = rest between words
int noteDurations[] = {

  //This first portion signals "Hello"
  4, 5, 4, 5, 4, 5, 4,   //H -> ". . . ."
  13,                    //intra-letter rest
  4,                     //e -> "."
  13,                    //intra-letter rest
  4, 5, 12, 5, 4, 5, 4,  //l -> ". - . ."
  13,                    //intra-letter rest
  4, 5, 12, 5, 4, 5, 4,  //l -> ". - . ."
  13,                    //intra-letter rest
  12, 5, 12, 5, 12,      //o -> "- - -"

  //This second portion signals the inter-word rest
  28,  //inter-word rest

  //This third portion signals "World"
  4, 5, 12, 5, 12,       //W -> ". - -"
  13,                    //intra-letter rest
  12, 5, 12, 5, 12,      //o -> "- - -"
  13,                    //intra-letter rest
  4, 5, 12, 5, 4,        //r -> ". - ."
  13,                    //intra-letter rest
  4, 5, 12, 5, 4, 5, 4,  //l -> ". - . ."
  13,                    //intra-letter rest
  12, 5, 4, 5, 4,        //d -> "- . ."

  //This final portion signals "!" (no rest is needed)
  13,                                  //intra-letter rest
  12, 5, 4, 5, 12, 5, 4, 5, 12, 5, 12  //! -> "- . - . - -"
};


int const lengthArr = sizeof(noteDurations) / sizeof(noteDurations[0]);  //This is the same thing as the size of the array in the memory (EEPROM) divided by the size of each element, giving the total amount of elements
//C++ uses array as convenient ways to point to memory locations, this is a low-level programming language

void setup() {

  pinMode(INPUT_PIN, INPUT_PULLUP);  //Sets the input pin to be an input
  //Note: don't worry about what "pullup" means for now
}

void loop() {

  buttonRead = digitalRead(INPUT_PIN);  //Reads whether the button is on or off based on the voltage going into the pin

  if (buttonRead == LOW) {
    // iterate over the notes of the melody:
    for (int thisNote = 0; thisNote < lengthArr; thisNote++) {

      // to calculate the note duration, take one second divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / noteDurations[thisNote];

      if (noteDurations[thisNote] == 4 || noteDurations[thisNote] == 12) { //This plays only if the length of the note is the length of one of the sounds
        tone(OUTPUT_PIN, 262); //outputs a middle C/C4 for the indicated length
        delay(1000/noteDurations[thisNote]*speedFactor);
        noTone(OUTPUT_PIN);
      }

      else { //If the length of the note is NOT one of the ones recognized as a buzz
        noTone(OUTPUT_PIN); 
        delay(1000/noteDurations[thisNote]*speedFactor);
      }
    }
  } else {
    buttonRead = digitalRead(INPUT_PIN);
  }
}
