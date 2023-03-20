volatile bool buttonSchedule;

void setup(){
  pinMode(2,INPUT);
  attachInterrupt(ISR,INT0,RISING); //INT0 => pin 2
}

void loop(){
  if(buttonSchedule){
    //do something
  }
}

void ISR(){
  buttonSchedule = true; //Button pressed Flag
}
