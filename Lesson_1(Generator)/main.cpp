#include <cmath>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <cstring>

#include "include/cxxopts.hpp"

using namespace std;

double amplitude;
double fi;
double frequency;
double sampling_frequency;
double delta_t;

string output;

double countable(double time){
	return amplitude * sin( 2 * M_PI * frequency * time + fi);
}

auto parseOptions(int argc, char* argv[]){
    cxxopts::Options options("Generator", "Sin text table generator");
    options.add_options()
        ("a,amplitude", "Amplitude", cxxopts::value<double>()->default_value("2.35"))
        ("p,phase", "Phase", cxxopts::value<double>()->default_value("0.0"))
        ("f,frequency", "Frequency", cxxopts::value<double>()->default_value("1.0"))
        ("s,sampling_frequency", "Sampling frequency", cxxopts::value<double>()->default_value("250.0"))
        ("o,output", "Output file name", cxxopts::value<string>()->default_value("../../output.txt"));

    auto parsedOptions = options.parse(argc, argv);

    amplitude = parsedOptions["amplitude"].as<double>();
    fi = parsedOptions["phase"].as<double>();
    frequency = parsedOptions["frequency"].as<double>();
    sampling_frequency = parsedOptions["sampling_frequency"].as<double>();
    output = parsedOptions["output"].as<string>();
    delta_t = 1/sampling_frequency;

    return parsedOptions;
}

int main(int argc, char* argv[]){
    parseOptions(argc, argv);

	double observation_time = 2.5;
	double time = 0.0;

	ofstream file;
	file.open( output, ios::out );

	if(!file.is_open()){
		cout << "Could not open output.exe" << endl;
		return 1;
	}

	do{
		file << time << ' ' << countable(time) << endl;

		time += delta_t;
	}
	while( time < observation_time );

	return 0;
}
