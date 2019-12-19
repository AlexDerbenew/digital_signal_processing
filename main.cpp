#include <iostream>
#include <fstream>

#include "include/point.hpp"
#include "include/graph.hpp"
#include "cxxopts.hpp"
#include "include/Generator/FunctionParameters.hpp"
#include "include/Generator/Generator.hpp"
#include "include/AmpDetector/AmpDetector.hpp"
#include "include/FloatingAverage/FloatingAverage.h"

using namespace std;

FunctionParameters parameters;

auto parseOptions(int argc, char* argv[]){
    cxxopts::Options options("Generator", "Sin function generator and amplitude detector");
    options.add_options()
        ("a,amplitude", "Amplitude", cxxopts::value<double>()->default_value("2.35"))
        ("p,phase", "Phase", cxxopts::value<double>()->default_value("0.0"))
        ("f,frequency", "Frequency", cxxopts::value<double>()->default_value("1.0"))
        ("s,sampling_frequency", "Sampling frequency", cxxopts::value<double>()->default_value("250.0"))
        ("t,observation_time", "Observation time", cxxopts::value<double>()->default_value("4.0"));

    auto parsedOptions = options.parse(argc, argv);

    parameters = {
        parsedOptions["amplitude"].as<double>(),
        parsedOptions["phase"].as<double>(),
        parsedOptions["frequency"].as<double>(),
        parsedOptions["sampling_frequency"].as<double>(),
        parsedOptions["observation_time"].as<double>(),
        (1/parsedOptions["sampling_frequency"].as<double>())
    };
    return parsedOptions;
}

int main(int argc, char* argv[])
{
    parseOptions(argc, argv);
    fstream floating1;

    GRAPH points;
    Generator generator(parameters);
    points = generator.generateValues();

/*    for(auto i = 0;i<points.size();i++) {
        cout << "gen" << points[i].y << endl;
    }*/
    auto floating = new FloatingAverage(points);
    floating->setWindowSize(10);
    floating->exec();
    points = floating->getPoints();

    floating1.open("floating.txt", ios::out);
    for(auto i = 0;i<points.size();i++) {
        floating1 << points[i].y << endl;
    }
    floating1.close();

    AmpDetector detector(points);

    cout << detector.countAmp();

    return 0;
}
