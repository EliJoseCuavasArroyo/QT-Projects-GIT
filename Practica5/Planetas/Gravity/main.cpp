#include <fstream>
#include <iostream>
#include <exception>
#include <math.h>
#include <string>
#include <vector>

#define PI 3.14159265

#include "particula.h"

using namespace std;

float distanceBetweenParticles(particula particula1, particula particula2);
float ForceBetweenParticles(particula particula1, particula particula2);
float AngleBetweenParticles(particula particula1, particula particula2);

int main()
{
    vector<particula> Particles; // Vector con las particulas que se van a trabajar
    float Fx, Fy, F;

    /*   Para el Ejemplo 1

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


    */


    particula particle1;
    particle1.setMasa(50000);
    particle1.setPX(0);
    particle1.setPY(0);
    particle1.setVX(0);
    particle1.setVY(0);

    particula particle2;
    particle2.setMasa(70);
    particle2.setPX(-5000);
    particle2.setPY(0);
    particle2.setVX(0);
    particle2.setVY(-2);

    particula particle3;
    particle3.setMasa(70);
    particle3.setPX(5000);
    particle3.setPY(0);
    particle3.setVX(0);
    particle3.setVY(2);

    particula particle4;
    particle4.setMasa(70);
    particle4.setPX(0);
    particle4.setPY(-5000);
    particle4.setVX(2);
    particle4.setVY(0);

    particula particle5;
    particle5.setMasa(70);
    particle5.setPX(0);
    particle5.setPY(5000);
    particle5.setVX(-2);
    particle5.setVY(0);

    Particles.push_back(particle1);
    Particles.push_back(particle2);
    Particles.push_back(particle3);
    Particles.push_back(particle4);
    Particles.push_back(particle5);

    string name_file;
    cout << "Ingrese el nombre del archivo de texto: " << endl;
    cin >> name_file;

    // Abrimos el archivo de texto que procedemos a codificar.

    ofstream File;
    File.open(name_file);

    if(File.fail()){
        cout << "Error al abrir el archivo de lectura de las palabras" << endl;
        return -1;
    }

    for (unsigned int iter = 0; iter < 10000 ; iter++){


        for(unsigned int i = 0; i < Particles.size(); i++){

            File << " || " << Particles[i].getPX() << "   " << Particles[i].getPY() << " || ";
        }
            File << endl;

        for(unsigned int i = 0; i < Particles.size(); i++){
            F = 0;
            Fx = 0;
            Fy = 0;
            for (unsigned int j = 0; j < Particles.size(); j++){
                if (i != j){
                    F = ForceBetweenParticles(Particles[i], Particles[j]); // Fuerza entre las particulas.
                    Fx = Fx+(F)*cos(AngleBetweenParticles(Particles[i], Particles[j])); // Fuerza en el eje X de la particula i.
                    Fy = Fy+(F)*sin(AngleBetweenParticles(Particles[i], Particles[j])); // Fuerza en el eje Y de la particula i.
                }
            }
            Particles[i].setAceleration((Fx/(Particles[i].getMasa())), (Fy/(Particles[i].getMasa()))); // Le asignamos las aceleraciones respectivas en su intervalo de tiempo.
        }

        for(unsigned int i = 0; i < Particles.size(); i++) // Actualizamos sus posiciones y velocidad.
        {
            Particles[i].updateposition(1); // Actualizacion con un delay de 1 segundo.
        }

    }
    File.close();
    return 0;
}

float distanceBetweenParticles(particula particula1, particula particula2) // Distancia entre particulas.
{
    return sqrt((pow(particula1.getPX()-particula2.getPX(), 2))+(pow(particula1.getPY()-particula2.getPY(), 2)));
}

float AngleBetweenParticles(particula particula1, particula particula2) // Angulo entre las pariculas, respecto a la particula 1.
{
    return atan2((particula2.getPY()-particula1.getPY()),(particula2.getPX()-particula1.getPX()));
}

float ForceBetweenParticles(particula particula1, particula particula2) // Fuerza entre particulas.
{
    return (((particula1.getMasa())*(particula2.getMasa()))/pow(distanceBetweenParticles(particula1, particula2), 2));
}


