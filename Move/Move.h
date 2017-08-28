//
// Created by rahul on 27/8/17.
//

#ifndef CLIONARDUINO_MOVE_H
#define CLIONARDUINO_MOVE_H

class Move{

public:
    //constructors--------
    Move(uint8_t leftRed,uint8_t leftBlack,uint8_t rightRed,uint8_t rightBlack,uint8_t leftSpeedPin,uint8_t rightSpeedPin);
    Move(uint8_t leftRed, uint8_t leftBlack, uint8_t rightRed, uint8_t rightBlack,uint8_t leftSpeedPin, uint8_t rightSpeedPin,char _mode );

    // navigation's function
    void forward();
    void backward();
    void sharpLeft();
    void sharpRight();
    void left();
    void right();
    void brake();
    void setSpeed(uint8_t Speed,char pin);
    uint8_t getSpeed();
private:
    // defining pins
    uint8_t _leftRed, _leftBlack, _rightRed, _rightBlack,_leftSpeedPin,_rightSpeedPin;
    // defining other variables
    uint8_t _Speed,_pin,thisSpeed=150;

};

#endif //CLIONARDUINO_MOVE_H
