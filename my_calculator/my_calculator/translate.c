//#define NOW
#ifdef NOW
#ifndef _TRAHSLATE_C
#define _TRAHSLATE_C
#include <main.h>
extern evening_struct training[5000];
extern evening_struct testing[5000];
extern total_training_nums;
extern total_testing_nums;
double cal_distance(evening_struct structA, evening_struct structB) {
    double distance=0;
    double linedistance[MAX_LINE] = { 0 };
    int line = 0;
    for (line = 0;line < 32; line++) {
        for (int raw = 0;raw < 32; raw++) {
            linedistance[line] += pow((structA.place[line][raw] - structB.place[line][raw]), 2);
        }
        linedistance[line] = sqrt(linedistance[line]);
        distance += linedistance[line];
    }
    distance /= line;
    return distance;
}

#endif
#endif
