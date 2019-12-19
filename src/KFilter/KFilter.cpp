//
// Created by inverse on 19.12.2019.
//

#include "../../include/KFilter/KFilter.h"
#include <iostream>

KFilter::KFilter(GRAPH points) {
    _filtered = points;
}

void KFilter::exec() {
    double average;
    int wSize = _filtered.size() - _size;
    for(int i=0;i<wSize;i++) {
        average = 0.0;
        for(int j=0;j<_size;j++)
        {
            average = coef[j]*(j);
        }

    }
}

void KFilter::setCoeff() {
    coef = new double[30];
    coef[0] = -1.117e-03;
    coef[1] = -3.755e-03;
    coef[2] = -3.029e-03;
    coef[3] = 1.626e-03;
    coef[4] = 7.169e-03;
    coef[5] = 8.126e-03;
    coef[6] = 2.788e-04;
    coef[7] = -1.515e-02;
    coef[8] = -2.968e-02;
    coef[9] = -3.022e-02;
    coef[10] = -5.435e-03;
    coef[11] = 4.702e-02;
    coef[12] = 0.1168;
    coef[13] = 0.1834;
    coef[14] = 0.224;
    coef[15] = 0.224;
    coef[16] = 0.1834;
    coef[17] = 0.1168;
    coef[18] = 4.702e-02;
    coef[19] = -5.435e-03;
    coef[20] = -3.022e-02;
    coef[21] = -2.968e-02;
    coef[22] = -1.515e-02;
    coef[23] = 2.788e-04;
    coef[24] = 8.126e-03;
    coef[25] = 7.169e-03;
    coef[26] = 1.626e-03;
    coef[27] = -3.029e-03;
    coef[28] = -3.775e-03;
    coef[29] = -1.117e-03;
}

void KFilter::setSize(int size) {
    _size = size;
}