

void setup(){
  pinMode(2,INPUT);
  EIMSK &= 254; //Disable Interrupt before changing Trigger
  EICRA |= 3;

}

void loop(){
  if(EIFR&1){
    //do something
    EIFR |= 1; //reset button flag
  }
}


