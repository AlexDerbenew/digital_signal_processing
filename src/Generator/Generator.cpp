#include <cmath>
#include <fstream>

#include "../../include/Generator/Generator.hpp"
#include <iostream>

using namespace std;

double Generator::countValue(double time){
    return this->_parameters.amplitude * sin( 2 * M_PI * this->_parameters.frequency * time + this->_parameters.fi);
}


GRAPH Generator::generateValues(){
    GRAPH points;
    fstream file;
    double time = 0.0;
    file.open("generated.txt", ios::out);
    do{
        points.push_back({time,countValue(time)});
        file << countValue(time) << endl;
        time += this->_parameters.delta_t;
    }
    while( time < this->_parameters.observation_time );
    file.close();
    return points;
}
