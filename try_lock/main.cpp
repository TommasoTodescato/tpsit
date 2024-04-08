#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

#define CONT (100*1000)

mutex m;
int contatore = 0;
int cock = 0;

void incrementa()
{
    for (int i = 0; i < CONT; i++)
    {
        if(m.try_lock())
        {
            contatore++;
            m.unlock();
        }
        else
            cock++;
    }
}

int main()
{
    thread worker1(incrementa);
    thread worker2(incrementa);
    worker1.join();
    worker2.join();

    cout << contatore << endl;
    cout << cock << endl;
    cout << contatore + cock << endl;

    return 0;
}