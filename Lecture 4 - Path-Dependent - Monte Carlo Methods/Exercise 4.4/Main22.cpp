#include <iostream>
#include "PathDepOption04.h"
#include "GmtrAsianCall.h"
#include "EurCall.h"

using namespace std;

//Exercise 4.4 - Price a barrier call option

int main()
{
   double S0=100.0, r=0.03, sigma=0.2;
   BSModel Model(S0,r,sigma);

   double T =1.0/12.0, K=100.0;
   int m=10;

   double B = 103;

   ArthmAsianCall Option(T,K,m);
   GmtrAsianCall  CVOption(T,K,m);

   UpOutCall OptionUOC(T, K, B, m);
   EurCall OptionEC(T, K);

   long N=1000;
  // Option.PriceByVarRedMC(Model,N,CVOption);
   //cout << "Arithmetic call price = " << Option.Price << endl
       // << "Error = " << Option.PricingError << endl;

   //Option.PriceByMC(Model,N);
  // cout << "Price by direct MC = " << Option.Price << endl
       // << "MC Error = " << Option.PricingError << endl;

   //We need to make EurCall a path dependent option for simplicity
   OptionUOC.PriceByVarRedMC(Model, N, OptionEC);
   cout << "Up and out call price = " << OptionUOC.Price << endl
	   << "Error = " << OptionUOC.PricingError << endl;

   return 0;
}
