
// Main Moisture Detection Program

int SensorRods1 = A5;    // input from first moisture sensor 1
int PulsePin1 = 13;      // Sends a pulse of current to the sensor 1
int SensorRods2 = A4;    // input from second moisture sensor 2
int PulsePin2 = 12;      // Sends a pulse of current to the sensor 2
int ValveOutput1 = 4;    // select the pin for the solenoid valve control (1)
int ValveOutput2 = 8;    // select the pin for the solenoid valve control (2)
int sensorValue1 = 0;    // initial variable to store the value coming from the sensor (1)
int sensorValue2 = 0;    // initial variable to store the value coming from the sensor (2)

void setup() {
  // declare the inputs and outputs:
  pinMode(SensorRods1, INPUT);
  pinMode(PulsePin1, OUTPUT);
  pinMode(SensorRods2, INPUT);
  pinMode(PulsePin2, OUTPUT);
  pinMode(ValveOutput1, OUTPUT);
  pinMode(ValveOutput2, OUTPUT);

  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

void loop() {
  // Provide current to sensor 1 and read the value
  digitalWrite(PulsePin1, HIGH);
  delay(100);
  sensorValue1 = analogRead(SensorRods1);
  delay(100);
  Serial.println(sensorValue1);
  digitalWrite(PulsePin1, LOW);
  delay(250);

  // Provide current to sensor 2 and read the value
  digitalWrite(PulsePin2, HIGH);
  delay(100);
  sensorValue2 = analogRead(SensorRods2);
  delay(100);
  Serial.println(sensorValue2);
  digitalWrite(PulsePin2, LOW);
  delay(250);

  // Evaluate the moisture sensor values and turn on valves as necessary

  if (sensorValue1 >= 680) {
    digitalWrite(ValveOutput1, HIGH);
  }

  if (sensorValue1 < 680) {
    digitalWrite(ValveOutput1, LOW);
  }

  if (sensorValue2 >= 680) {
    digitalWrite(ValveOutput2, HIGH);
  }

  if (sensorValue2 < 680) {
    digitalWrite(ValveOutput2, LOW);
  }

  // Check once every 3 seconds
  delay(3000);

}
