#include <iostream>
#include <cmath>
#include <fstream>
#include <sstream>
#include <vector>
#include "CustomFunctions.h"


int main(){
    std::string input_file = "/home/s2852655/SUPACPP_Labs/Exercises/Lab1and2/input2D_float.txt";
    std::string error_file = "/home/s2852655/SUPACPP_Labs/Exercises/Lab1and2/error2D_float.txt";
    
    std::cout<<"What function you want to use?"<<std::endl;
    std::cout<<"To print N line enter: 1"<<std::endl;
    std::cout<<"To calculate the magnitude enter: 2"<<std::endl;
    std::cout<<"To fit the data and calculate the chi-squared enter: 3"<<std::endl;
    std::cout<<"To claculate the x to power of y for each data point enter: 4"<<std::endl;
    std::cin>>function;

    read_data_file(input_file, data_point);
    read_data_file(error_file, error_point);
    if (function == 1){
        print(data_point);
    }
    else if (function == 2)
    {
        calculate_magnitude(data_point, magnitude);
        print(magnitude);
        output(output_magnitude, magnitude);
    }
    else if (function == 3)
    {
        fit_line(data_point , error_point, q,p, chi);
        func << "y = " << p << " * x + " << q;
        std::string fit = func.str();
        print(fit);
        output(output_fit, fit, chi);
    }
    else if (function == 4)
    {
        x_pow_y(data_point, power);
        print(power);
        output(output_power, power);
    }
    
    
    else{
        std::cout<<"Invalid input"<<std::endl;
        return main();
    }
    int input;
    std::cout<<"To use another function enter: 1"<<std::endl;
    std::cout<<"To close the programm enter: 2"<<std::endl;
    std::cin>>input;
    if (input == 1){
        return main();
    }
    else if(input == 2)
    {
        return 0;
    }
    else{
        std::cout<<"Invalid input the programm will close"<<std::endl;
    }
    return 0;
}


