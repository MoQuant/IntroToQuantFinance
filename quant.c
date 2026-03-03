#include <stdlib.h>
#include <math.h>
#include <time.h>

double dWT()
{
    int num = 20;
    double dw = (rand() % (2*num + 1)) - num;
    return dw / 100.0;
}

double HestonModel(double S, double mu, double t, double vol, double kappa, double theta, double epsilon)
{
    srand(time(NULL));
    double rho = 0.7;

    int paths = 50;
    int steps = 1000;
    double dt = t / (double) steps;

    double SX = 0;

    for(int i = 0; i < paths; ++i){
        double S0 = S;
        double v0 = vol;
        for(int j = 0; j < steps; ++j){
            double dwt = dWT();
            double dws = rho*dwt;
            v0 += kappa*(theta - v0)*dt + epsilon*pow(v0, 0.5)*dws;
            S0 += mu*S0*dt + pow(v0, 0.5)*S0*dwt;
        }
        SX += S0;
    }
    return SX / (double) paths;
}