#ifndef PathDepOption01_h
#define PathDepOption01_h

#include "BSModel01.h"

class PathDepOption
{
   public:
      double T;
      int m;
      double PriceByMC(BSModel Model, long N);
      virtual double Payoff(SamplePath& S)=0;
};

class ArthmAsianCall: public PathDepOption
{
   public:
      double K;
      ArthmAsianCall(double T_, double K_, int m_)
            {T=T_; K=K_; m=m_;}
      double Payoff(SamplePath& S);
};


class EuropeanOption
{
public:
    double T_{};
    int m_{};
	double PriceByMC(BSModel Model, long N);
	virtual double Payoff(SamplePath& S) = 0;
};

class EuroCall : public EuropeanOption
{
public:

    double K_{};

    EuroCall(double T, double K, int m)
    {
    	T_ = T;
        K_ = K;
        m_ = m;
    }

    double Payoff(SamplePath& S) override;
};



class EuroPut : public EuropeanOption
{
public:

    double K_{};
    EuroPut(double T, double K, int m)
    {
        T_ = T;
        K_ = K;
        m_ = m;
    }
    double Payoff(SamplePath& S) override;
};

#endif
