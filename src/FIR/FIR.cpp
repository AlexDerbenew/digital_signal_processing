//
// Created by inverse on 19.12.2019.
//

#include "../../include/FIR/FIR.h"
#include <iostream>

FIR::FIR(GRAPH points) {
    _source = points;
    this->setCoeff();
}

void FIR::exec() {
    double average;
    for(int i=0;i<_source.size();i++) {
        average = 0.0;
        for(int j=0;j<_windowSize;j++)
        {
            average += coef[j]*(_source[i+j].y);
        }
        _source[i].y = average;
    }
}



/*
void TAwesomeFiltr::exec()
{
    double averedge;
    for (int i = 0; i<_formedSignalLine->getWindowSize(); i++)
    {
        averedge = 0.0;
        for(int j = 0; j<_formedSize;j++)
        {
//            printf("Koef[%d] = %f \n",j,KOFS[j]);
//            printf("Point = %d \n", ((*(_alphaSignalLine->getLast()-(i+j)))));
            averedge += KOFS[j] * ((*(_alphaSignalLine->getLast()-(i+j)))* 1.0);
        }
        *(_formedSignalLine->getLast()-i) = averedge ;
//        sleep(2);
    }
}
*/


void FIR::setSize(int size) {
    _windowSize = size;
    _sourceSize = _source.size();
    _filteredSize = _sourceSize - _windowSize;
}

void FIR::setCoeff() {
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

