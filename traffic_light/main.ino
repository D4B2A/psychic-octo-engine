mask maskArray[14]; //Max 14 Frames => Stack
trafficLight trafficLightArray[8]; //Max 8 TrafficLights => Stack

const phase[][];

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
    
    setFrame(byte GNDpin){
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
        
        
        if((redGround == GNDpin)&&redState){
            *(maskPointer+GNDpin) |= 1<<redPin;
        }
        else if((orangeGround == GNDpin)&&orangeState){
            *(maskPointer+GNDpin) |= 1<<orangePin;
        }
        else if((greenGround == GNDpin)&&greenState){
            *(maskPointer+GNDpin) |= 1<<greenPin;
        }
    }

}

class mask{
    private:
    int mask;
    
    getOnMask(){
        return mask;
    }
    
    getOffMask(){
        return ~mask;
    }
    public:
    
    mask(){ //Constructor dataport => port pointer
    }
    
    applyMask(bool on){
        if(on){
            PORTC |= (getOnMask()>>8)&255;
            PORTD |= getOnMask()&255;
        }
        else {
            PORTC &= (getOffMask()>>8)&255;
            PORTD &= getOffMask()&255;
        }
    }
    
}

void updateFrames(){
    for(int i = 0; i<13; i++){
        for(int j = 0; j < sizeof(trafficLightArray); j++){
            trafficLightArray[j].setFrame(i);
        }
    }
}

void setPhase(byte newphase){
    for(int i = 0; i < sizeof(trafficLightArray);i++){
        trafficLightArray[i].setState(phase[newphase][i]);
    }

void setup(){
    pinMode(2,INPUT);
    EICRA |= 3;
    EIMSK &= 254;
}
