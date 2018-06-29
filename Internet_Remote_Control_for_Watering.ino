
// ESP control pin on digital pin 2
int ESPInput = 2;
// Valve output in on digital pin 4
int ValveOutput = 4;


void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // Read incoming command from the ESP:
  pinMode(ESPInput, INPUT);
  // Control this:
  pinMode(ValveOutput, OUTPUT);
}

void loop() {
  // read the input pin:
  int buttonState = digitalRead(ESPInput);
  // print out the state of the input:
  Serial.println(buttonState);
  // set output accordingly
  digitalWrite(ValveOutput, buttonState);
  delay(250);        // reading every 250ms
}
