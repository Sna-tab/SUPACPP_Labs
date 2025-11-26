#ifndef CustomFunctions
#define CustomFunctions

#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>

std::vector<std::pair<double, double>> data_point;
std::vector<std::pair<double, double>> error_point;
std::vector<double> magnitude;
std::vector<double> power;
int function;
double p;
double q;
char line;
double chi;
std::ostringstream func;
void print(const std::vector<std::pair<double, double>>& data_point);
void print(std::vector<double>& magnitude);
void read_data_file(std::string& input_file, std::vector<std::pair<double, double>>& data_point);

void calculate_magnitude(const std::vector<std::pair<double, double>>& data_point, std::vector<double>& magnitude);

void fit_line(const std::vector<std::pair<double, double>>& data_point,const std::vector<std::pair<double, double>>& error_point, double& p, double& q, double& chi);
void print(std::string fit);
void chi_square(const std::vector<std::pair<double, double>>& data_point,const std::vector<std::pair<double, double>>& error_point, double& p, double& q, double& chi);
void x_pow_y(const std::vector<std::pair<double, double>>& data_point, std::vector<double>& power);
double power_fun(double& x, int y, double result);

std::string output_magnitude = "/workspaces/SUPACPP_Labs/Exercises/Lab1and2/Outputs/magnitude.txt";
std::string output_fit = "/workspaces/SUPACPP_Labs/Exercises/Lab1and2/Outputs/fit.txt";
std::string output_power = "/workspaces/SUPACPP_Labs/Exercises/Lab1and2/Outputs/power.txt";

void output(std::string& output_file,std::vector<double>& magnitude);
void output(std::string& output_file, std::string& fit, double& chi);

#endif