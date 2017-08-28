//
// Created by rahul on 27/8/17.
//
#include "Arduino.h"
#include "Move.h"

char mode = 'A';
Move::Move(uint8_t  leftRed, uint8_t  leftBlack, uint8_t rightRed, uint8_t rightBlack,uint8_t leftSpeedPin, uint8_t rightSpeedPin)
{

    pinMode(leftRed, OUTPUT);
    pinMode(leftBlack, OUTPUT);
    pinMode(rightRed, OUTPUT);
    pinMode(rightBlack, OUTPUT);
    pinMode(leftSpeedPin,OUTPUT);
    pinMode(rightSpeedPin,OUTPUT);
    _leftRed = leftRed;
    _leftBlack = leftBlack;
    _rightRed = rightRed;
    _rightBlack = rightBlack;
    _leftSpeedPin = leftSpeedPin;
    _rightSpeedPin = rightSpeedPin;
    delay(500);
    Serial.println("Library made by Rahul Tripathy.");
    Serial.println("Pin address are in order :- \n left_red \t left_black \t rightRed \t rightBlack \t leftSpeedPin \t rightSpeedPin ");


}

Move::Move(uint8_t leftRed, uint8_t leftBlack, uint8_t rightRed, uint8_t rightBlack,uint8_t leftSpeedPin, uint8_t rightSpeedPin,char _mode )
{
    pinMode(leftRed, OUTPUT);
    pinMode(leftBlack, OUTPUT);
    pinMode(rightRed, OUTPUT);
    pinMode(rightBlack, OUTPUT);
    pinMode(leftSpeedPin,OUTPUT);
    pinMode(rightSpeedPin,OUTPUT);
    _leftRed = leftRed;
    _leftBlack = leftBlack;
    _rightRed = rightRed;
    _rightBlack = rightBlack;
    _leftSpeedPin = leftSpeedPin;
    _rightSpeedPin = rightSpeedPin;
    mode = _mode;
    delay(500);
    Serial.println("Opening in manual mode.....");
    Serial.println("Pin addresses are :- \n left_red \t left_black \t rightRed \t rightBlack \t leftSpeedPin \t rightSpeedPin ");


}

void Move::setSpeed(uint8_t Speed=150, char pin='b')
{		thisSpeed = Speed;
    if (pin == 'l' && mode == 'M')
    {
        analogWrite(_leftSpeedPin,Speed);

    }
    else if ( pin == 'r' && mode == 'M')
    {
        analogWrite(_rightSpeedPin,Speed);
    }
    else if (pin == 'b' && mode =='A')
    {
        analogWrite(_leftSpeedPin,Speed);
        analogWrite(_rightSpeedPin,Speed);
    }
}
void Move::forward()
{
    Serial.println("moving forward");
    this->setSpeed(thisSpeed,'l');
    this->setSpeed(thisSpeed,'r');
    digitalWrite(_leftRed, HIGH);
    digitalWrite(_leftBlack,LOW);
    digitalWrite(_rightRed, HIGH);
    digitalWrite(_rightBlack, LOW);
    delay(10);
}
void Move::backward()
{
    Serial.println("moving backward");
    this->setSpeed(thisSpeed,'l');
    this->setSpeed(thisSpeed,'r');
    digitalWrite(_leftRed, LOW);
    digitalWrite(_leftBlack, HIGH);
    digitalWrite(_rightRed, LOW);
    digitalWrite(_rightBlack, HIGH);
    delay(10);
}
void Move::sharpLeft()
{
    Serial.println("moving sharp left");
    this->setSpeed(thisSpeed,'l');
    this->setSpeed(thisSpeed,'r');
    digitalWrite(_leftRed, LOW);
    digitalWrite(_leftBlack, HIGH);
    digitalWrite(_rightRed, HIGH);
    digitalWrite(_rightBlack, LOW);
    delay(10);
}
void Move::sharpRight()
{
    Serial.println("moving sharp right");
    this->setSpeed(thisSpeed,'l');
    this->setSpeed(thisSpeed,'r');
    digitalWrite(_leftRed, HIGH);
    digitalWrite(_leftBlack, LOW);
    digitalWrite(_rightRed, LOW);
    digitalWrite(_rightBlack, HIGH);
    delay(10);
}
void Move::left()
{
    Serial.println("moving LEFT");
    this->setSpeed(thisSpeed,'l');
    this->setSpeed(thisSpeed,'r');
    digitalWrite(_leftRed, HIGH);
    digitalWrite(_leftBlack, LOW);
    digitalWrite(_rightRed, LOW);
    digitalWrite(_rightBlack, LOW);
    delay(10);
}
void Move::right()
{
    Serial.println("moving RIGHT");
    this->setSpeed(thisSpeed,'l');
    this->setSpeed(thisSpeed,'r');
    digitalWrite(_leftRed, LOW);
    digitalWrite(_leftBlack, LOW);
    digitalWrite(_rightRed, HIGH);
    digitalWrite(_rightBlack, LOW);
    delay(10);
}


void Move::brake()
{
    Serial.println("slowing down...");
    for (uint8_t i = thisSpeed;i>0;i++)
    {
        this->setSpeed(i,'b');

    }
    Serial.println("Stopped");

    digitalWrite(_leftRed, LOW);
    digitalWrite(_leftBlack, LOW);
    digitalWrite(_rightRed, LOW);
    digitalWrite(_rightBlack, LOW);
    delay(10);

}

