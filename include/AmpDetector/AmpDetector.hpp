#ifndef AMPDETECTOR_HPP_INCLUDED
#define AMPDETECTOR_HPP_INCLUDED

#include "point.hpp"
#include "graph.hpp"

using namespace std;

class AmpDetector{
private:
    GRAPH _points;
    float energy();
public:
    explicit AmpDetector(GRAPH points) : _points(points){}
    double countAmp();
};


#endif // AMPDETECTOR_HPP_INCLUDED
