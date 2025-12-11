#ifndef Distribution
#define Distribution

#include "FiniteFunctions.h"
#include <string>


class NormalFunction : public FiniteFunction {
public:
    NormalFunction(double mu, double sigma,double RMin, double RMax,std::string outfile);

    virtual double callFunction(double x) override;

protected:
    double m_mu;
    double m_sigma;
};



class CauchyFunction : public FiniteFunction {
public:
    CauchyFunction(double x0, double gamma,double RMin, double RMax,std::string outfile);

    virtual double callFunction(double x) override;

private:
    double m_x0;
    double m_gamma;
};



class CrystalBallFunction : public FiniteFunction {
public:
    CrystalBallFunction(double mu, double sigma,double alpha, double n,double RMin, double RMax,std::string outfile);

    virtual double callFunction(double x) override;

private:
    double m_mu;
    double m_sigma;
    double m_alpha;
    double m_n;

    double A;
    double B;
    double N;

    void computeConstants(); 
};

#endif
