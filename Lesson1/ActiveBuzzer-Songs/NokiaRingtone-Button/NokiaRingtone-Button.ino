/*
  Melody

  Plays a melody

  circuit:
  - 8 ohm speaker on digital pin 8

  created 21 Jan 2010
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/toneMelody

  Credit for songs goes to: 
  https://github.com/hibit-dev/buzzer
*/

#include "pitches.h"


const int INPUT_PIN = 3;  //This is the pin where the input signal from the button goes
//This is actually a *digital* input pin

const int OUTPUT_PIN = 8;  //This is the pin where the output into the LED goes
//This is actually an *analog* write pin

int buttonRead = 0;  //This variable allows us to store whether the button is pressed or not


// notes in the melody:
int melody[] = {
  NOTE_E5, NOTE_D5, NOTE_FS4, NOTE_GS4, 
  NOTE_CS5, NOTE_B4, NOTE_D4, NOTE_E4, 
  NOTE_B4, NOTE_A4, NOTE_CS4, NOTE_E4,
  NOTE_A4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  8, 8, 4, 4,
  8, 8, 4, 4,
  8, 8, 4, 4,
  2
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
      tone(OUTPUT_PIN, melody[thisNote], noteDuration);

      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      // stop the tone playing:
      noTone(OUTPUT_PIN);
    }
  }
  else {
    buttonRead = digitalRead(INPUT_PIN);
  }
}
