volatile bool buttonSchedule = false;

class trafficLight {
private:
  byte down_at;
  byte down;
  
public:
  Button();
  byte downFor();
  void resetDown();
  bool isDown();
  void turnOn();
  void turnOff();
};



void setup(){
  
}
