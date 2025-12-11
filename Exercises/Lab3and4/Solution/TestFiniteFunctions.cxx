#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <fstream>
#include <sstream>
#include "FiniteFunctions.h"
#include <filesystem>
#include "CustomFunctions.h"
#include "Distribution.h"

int main() {
    std::string data_path = "/workspaces/SUPACPP_Labs/Exercises/Lab3and4/Solution/Outputs/data/MysteryData14101.txt";
    std::vector<double> data_point;
    read_data_file(data_path, data_point);
    double sigma=  0.0;
    double mean= 0.0;

    std::string outfile = "/workspaces/SUPACPP_LabsExercises/Lab3and4/Solution";

    double min = *std::min_element(data_point.begin(), data_point.end());
    double max = *std::max_element(data_point.begin(), data_point.end());
    
    sigma = standard_deviation(data_point);
    mean = mean_(data_point);
    std::cout<<mean<<"   "<<sigma<<std::endl;
    FiniteFunction fin;
    fin.setRangeMin(min);
    fin.setRangeMax(max);
    fin.setOutfile(outfile);
    fin.printInfo();
    fin.plotFunction();
    fin.plotData(data_point, 50, true);

    

    NormalFunction normal(mean, sigma,min, max,"NormalFit");
    normal.printInfo();
    normal.plotFunction();
    normal.plotData(data_point, 100);

    CauchyFunction cauchy(1, 0.7,min, max,"CauchyFit");
    cauchy.plotFunction();
    cauchy.plotData(data_point, 100);
    std::vector<double> pseudo = cauchy.sample_metropolis(5000, 0.7);
    cauchy.plotData(pseudo, 100, false);


    CrystalBallFunction crystal(mean, sigma,2, 1.7,min, max,"CrystalBallFit");
    crystal.plotFunction();
    crystal.plotData(data_point, 100);

    return 0;
   
}












