//
// Created by inverse on 08.12.2019.
//

#ifndef DSP_FLOATINGAVERAGE_H
#define DSP_FLOATINGAVERAGE_H

#include "../graph.hpp"

class FloatingAverage
{
public:
    FloatingAverage(GRAPH points);
    ~FloatingAverage();
    void setWindowSize(int ws);
    void exec();
    GRAPH getPoints() { return _points;}
private:
    GRAPH _points;
    int _windowSize;
};


#endif //DSP_FLOATINGAVERAGE_H
