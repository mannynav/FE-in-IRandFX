#include "Options06.h"
#include "BinModel02.h"
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

double EurOption::PriceByCRR(BinModel Model)
{
   double q=Model.RiskNeutProb();
   vector <double> Price(N + 1);
   //double Price[N+1];
   for (int i=0; i<=N; i++)
   {
      Price[i]=Payoff(Model.S(N,i));
   }
   for (int n=N-1; n>=0; n--)
   {
      for (int i=0; i<=n; i++)
      {
         Price[i]=(q*Price[i+1]+(1-q)*Price[i])
            /(1+Model.GetR());
      }
   }
   return Price[0];
}

int Call::GetInputData()
{
   cout << "Enter call option data:" << endl;
   int N;
   cout << "Enter steps to expiry N: "; cin >> N;
   SetN(N);
   cout << "Enter strike price K:    "; cin >> K;
   cout << endl;
   return 0;
}

double Call::Payoff(double z)
{
   if (z>K) return z-K;
   return 0.0;
}

int Put::GetInputData()
{
   cout << "Enter put option data:" << endl;
   int N;
   cout << "Enter steps to expiry N: "; cin >> N;
   SetN(N);
   cout << "Enter strike price K:    "; cin >> K;
   cout << endl;
   return 0;
}

double Put::Payoff(double z)
{
   if (z<K) return K-z;
   return 0.0;
}



int BullSpread::GetInputData()
{
    cout << "Enter bull spread option data:" << endl;
    int N;
    cout << "Enter steps to expiry N: "; cin >> N;
    SetN(N);

    cout << "Enter K1 as first strike price: "; cin >> K1;
    cout << "Enter K2 as second strike price: "; cin >> K2;

    if (K2 < K1) {
        cout << "K2 must be greater than K1" << endl;
        return 1;
    }

    return 0;
}

double BullSpread::Payoff(double z)
{

    if (z <= K1) {

        return 0;
    }
    else if (K1 < z && z <= K2) {

        return z - K1;
    }
    else {

        return K2 - K1;
    }
}

int BearSpread::GetInputData()
{
    cout << "Enter bear spread option data:" << endl;
    int N;
    cout << "Enter steps to expiry N: "; cin >> N;
    SetN(N);

    cout << "Enter K1 as first strike price: "; cin >> K1;
    cout << "Enter K2 as second strike price: "; cin >> K2;

    if (K2 < K1) {
        cout << "K2 must be greater than K1" << endl;
        return 1;
    }

    return 0;
}

double BearSpread::Payoff(double z) {

    if (z <= K1) {

        return K2 - K1;
    }
    else if (K1 < z && z < K2) {

        return K2 - z;
    }
    else {

        return 0;
    }
}


int DoubleDigital::GetInputData()
{
    cout << "Enter double digital option data:" << endl;
    int N;
    cout << "Enter steps to expiry N: "; cin >> N;
    SetN(N);

    cout << "Enter K1 as first strike price: "; cin >> K1;
    cout << "Enter K2 as second strike price: "; cin >> K2;

    if (K2 < K1) {
        cout << "K2 must be greater than K1" << endl;
        return 1;
    }

    return 0;
}

double DoubleDigital::Payoff(double z)
{
	if (K1 < z && z<K2)
	{
		return 1;
	}
	else
	{

		return 0;
	}
}



