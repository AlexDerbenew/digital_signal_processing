//
// Created by inverse on 19.12.2019.
//

#ifndef DSP_KFILTER_H
#define DSP_KFILTER_H

#include "../graph.hpp"

class KFilter {
public:
    KFilter(GRAPH points);
    void setCoeff();
    void setSize(int size);
    void exec();
    GRAPH getFilteredElements() { return _filtered;}
private:
    GRAPH _filtered;
    double *coef;
    int _size;
};

#endif //DSP_KFILTER_H
