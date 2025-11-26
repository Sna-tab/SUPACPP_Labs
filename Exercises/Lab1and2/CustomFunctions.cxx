#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>

void read_data_file(std::string& input_file, std::vector<std::pair<double, double>>& data_point){
    double x,y;
    char comma; 
    std::ifstream data_file;
    data_file.open(input_file);
    std::string header; 
    std::getline(data_file, header);
    while (data_file >> x>> comma>> y){
        data_point.push_back(std::make_pair(x, y));
    }    
}

void print(const std::vector<std::pair<double, double>>& data_point){
    int N;
    std::cout<<"Input the number of line to print"<<std::endl;
    std::cin>> N ;
    if (N > data_point.size()){
        std::cout<<"Invalid input N is larger than the data size"<<std::endl;
        std::cout<<"Only the first 5 line will be printed"<<std::endl;
        if (data_point.size() < 5){
            for (size_t i = 0; i < data_point.size(); ++i) {
                std::cout << "x = " <<  data_point[i].first << ", y = " << data_point[i].second << std::endl;
            }
        }
        else{ 
        for (size_t i = 0; i < 5; ++i) {
            std::cout << "x = " <<  data_point[i].first << ", y = " << data_point[i].second<< std::endl;
        }}
    }
    else {
        for (size_t i = 0; i<N; ++i) {
            std::cout << "x = " <<  data_point[i].first << ", y = " << data_point[i].second<< std::endl;
    }
}
}

void print(std::vector<double>& magnitude){
    for (auto i: magnitude){
    std::cout << i << std::endl;
    }    
}


void calculate_magnitude(const std::vector<std::pair<double, double>>& data_point, std::vector<double>& magnitude){
    double x,y;
    double mag;
    for (size_t i=0; i < data_point.size(); i++){
        x=data_point[i].first;
        y=data_point[i].second;
        mag = sqrt(pow(x,2)+pow(y,2));
        magnitude.push_back(mag);
    }
}

void chi_square(const std::vector<std::pair<double, double>>& data_point,const std::vector<std::pair<double, double>>& error_point, double& p, double& q, double& chi){
    chi = 0.0;
    double  observed, expected, diff, error;
    for(size_t i = 0; i < data_point.size(); i++){
        observed = data_point[i].second;
        expected = data_point[i].first*p + q;
        diff = observed - expected;
        error = error_point[i].second;
        chi = chi+pow(diff,2)/pow(error,2);
    }
    chi = chi/( data_point.size() - 2);
    std::cout<<"Chi value is: "<<chi<<std::endl;
}

void fit_line(const std::vector<std::pair<double, double>>& data_point,const std::vector<std::pair<double, double>>& error_point, double& p, double& q, double& chi){
    int n;
    double sumxy = 0.0;
    double sumx = 0.0;
    double sumy = 0.0;
    double sumxsq = 0.0;
    n = data_point.size();
    double chi_value;
    for (size_t i = 0; i <data_point.size(); i++){
        sumxy = sumxy + data_point[i].first * data_point[i].second;
        sumx = sumx + data_point[i].first;
        sumy = sumy +data_point[i].second;
        sumxsq = sumxsq + pow(data_point[i].first,2);
    }
    p = (n*sumxy - sumx *sumy)/(n* sumxsq - sumx * sumx);
    q = (sumxsq * sumy - sumxy * sumx) / (n*sumxsq - sumx*sumx);
    chi_square(data_point, error_point, p, q, chi);

}

void print(std::string fit){
    std::cout<<"The fit function of the data:"<<std::endl;
    std::cout<<fit<<std::endl;
}


double power_fun(double& x, int y, double result){
    if (y > 0){
        result = result *x;
    }
    if (y == 0){
       return result;
    }
    return power_fun(x, y-1,result);
}

void x_pow_y(const std::vector<std::pair<double, double>>& data_point, std::vector<double>& power){
    double x, pow;
    int y;
    double result = 1.0;
    for(size_t i =0; i < data_point.size(); i++){
        x = data_point[i].first;
        y=round(data_point[i].second);
        pow = power_fun(x,y,result);
        power.push_back(pow);
    }
    for (auto i: power){
    std::cout << i << std::endl;
    } 
}


void output(std::string& output_file,std::vector<double>& magnitude){
    std::ofstream outfile;
    outfile.open(output_file, std::ios::app);
    for (auto i: magnitude){
    outfile << i << std::endl;
    } 
    
}

void output(std::string& output_file, std::string& fit, double& chi){
    std::ofstream outfile;
    outfile.open(output_file, std::ios::app);
    outfile << "The fit function: "<< fit << std::endl;
    outfile<<"Chi value is: "<<chi<<std::endl;
}


