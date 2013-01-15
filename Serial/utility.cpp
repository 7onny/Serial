#include"utility.h"

double two_norm(double A[N+1][N+1]){
	double norm=0;
	for(int i=0; i<=N; i++)
		for(int j=0; j<=N; j++){
			double aux=A[i][j];
			norm+=(aux*aux);
		}
	norm=sqrt(norm);
	return norm;
}

double monitorError(double phi[N+1][N+1], double old_phi[N+1][N+1], int k, ofstream& log){
	double A[N+1][N+1],error;
	for(int i=0;i<=N;i++)
		for(int j=0;j<=N;j++)
			A[i][j]=old_phi[i][j]-phi[i][j];
	error=two_norm(A);
	log<<"Iteration "<<k<<", Error: "<<error<<endl;
	return error;
}

void print(double x[N+1], double y[N+1], double phi[N+1][N+1], double rate){
	//cout<<"N: "<<N<<", Convergence Rate: "<<rate<<endl;
	cout<<"Point "<<x[0]<<","<<y[1]<<"= "<<phi[0][1]<<endl;
	system("pause");
}