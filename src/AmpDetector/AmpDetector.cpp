#include <cmath>

#include "AmpDetector/AmpDetector.hpp"

using namespace std;

class AmpDetector{
private:
    GRAPH _points;
    float energy(){
        double W = 0.0;
        for( unsigned int i = 0; i < this->_points.size(); i++ ){
            W += this->_points[i].value * this->_points[i].value * 2 * ( M_PI / this->_points.size() );
        }
        return W;
    }
public:
    explicit AmpDetector(GRAPH points) : _points(points){}
    double countAmp(){
        return sqrt(  energy() / M_PI );
    }
};
