#ifndef PARTICULA_H
#define PARTICULA_H


class particula
{
private:
    float pX, pY, vX, vY, aX, aY, masa;
public:
    particula();

    float getPX() const;
    void setPX(float value);

    float getPY() const;
    void setPY(float value);

    float getVX() const;
    void setVX(float value);

    float getVY() const;
    void setVY(float value);

    float getAX() const;
    void setAX(float value);

    float getAY() const;
    void setAY(float value);

    float getMasa() const;
    void setMasa(float value);

    void setAceleration (float aX,float aY);

    void updateposition(float delta);

};

#endif // PARTICULA_H
