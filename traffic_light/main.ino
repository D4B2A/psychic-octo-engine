volatile bool buttonSchedule = false;

class trafficLight {
public:
    byte redPin;
    byte orangePin;
    byte greenPin;

    byte state;

    trafficLight(byte red, byte orange, byte green){
        redPin = red;
        orangePin = orange;
        greenPin = green;

        state = 0;
    }

};



void setup(){
  
}
