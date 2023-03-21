volatile bool buttonSchedule = false;

class trafficLight {
public:
    byte redPin;
    byte orangePin;
    byte greenPin;

    byte redGround;
    byte orangeGround;
    byte greenGround;

    byte state;

    trafficLight(byte red, byte orange, byte green, byte redGnd, byte orangeGnd,byte greenGnd){
        redPin = red;
        orangePin = orange;
        greenPin = green;

        redGround = redGnd;
        orangeGround = orangeGnd;
        greenGround = greenGnd

        state = 0;
    }

};



void setup(){
  
}
