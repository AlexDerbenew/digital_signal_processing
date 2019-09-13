#include <cmath>

#include "Generator/Generator.hpp"

using namespace std;

class Generator{
private:
    FunctionParameters _parameters;
    double countValue(double time){
        return this->_parameters.amplitude * sin( 2 * M_PI * this->_parameters.frequency * time + this->_parameters.fi);
    }
public:
    explicit Generator(FunctionParameters parameters) : _parameters(parameters){}
    GRAPH generateValues(){
        GRAPH points;
        double time = 0.0;
        do{
            points.push_back({time,countValue(time)});
            time += this->_parameters.delta_t;
        }
        while( time < this->_parameters.observation_time );
        return points;
    }
};
