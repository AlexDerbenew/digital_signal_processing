#ifndef GENERATOP_HPP_INCLUDED
#define GENERATOP_HPP_INCLUDED

#include <cmath>

#include "point.hpp"
#include "graph.hpp"
#include "Generator/FunctionParameters.hpp"

using namespace std;

class Generator{
private:
    FunctionParameters _parameters;
    double countValue(double time);
public:
    explicit Generator(FunctionParameters parameters) : _parameters(parameters){}
    GRAPH generateValues();
};


#endif // GENERATOP_HPP_INCLUDED
