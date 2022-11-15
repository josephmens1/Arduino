// Arduino-project
//Keypad and buzzer interfacing with ESP 8266mod.

/* Keypad interfacing with ESP 8266*/

/* initializing keypad libraries*/
#include <Key.h>
#include <Keypad.h>

/*declare a variable to store the number of lines and another for the number of columns for the  keypad.*/ 
const byte num_rows = 4;
const byte num_cols = 3;
String pass = "";

const int buzzer = D8;

/*declare a char matrix with the same size of our keypad(4rows and 4 columns)*/
char keys[num_rows][num_cols] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};

/* declare two byte arrays, which will contain the pins of the NodeMCU that are connected to the rows and the columns of our keypad.*/
byte colPins[num_cols] = {14,12,13};
byte rowPins[num_rows] = {5,4,0,2};

Keypad myKeypad = Keypad( makeKeymap(keys), rowPins, colPins, num_rows, num_cols); 



void setup() {
  // put your setup code here, to run once:

/* Keypad: simply set a serial connection to output results of code*/
Serial.begin(115200); // Enable the serial with 115200 baud rate
Serial.print("Enter Passcode: \n");
pinMode(buzzer, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

/* call the getKey method of the class Keypad to get a char corresponding to the key pressed.*/
char myKey = myKeypad.getKey();

 if (myKey != NULL){
  Serial.println(myKey);
  pass += myKey;
  Serial.println(pass);

  if ((String(myKey).equals("#")) && ( pass.length() >= 5 )){
    // Serial.println(pass.indexOf("#"));
    pass = pass.substring(pass.indexOf("#")-4,pass.indexOf("#"));
    Serial.println(pass);
    if(pass.equals("2186")){
      digitalWrite(buzzer, HIGH);
      delay(500);
      digitalWrite(buzzer, LOW);
      
    }
   
  }
}
