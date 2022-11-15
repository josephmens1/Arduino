// Arduino-project1
// Ultrasonic sensor interfacing with ESP 8266mod

/* Ultrasonic Sensor HC-SR04 interfacing with ESP8266 */

/* Define the names for ESP8266 pin for HC-SR04*/

int trigger_pin = 12;

int Echo_pin = 14;

/* two variables to store duration and distance value */

long duration;
int distance;
//const_speed = 34000 m/s * 10^-6 ; 0.034 m/microsecond

/* configure D5 and D6 as digital input and output respectively */
void setup() {

  /* Ultrasonic Sensor: */

  pinMode(12, OUTPUT); // configure the trigger_pin(D6) as an Output
  pinMode(14, INPUT); // configure the Echo_pin(D5) as an Input
  Serial.begin(9600); // Enable the serial with 9600 baud rate
}

void loop() {

  /* Ultrasonic sensor*/

  digitalWrite(12, LOW); //set trigger signal low for 2us
  delay(2);

  /*send 10 microsecond pulse to trigger pin of HC-SR04 */

  digitalWrite(12, HIGH);  // make trigger pin active high
  delay(10);            // wait for 10 microseconds
  digitalWrite(12, LOW);   // make trigger pin active low

  /*Measure the Echo output signal duration or pulse width */

  duration = pulseIn(Echo_pin, HIGH); // save time duration value in "duration variable
  distance = duration * 0.034 / 2; //Convert pulse duration into distance

  Serial.print("DISTANCE:");
  Serial.print(distance);
  Serial.println(" cm ");
  delay(500);
}
