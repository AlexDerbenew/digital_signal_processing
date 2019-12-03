#include <cmath>

#include "Generator/Generator.hpp"

using namespace std;

double Generator::countValue(double time){
    return this->_parameters.amplitude * sin( 2 * M_PI * this->_parameters.frequency * time + this->_parameters.fi);
}


GRAPH Generator::generateValues(){
    GRAPH points;
    double time = 0.0;
    do{
        points.push_back({time,countValue(time)});
        time += this->_parameters.delta_t;
    }
    while( time < this->_parameters.observation_time );
    return points;
}
