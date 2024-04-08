#ifndef DRONE_DATO_H
#define DRONE_DATO_H

#include <string>
#define CS
using namespace std;

class dato{
private:
    int n_drone;
    float lat;
    float lon;
    int alt;

public:
    dato();
    dato(int nD, float lat1, float lon1, int alt1);
    int get_n_drone();
    int get_lat();
    int get_lon();
    int get_alt();
};

#endif