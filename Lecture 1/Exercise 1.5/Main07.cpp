#include "BinModel01.h"
#include "Options01.h"
#include "Options03.h"
#include <iostream>
#include <cmath>
using namespace std;

//Exercise 1.5 - Compare the binomial tree price with that obtained from the CRR analytical formula

int main()
{
   double S0,U,D,R;

   if (GetInputData(S0,U,D,R)==1) return 1;

   double K;   //strike price
   int N;      //steps to expiry

   cout << "Enter call option data:" << endl;

   GetInputData(N,K);

   cout << "European call option price = " << PriceByCRR(S0,U,D,R,N,K,CallPayoff) << endl << endl;

   cout << "Enter put option data:" << endl;

   GetInputData(N,K);

   cout << "European put option price =  " << PriceByCRR(S0,U,D,R,N,K,PutPayoff) << endl << endl;

   cout << "Price Analytic for Call Option = " << PriceAnalytic(S0, U, D, R, N, K) << endl;

   return 0;
}
