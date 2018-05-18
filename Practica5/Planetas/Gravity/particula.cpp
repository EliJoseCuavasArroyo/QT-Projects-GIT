#include "particula.h"
#include <iostream>

using namespace std;

particula::particula()
{

}

float particula::getMasa() const
{
    return masa;
}

void particula::setMasa(float value)
{
    masa = value;
}

float particula::getPX() const
{
    return pX;
}

void particula::setPX(float value)
{
    pX = value;
}

float particula::getPY() const
{
    return pY;
}

void particula::setPY(float value)
{
    pY = value;
}

float particula::getVX() const
{
    return vX;
}

void particula::setVX(float value)
{
    vX = value;
}

float particula::getVY() const
{
    return vY;
}

void particula::setVY(float value)
{
    vY = value;
}

float particula::getAX() const
{
    return aX;
}

void particula::setAX(float value)
{
    aX = value;
}

float particula::getAY() const
{
    return aY;
}

void particula::setAY(float value)
{
    aY = value;
}

void particula::setAceleration(float aX, float aY)
{
    this->setAX(aX);
    this->setAY(aY);
}

void particula::updateposition(float delta)
{
    this->setVX(this->getAX()*delta + this->getVX());
    this->setVY(this->getAY()*delta + this->getVY());

    this->setPX(this->getVX()*delta + this->getPX() + this->getAX()*delta*delta/2.0);
    this->setPY(this->getVY()*delta + this->getPY() + this->getAY()*delta*delta/2.0);
}
