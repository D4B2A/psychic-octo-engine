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
        bool redState = false;
        bool orangeState = false;
        bool greenState = false;
        
        switch(state){
            case 0:
                redState = true;
                break:
            case 1:
                redState = true;
                orangeState = true;
                break;
            case 2:
                orangeState = true;
                break;
            case 3:
                greenState = true;
                break;
        }
        
        
        if((redGround == GNDpin)&redState){
            *(maskPointer+GNDpin) |= 1<<redPin;
        }
        else if((orangeGround == GNDpin)&orangeState){
            *(maskPointer+GNDpin) |= 1<<orangePin;
        }
        else if((greenGround == GNDpin)&greenState){
            *(maskPointer+GNDpin) |= 1<<greenPin;
        }
    }

}

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
