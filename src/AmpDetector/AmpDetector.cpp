#include <cmath>

#include "AmpDetector/AmpDetector.hpp"

using namespace std;

float AmpDetector::energy(){
    double W = 0.0;
    for( unsigned int i = 0; i < this->_points.size(); i++ ){
        W += this->_points[i].y * this->_points[i].y * 2 * ( M_PI / this->_points.size() );
    }
    return W;
}

double AmpDetector::countAmp(){
    return sqrt(  energy() / M_PI );
}
