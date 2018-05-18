#include <fstream>
#include <iostream>
#include <exception>
#include <math.h>
#include <vector>

#define PI 3.14159265

#include "particula.h"

using namespace std;

float distanceBetweenParticles(particula particula1, particula particula2);
float ForceBetweenParticles(particula particula1, particula particula2);
float AngleBetweenParticles(particula particula1, particula particula2);

int main()
{
    vector<particula> Particles;
    float Fx, Fy, F;

    particula particle1;
    particle1.setMasa(70);
    particle1.setPX(0);
    particle1.setPY(-7000);
    particle1.setVX(2);
    particle1.setVY(0);

    particula particle2;
    particle2.setMasa(70000);
    particle2.setPX(0);
    particle2.setPY(0);
    particle2.setVX(0);
    particle2.setVY(0);

    particula particle3;
    particle3.setMasa(25);
    particle3.setPX(4000);
    particle3.setPY(5000);
    particle3.setVX(-1.6);
    particle3.setVY(1.2);

    Particles.push_back(particle1);
    Particles.push_back(particle2);
    Particles.push_back(particle3);

    for (unsigned int iter = 0; iter < 30 ; iter++){

        for(unsigned int i = 0; i < Particles.size(); i++){
            cout << " || " << Particles[i].getPX() << "   " << Particles[i].getPY() << " || ";
        }

        cout << endl;

        for(unsigned int i = 0; i < Particles.size(); i++){
            F = 0;
            Fx = 0;
            Fy = 0;
            for (unsigned int j = 0; j < Particles.size(); j++){
                if (i != j){
                    F = ForceBetweenParticles(Particles[i], Particles[j]);
                    /*
                    if ((i == 1)&&(iter == 1)){
                        cout << "Masa: " << Particles[j].getMasa() << endl;
                        cout << "Fneta: " << F << endl;
                        cout << "Angulo: " <<  AngleBetweenParticles(Particles[i], Particles[j])  << endl;
                        cout << "Angulo: " << ( AngleBetweenParticles(Particles[i], Particles[j]) )*(180/PI) << endl;
                        cout << "El Coseno del angulo: "<< cos(AngleBetweenParticles(Particles[i], Particles[j])) << endl;
                        cout << "El Seno del angulo: "<< sin(AngleBetweenParticles(Particles[i], Particles[j])) << endl;
                        cout << "En X: "<< (F)*cos(AngleBetweenParticles(Particles[i], Particles[j])) << endl;
                        cout << "En Y: "<< (F)*sin(AngleBetweenParticles(Particles[i], Particles[j])) << endl;
                        cout << "FX: " << Fx << endl;
                        cout << "FY: " << Fy << endl;
                        cout << endl;
                    }
                    */
                    Fx = Fx+(F)*cos(AngleBetweenParticles(Particles[i], Particles[j]));
                    Fy = Fy+(F)*sin(AngleBetweenParticles(Particles[i], Particles[j]));
                }
            }
            Particles[i].setAceleration((Fx/(Particles[i].getMasa())), (Fy/(Particles[i].getMasa())));
        }

        for(unsigned int i = 0; i < Particles.size(); i++){
            Particles[i].updateposition(1);
        }

    }

    return 0;
}

float distanceBetweenParticles(particula particula1, particula particula2)
{
    return sqrt((pow(particula1.getPX()-particula2.getPX(), 2))+(pow(particula1.getPY()-particula2.getPY(), 2)));
}

float AngleBetweenParticles(particula particula1, particula particula2)
{
    return atan2((particula2.getPY()-particula1.getPY()),(particula2.getPX()-particula1.getPX()));
}

float ForceBetweenParticles(particula particula1, particula particula2)
{
    return (((particula1.getMasa())*(particula2.getMasa()))/pow(distanceBetweenParticles(particula1, particula2), 2));
}
