#include <iostream>
#include "PathDepOption01.h"

//Exercise 4.1 - Add ability to price euro calls and euro puts

using namespace std;

int main()
{
   double S0=100.0, r=0.03, sigma=0.2;

   BSModel Model(S0,r,sigma);

   double T=1.0/12.0, K=100.0;

   int m=30;

   ArthmAsianCall Option(T,K,m);

   long N=100000;

   cout << "Asian Call Price = " << Option.PriceByMC(Model,N) << endl;


   EuroCall callOpt(T, K, m);
   EuroPut putOpt(T, K, m);

   std::cout << "Euro call price " << callOpt.PriceByMC(Model, N) << std::endl;
   std::cout << "Euro put price " << putOpt.PriceByMC(Model, N) << std::endl;

	std::cout << putOpt.PriceByMC(Model, N) + S0 - K * std::exp(-r * T) << std::endl;



   return 0;
}