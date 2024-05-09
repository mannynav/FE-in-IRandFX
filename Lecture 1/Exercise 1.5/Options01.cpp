#include "Options01.h"
#include "BinModel01.h"
#include "Options03.h"
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

double NewtonSymbol(int N, int i)
{

    if(i<0 || i >N)
    {
        return 0;
    }

    double result = 1;

    for(int k = 1; k<= i; ++k)
    {
		result = result * (N - k + 1) / k;
    }

    return result;


}

double PriceAnalytic(double S0, double U, double D, double R, int N, double K)
{

    double q = RiskNeutProb(U, D, R);

    vector<double> PDF(N + 1);

    double PDF_Sum = 0.0;

	double* Price = new double[N + 1];
    double Sum = 0.0;

    for(int i = 0; i <=N; ++i)
    {
		Price[i] = Options03_h::CallPayoff(S(S0, U, D, N, i), K);
    }

    for(int i = 0; i<=N; ++i)
    {
		PDF[i] = NewtonSymbol(N, i) * pow(q, i) * pow((1 - q), (N - i));
		PDF_Sum += PDF[i];

        Sum += PDF[i] * Price[i];
    }

	double result = Sum / pow((1 + R), N);
    delete[] Price;
    return result;
}
