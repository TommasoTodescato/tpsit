#include <iostream>
#include <list>
#include <thread>
#include <mutex>
#include <vector>
#include <fstream>

#include "dato.h"

using namespace std;

void inserisci_dati();
void leggi_dati();
void scrivi_su_file();

int main()
{
    list<dato> dati(8);
    vector<thread> lettura(8);
    thread scrittura(scrivi_su_file);

    for (int i = 0; i < 8; i++)
    {
        ofstream f("file" + to_string(i));
        f.close();
    }

    for (auto &x : lettura)
        x = thread(leggi_dati);

    return 0;
}