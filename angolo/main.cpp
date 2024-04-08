// Implementare la classe angolo che rappresenta un angolo geometrico espresso in gradi, primi e secondi

/* Specifiche:
 * a) costruttore di default
 * b) costruttore con parametri
 * c) metodo set(int g, int p, int s)
 * d) metodo getGradi()
 * e) metodo getPrimi()
 * f) metodo getSecondi()
 * g) metodo radianti() // converte l'angolo in radianti
*/

#include <iostream>
using namespace std;

#define pi 3.141592653589

class Angolo
{
    int gradi;
    int primi;
    int secondi;

    void set(int g, int p, int s)
    {
        gradi = g;
        primi = p;
        secondi = s;
    }

    int getGradi()
    {
        return gradi;
    }

    int getPrimi()
    {
        return primi;
    }

    int getSecondi()
    {
        return secondi;
    }

    double radianti()
    {
        double fact = pi/180;
        double gradi = (double)gradi + (double)primi/60 + (double)secondi/3600;
        return gradi * fact;
    }

    Angolo(int gradi, int primi, int secondi)
    {
        set(gradi, primi, secondi);
    }

    void stampa()
    {
        cout << gradi << "°" << primi << "'" << secondi << "''" << endl;
    }
};

int main()
{
    cout << "Hello, World!" << endl;
    return 0;
}