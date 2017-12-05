//#define NOW
#ifdef NOW
#ifndef _ANALYZE_C
#define _ANALYZE_C
#include <main.h>

extern evening_struct training[5000];
extern evening_struct testing[5000];
extern total_training_nums;
extern total_testing_nums;

void enlabel_testing_files(int k) {
    for (int i = 280; i < 330; i++) {
        enlabel_a_single_file(&testing[i], k);
    }
}

void enlabel_a_single_file(evening_struct *testing, int k) {
    double* distance = (double*)malloc(sizeof(double)*(k + 1));
    int* places = (int*)malloc(sizeof(int)*(k + 1));
    //*****************这段对前k个值的选取有很大问题，要改**********************************
    for (int i = 0; i < k; i++) {
        distance[i] = cal_distance(*testing, training[i]);
        places[i] = training[i].num;
    }
    for (int i = k; i < total_training_nums; i++) {
        int j = 0;
        for (; j < k; ++j) {
            if (j >= k)j = 0;
            float buf;
            if ((buf = cal_distance(*testing, training[i])) <= distance[j]) {
                distance[j] = buf;
                places[j] = training[i].num;
                break;
            }
        }
    }
    //改好了，mark一下************************************************************
    int guessnumber[10] = { 0,0,0,0,0,0,0,0,0,0 };
    for (int i = 0; i < k; i++) {
        guessnumber[training[places[i]].truelabel]++;
    }
    int max = guessnumber[0];
    int label = 0;
    for (int i = 0; i < 10; i++) {
        if (guessnumber[i] > max) {
            max = guessnumber[i];
            label = i;
        }
    }
    testing->guesslabel = label;
    free(distance);
    distance = NULL;
    free(places);
    places = NULL;
    
}

double cal_rate(void) {
    int right = 0;
    int not_right = 0;
    double right_rate;
    for (int i = 280; i < 330; i++) {
        if (testing[i].guesslabel == testing[i].truelabel) {
            right++;
        }
        else if (testing[i].guesslabel != testing[i].truelabel) {
            not_right++;
        }
    }
    right_rate = 1.0*right / (right + not_right);
    return right_rate;
}

#endif
#endif
