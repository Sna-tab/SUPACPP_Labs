#ifndef CustomFunctions
#define CustomFunctions

#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>

std::vector<std::pair<double, double>> data_point;
void read_data_file(std::string& input_file, std::vector<double>& data_point);
double standard_deviation (std::vector<double>& data_point );
double mean_(std::vector<double>& data_point);
#endif