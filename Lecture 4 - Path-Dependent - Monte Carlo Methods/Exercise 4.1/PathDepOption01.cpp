#include "PathDepOption01.h"
#include <cmath>

double PathDepOption::PriceByMC(BSModel Model, long N)
{
   double H=0.0;
   SamplePath S(m);
   for(long i=0; i<N; i++)
   {
      Model.GenerateSamplePath(T,m,S);
      H = (i*H + Payoff(S))/(i+1.0);
   }
   return exp(-Model.r*T)*H;
}

double ArthmAsianCall::Payoff(SamplePath& S)
{
   double Ave=0.0;
   for (int k=0; k<m; k++) Ave=(k*Ave+S[k])/(k+1.0);
   if (Ave<K) return 0.0;
   return Ave-K;
}

double EuroCall::Payoff(SamplePath& S)
{
    return std::max(S.back() - K_,0.0);
}

double EuroPut::Payoff(SamplePath& S)
{
    return std::max( K_ - S.back(), 0.0);
}

double EuropeanOption::PriceByMC(BSModel Model, long N)
{

    double H = 0.0;
    SamplePath S(m_);
    for (long i = 0; i < N; i++)
    {
        Model.GenerateSamplePath(T_, m_, S);
        H = (i * H + Payoff(S)) / (i + 1.0);
    }
    return exp(-Model.r * T_) * H;
    
}
