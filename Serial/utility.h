#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

#define ITMAX 100000
#define N 4
const double PI=atan(1.0)*4.0;

double monitorError(double phi[N+1][N+1], double old_phi[N+1][N+1], double *rate, int k);
void print(double x[N+1], double y[N+1], double phi[N+1][N+1], double rate);