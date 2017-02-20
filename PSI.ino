
void setup() {
  Serial.begin(9600); //Begin serial communication
  pinMode(13, OUTPUT); //Pin for air 
  pinMode(0, INPUT); //Pin for pushbutton
}

void loop() {
  float sensorPressure = analogRead(A5); //Read a value from the pressure sensor
  int buttonState = digitalRead(0); //Pushbutton state value 

  float ATM = (sensorPressure*0.0020408163); //Convert sensorPressure to a pressure in atmospheres
  
  int c = 0.5; 
  float d = 15-c; //We INPUT the distance in feet
  float v = 5.319444444; //The rate of the car in ft/s
  float t = d/v; //Calculate time from distance and speed

  
  float targetATM = (.019457*t+1.0096); //find target pressure in atm using calculated time. Plugs t into pressure vs time graph for rxn


if (buttonState == LOW) { //If the button is pressed
digitalWrite (13, HIGH); //Turn air on 


  if (ATM >= targetATM) //If pressure is greater than or equal to targetATM
  {
    digitalWrite (13, LOW); //Turn air off
  }

  else
  { digitalWrite (13, HIGH); //Keep the air turned on if it hasn't hit targetATM
  }
  
}
}
