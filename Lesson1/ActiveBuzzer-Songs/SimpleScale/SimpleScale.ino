void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  //The "tone()" function takes in these parameters, 
  //1. The pin on which the tone is being played
  //2. The frequency of the tone
  //3. The length of the tone in milliseconds
  //So to play a middle C note on pin 8 for 1 second one would write: "tone(8,262,1000);"
  //Other frequencies can be found at: https://pages.mtu.edu/~suits/notefreqs.html

  //This code plays a C major scale, starting with Middle C, otherwise known as C4

  tone(8,262,1000);
  tone(8,294,1000);
  tone(8,330,1000);
  tone(8,350,1000);
  tone(8,392,1000);
  tone(8,440,1000);
  tone(8,494,1000);
  tone(8,523,1000);

  //This just waits 3 seconds (3000ms) between each repetition of the scale
  delay(3000);
}
