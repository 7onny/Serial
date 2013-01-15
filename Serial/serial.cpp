#include"utility.h"

int main(){
	//Initialization
	int k=0;
	bool repeat=true;
	double phi[N+1][N+1],old_phi[N+1][N+1],x[N+1],y[N+1],r[ITMAX],rate=0.0;
	ofstream log("error_log.txt");
	for(int i=0;i<=N;i++)
		for(int j=0;j<=N;j++)
			phi[i][j]=0;
	for(int i=0;i<=N;i++)
		phi[0][i]=sin(PI*y[i])*sin(PI*y[i]);
	for(int i=0;i<=N;i++)
		for(int j=0;j<=N;j++)
			old_phi[i][j]=phi[i][j];
	for(int i=0;i<=N;i++){
			x[i]=(double)i/N;
			y[i]=(double)i/N;
	}
	for(int i=0;i<ITMAX;i++)
		r[i]=0;


	//Jacobi
	while(k<ITMAX && repeat){
		for(int i=1; i<N; i++)
			for(int j=1; j<N; j++)
				phi[i][j]=0.25*(old_phi[i-1][j]+old_phi[i+1][j]+old_phi[i][j-1]+old_phi[i][j+1]);
		r[k]=monitorError(phi,old_phi,k,log);
		if(r[k]<1e-6)
			repeat=false;
		for(int i=0;i<=N;i++)
			for(int j=0;j<=N;j++)
				old_phi[i][j]=phi[i][j];
		k++;
	}
	
	
	print(x,y,phi,rate);
	
	return 0;
}