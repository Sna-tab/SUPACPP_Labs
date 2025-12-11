#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>

void read_data_file(std::string& input_file, std::vector<double>& data_point){
    double x;
    char comma; 
    std::ifstream data_file;
    data_file.open(input_file);
    std::string header; 
    std::getline(data_file, header);
    while (data_file >> x){
        data_point.push_back(x);
    }    
}

double standard_deviation(std::vector<double>& data_point ){

    double sum = 0.0, mean= 0.0, sd = 0.0;
    int size = data_point.size();
    for (int i = 0; i < size; ++i) {
        sum += data_point[i];
    }
    mean = sum / size;
    for (int i = 0; i < size; ++i) {
        sd += pow(data_point[i] - mean, 2);
    }
    std::cout<<"sd: "<<sd<< "size:  "<< size<<std::endl;
    double sigma = sd/size;
    double sig = sqrt(sigma);
    std::cout<<"sig: "<<sig<<std::endl;
    
    return sig;
}

double mean_(std::vector<double>& data_point){
    double sum = 0.0, mean= 0.0, sd = 0.0;
    int size = data_point.size();
    for (int i = 0; i < size; ++i) {
        sum += data_point[i];
    }
    mean = sum / size;
    
    return mean;
}
