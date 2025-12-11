#include "FiniteFunctions.h"
#include "Distribution.h"
#include <cmath>
#include <iostream>


NormalFunction::NormalFunction(double mu, double sigma,double RMin, double RMax,std::string outfile)
: FiniteFunction(RMin, RMax, outfile)
{
    m_mu = mu;
    m_sigma = sigma;
}

double NormalFunction::callFunction(double x)
{
    double f = 1/(m_sigma* sqrt(2*M_PI))*exp(pow((x-m_mu)/m_sigma,2)*-0.5);    
    return f;
}



CauchyFunction::CauchyFunction(double x0, double gamma,double RMin, double RMax,std::string outfile): FiniteFunction(RMin, RMax, outfile)
{
    m_x0=x0;
    m_gamma=gamma;


}

double CauchyFunction::callFunction(double x)
{
    double f = 1.0 / (M_PI * m_gamma *(1.0 + pow(((x - m_x0) / m_gamma), 2)));
    return f;
} 



CrystalBallFunction::CrystalBallFunction(double mu, double sigma,double alpha, double n,double RMin, double RMax,std::string outfile): FiniteFunction(RMin, RMax, outfile)
  
{
    m_mu = mu;
    m_sigma = sigma;
    m_alpha= alpha;
    m_n = n;
    computeConstants();
}

void CrystalBallFunction::computeConstants()
{
    A = pow(m_n/fabs(m_alpha),m_n) *exp(-pow(fabs(m_alpha),2)/2);
    B = m_n/fabs(m_alpha) - fabs(m_alpha);
    double C = m_n/fabs(m_alpha)*1/(m_n-1)*exp(-pow(fabs(m_alpha),2)/2);
    double D = sqrt(M_PI/2)*(1+erf(fabs(m_alpha)/sqrt(2)));
    N = 1/(m_sigma*(C+D));

}

double CrystalBallFunction::callFunction(double x)
{
    double cond  = (x - m_mu) / m_sigma;
    double cb;

    if (cond > -m_alpha) {
       
        cb = exp(-pow((x-m_mu),2)/(2*pow(m_sigma,2)));
    }
    else {
       
        cb = A*pow((B-(x-m_mu)/m_sigma), -m_n);
    }
    double crystal = cb * N;
    return crystal;
}
