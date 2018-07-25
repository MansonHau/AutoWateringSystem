/*
Timer control for Automatic Watering System
*/

#include <DS3231.h>
#include <Wire.h>

DS3231 Clock;
bool Century=false;
bool h12;
bool PM;
byte ADay, AHour, AMinute, ASecond, ABits;
bool ADy, A12h, Apm;

byte year, month, date, DoW, hour, minute, second;
int outputPin = 7;
int controlPin = 2;

void setup() {
	// Start the I2C interface
	Wire.begin();
        Clock.setSecond(50);//Set the second 
        Clock.setMinute(22);//Set the minute 
        Clock.setHour(19);  //Set the hour 
        Clock.setDoW(4);    //Set the day of the week
        Clock.setDate(25);  //Set the date of the month
        Clock.setMonth(7);  //Set the month of the year
        Clock.setYear(18);  //Set the year (Last two digits of the year)
	// Start the serial interface
	Serial.begin(115200);

  pinMode(outputPin, OUTPUT);
  pinMode(controlPin, INPUT);
}
void ReadDS3231()
{
  int second,minute,hour,date,month,year,temperature; 
  second=Clock.getSecond();
  minute=Clock.getMinute();
  hour=Clock.getHour(h12, PM);
  date=Clock.getDate();
  month=Clock.getMonth(Century);
  year=Clock.getYear(); 
  
}
void loop() {ReadDS3231();delay(1000);
	// send what's going on to the serial monitor.
	// Start with the year
	Serial.print("2");
	if (Century) {			// Won't need this for 89 years.
		Serial.print("1");
	} else {
		Serial.print("0");
	}
	Serial.print(Clock.getYear(), DEC);
	Serial.print('-');
	// then the month
	Serial.print(Clock.getMonth(Century), DEC);
	Serial.print('-');
	// then the date
	Serial.print(Clock.getDate(), DEC);
	Serial.print(' ');
	// and the day of the week
	Serial.print(Clock.getDoW(), DEC);
	Serial.print(' ');
	// Finally the hour, minute, and second
	Serial.print(Clock.getHour(h12, PM), DEC);
	Serial.print(':');
	Serial.print(Clock.getMinute(), DEC);
	Serial.print(':');
	Serial.print(Clock.getSecond(), DEC);
 
	Serial.print('\n');
  second = Clock.getSecond();
  Serial.print(second);
  Serial.print('\n');
  hour = Clock.getHour(h12, PM);
  Serial.print(hour);
  Serial.print('\n');
  int control = digitalRead(controlPin);
  if (control == HIGH) {
     digitalWrite(outputPin, HIGH);
     Serial.print('\n');
     Serial.print("Remote signal received.");
     }
  else
    if ((second > 3) && (second < 15)) {
       digitalWrite(outputPin, HIGH);  }
    else
       digitalWrite(outputPin, LOW);
  
  }


