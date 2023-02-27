//These are the pins used for the PWM controlled LEDS

const int LED_1 = 9;

const int LED_2 = 10;

const int LED_3 = 11;

const double voltage = 3.0;  //This is the max voltage that the LEDs need

const int MAX_PWM = (int)(voltage * 51);  //This is because the voltage that you want is (voltage)*255/5 for a PWM Arduino signal, or just (voltage)*51

const int delay_time = 3; //How much time in milliseconds it is between each change in LED brightness

void setup() {

  /* sets the pins to be outputs */
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
}

void loop() {

  //This code goes through every LED one by one making it go from bright to dark, and back to bright again

  //Sets all LEDs to be off
  analogWrite(LED_1, 0);
  analogWrite(LED_2, 0);
  analogWrite(LED_3, 0);

  //Turns the first LED from 0 brightness to full
  for (int i = 0; i < MAX_PWM; i = i + 1) {
    analogWrite(LED_1, i);  //Sets the LED brightness to the current value of i
    delay(delay_time);               //Has a delay of length "delay_time" in millisecond between brightness changes
  }

  //Turns the first LED back down to 0 brightness from full
  for (int i = MAX_PWM; i >= 0; i = i - 1) {
    analogWrite(LED_1, i);  //Sets the LED brightness to the current value of i
    delay(delay_time);               //Has a delay of length "delay_time" in millisecond between brightness changes
  }

  //Turns the second LED from 0 brightness to full
  for (int i = 0; i < MAX_PWM; i = i + 1) {
    analogWrite(LED_2, i);  //Sets the LED brightness to the current value of i
    delay(delay_time);               //Has a delay of length "delay_time" in millisecond between brightness changes
  }

  //Turns the second LED back down to 0 brightness from full
  for (int i = MAX_PWM; i >= 0; i = i - 1) {
    analogWrite(LED_2, i);  //Sets the LED brightness to the current value of i
    delay(delay_time);               //Has a delay of length "delay_time" in millisecond between brightness changes
  }

  //Turns the third LED from 0 brightness to full
  for (int i = 0; i < MAX_PWM; i = i + 1) {
    analogWrite(LED_3, i);  //Sets the LED brightness to the current value of i
    delay(delay_time);               //Has a delay of length "delay_time" in millisecond between brightness changes
  }

  //Turns the third LED back down to 0 brightness from full
  for (int i = MAX_PWM; i >= 0; i = i - 1) {
    analogWrite(LED_3, i);  //Sets the LED brightness to the current value of i
    delay(delay_time);               //Has a delay of length "delay_time" in millisecond between brightness changes
  }

  //This line simply puts a small 1 second delay between each cycle
  delay(1000);
}
