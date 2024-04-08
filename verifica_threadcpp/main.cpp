// Todescato Tommaso 26/03/2024
// Verifica TPSIT N.5 - Multithreading

#include <iostream>
#include <fstream>
#include <thread>
#include <mutex>
#include <stack>

// Costanti
#define MAX_NUM 100
#define MAX_SEC 10000
#define MAX_DIST 1000
#define MAX_SPEED 100

// Per evitare cicli infiniti definisco la quantità di iterazioni (arbitraria)
#define LEN 5

using namespace std;

class Corridore
{
public:
    int numero;
    int tempo;
    float dist;
    float speed;

    Corridore()
    {
        srand(time(NULL));
        numero = rand() % MAX_NUM;
        tempo = rand() % MAX_SEC;
        // Genero un int e lo divido per 10 in modo da ottenere un float
        dist =  ((float)(rand()%MAX_DIST) / 10);
        speed = ((float)(rand()%MAX_SPEED) / 10);
    }

    string ToString()
    {
        string res = "Corridore n. " + to_string(numero) +
                "\nTempo: " + to_string(tempo) +
                "\nDistanza:  " + to_string(dist) +
                "\nVelocità: " + to_string(speed) + "\n\n";

        return res;
    }
};

stack<Corridore> corridori;
mutex m1;

void produttore()
{
    // Per non fare andare i thread all'infinito conviene utilizzare un ciclo for
    // LEN definisce quanto il programma va avanti
    for(int i = 0; i < LEN; i++)
    {
        this_thread::sleep_for(1s);

        m1.lock();
        corridori.push(Corridore());
        m1.unlock();
    }
}

void consumatore(int maglia)
{
    // Ogni thread ha il suo numero di maglia che definisce il file su cui scrive
    string nome_file = "Ita"+to_string(maglia)+".txt";
    ofstream f;
    for(int i = 0; i < LEN; i++)
    {
        this_thread::sleep_for(1s);

        m1.lock();
        if (corridori.empty())
        {
            m1.unlock();
            continue;
        }
        Corridore tmp = corridori.top(); corridori.pop();
        f.open(nome_file, ios::app);
        if (!f.is_open())
        {
            cout << "Impossibile aprire il file numero " << maglia << endl;
            m1.unlock();
            continue;
        }

        // Stampo solo se il numero di maglia che cerco è uguale
        // a quello del giocatore che sto leggendo
        if (tmp.numero == maglia)
        {
            cout << tmp.ToString();
            f << tmp.ToString();
        }

        f.close();
        m1.unlock();
    }
}

int main()
{
    thread t_prod(produttore);
    thread cons[4];
    for (int i = 0; i < 4; i++)
        // 10+i include solo da 10 a 13 compresi come numeri di maglia
        cons[i] = thread(consumatore, 10+i);

    // joino tutti i thread
    for (auto & con : cons) con.join();
    t_prod.join();

    return 0;
}