#ifndef Options01_h
#define Options01_h

//inputting and displaying option data
int GetInputData(int& N, double& K);

//Factorial function for CRR Formula
int Factorial(int N);

//computing call payoff
double CallPayoff(double z, double K);

double PriceByCRRFormula(double S0, double U, double D,
    double R, int N, double K);

double NewtonSymbol(int N, int i);

double PriceAnalytic(double S0, double U, double D, double R, int N, double K);

#endif
