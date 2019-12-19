//
// Created by inverse on 19.12.2019.
//

#ifndef DSP_FIR_H
#define DSP_FIR_H

#include "../graph.hpp"

class FIR {
public:
    FIR(GRAPH points, );
    void setCoeff();
    void setSize(int size);
    void exec();
    GRAPH getFilteredElements() { return _source;}
private:
    GRAPH _source;
    GRAPH _filtered;
    double *coef;
    int _sourceSize;
    int _filteredSize;
    int _windowSize;
    int _sampleRate;
};

#endif //DSP_KFILTER_H
