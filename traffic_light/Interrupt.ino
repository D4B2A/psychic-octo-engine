

void setup(){
  pinMode(2,INPUT);
  EICRA |= 3;
  EIMSK &= 254;
}

void loop(){
  if(EIFR&1){
    //do something
    EIFR /= 1; //reset button flag
  }
}


