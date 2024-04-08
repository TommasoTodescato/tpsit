#include <iostream>
#include <thread>
#include <fstream>

using namespace std;

#define path "meteo.txt"

void background()
{
    int temperatura = 0;
    for (int i = 0; i < 1000000; i++)
    {
        ifstream fi(path);
        if(!fi.is_open()) return;
        fi >> temperatura;
        fi.close();

        temperatura++;

        ofstream fo(path);
        if(!fo.is_open()) return;
        fo << temperatura;
        fo.close();

        this_thread::sleep_for(10s);
    }
}

int print_from_file()
{
    int temperatura = 0;
    ifstream f(path);
    if (!f.is_open()) return -1;
    f >> temperatura;
    cout << temperatura << endl;
    f.close();

    return 0;
}

int main()
{
    thread bg(background);

    int mod = false;
    while (true)
    {
        cout << "0 - Esci\n1 - Visualizza la temperatura" << endl;
        cin >> mod;
        if(!mod) return 0;

        print_from_file();

    }
    bg.join();

    return 0;
}