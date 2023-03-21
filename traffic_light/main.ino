volatile bool buttonSchedule = false;

mask maskArray[14]; //Max 14 Frames

class trafficLight {

    private:
    
    byte redPin;
    byte orangePin;
    byte greenPin;

    byte redGround;
    byte orangeGround;
    byte greenGround;
    
    byte state;

    public:
    
    trafficLight(byte red, byte orange, byte green, byte redGnd, byte orangeGnd,byte greenGnd, mask* maskPointer){
        redPin = red;
        orangePin = orange;
        greenPin = green;

        redGround = redGnd;
        orangeGround = orangeGnd;
        greenGround = greenGnd;

        state = 0;
    }
    
    getFrame(byte GNDpin){
        if(redGround == GNDpin){
            *(maskPointer+GNDpin) |= redPin;
        }
        else if(orangeGround == GNDpin){
            *(maskPointer+GNDpin) |= orangePin;
        }
        else if(greenGround == GNDpin){
            *(maskPointer+GNDpin) |= greenPin;
        }
    }

};

class mask{
    private:
    byte mask;
    bool* port;
    
    getOnMask(){
        return mask;
    }
    
    getOfMask(){
        return ~mask;
    }
    public:
    
    mask(bool *dataport){ //Constructor dataport => port pointer
        port = dataport;
    }
    
    applyMask(bool on){
        if(on) *port |= getOnMask();
        else *port &= getOfMask();
    }
    
}


void setup(){
  
}
