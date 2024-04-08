#include <iostream>
#include <thread>
#include <mutex>

using namespace std;
int a;

int main()
{
    threads[i] = thread(inc);
    thread threads[10];
    for (int i=0; i<10; ++i) {
    }

    for (int i=0; i<10; ++i) {
        threads[i].join();
    }

    return 0;
}

void inc()
{
    m.lock();
    a++;
    cout << this_thread::get_id() << " " << a << '\n';
    m.unlock();
}

mutex m;