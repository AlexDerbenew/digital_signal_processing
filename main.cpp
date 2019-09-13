#include <iostream>

#include "point.hpp"
#include "graph.hpp"
#include "cxxopts.hpp"
#include "Generator/FunctionParameters.hpp"
#include "Generator/Generator.hpp"

using namespace std;

FunctionParameters parameters;

auto parseOptions(int argc, char* argv[]){
    cxxopts::Options options("Generator", "Sin function generator and amplitude detector");
    options.add_options()
        ("a,amplitude", "Amplitude", cxxopts::value<double>()->default_value("2.35"))
        ("p,phase", "Phase", cxxopts::value<double>()->default_value("0.0"))
        ("f,frequency", "Frequency", cxxopts::value<double>()->default_value("1.0"))
        ("s,sampling_frequency", "Sampling frequency", cxxopts::value<double>()->default_value("250.0"))
        ("t,observation_time", "Observation time", cxxopts::value<double>()->default_value("2.5"));

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

    GRAPH points;

    Generator generator(parameters);
    points = generator.generateValues();

    AmpDetector detector(points);

    cout << detector.countAmp();

    return 0;
}
