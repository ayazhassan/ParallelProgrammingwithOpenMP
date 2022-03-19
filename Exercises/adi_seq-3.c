#include <stdio.h>
#include <time.h>
#include <math.h>
#include <sys/time.h>

//#define N 960
#define MAXITER 100

int N = 960;

int main(int argc, char *argv[]){

	if(argc > 1)
		N = atoi(argv[1]);

	float x[N][N], a[N][N], b[N][N];
	int i,j,k, iter;
	double dtime;
	int ssec, esec, susec, eusec;
	struct timeval tv;


	for(i=0; i<N; i++)
		for(j=0; j<N; j++){
			x[i][j] = (i+j) * 1.0; //(double)((rand() % 100) * 1.0);
			a[i][j] = (i+j) * 1.0; //(double)((rand() % 100) * 1.0);
			b[i][j] = (i+j+1) * 1.0; //(double)((rand() % 100) * 1.0);
		}

	gettimeofday(&tv, NULL);
	ssec = tv.tv_sec;
	susec = tv.tv_usec;

//***************ADI code: main loop start****************************
//Outer Iterater
for(iter = 1; iter <= MAXITER; iter++){
//////ADI forward & backword sweep along rows//////
//L1: Starts
for (i = 0; i < N; i++){
for (j = 1; j < N; j++){
x[i][j] = x[i][j]-x[i][j-1]*a[i][j]/b[i][j-1];
b[i][j]= b[i][j] - a[i][j]*a[i][j]/b[i][j-1];
}
x[i][N-1] = x[i][N-1]/b[i][N-1];
}
//L2: Starts
for (i = 0; i < N; i++){
for (j = N-2; j > 1; j--){
	x[i][j]=(x[i][j]-a[i][j+1]*x[i][j+1])/b[i][j];
}
}
////// ADI forward & backward sweep along columns//////
//L3: Starts
for (j = 0; j < N; j++){
for (i = 1; i < N; i++){
x[i][j] = x[i][j]-x[i-1][j]*a[i][j]/b[i-1][j];
b[i][j]= b[i][j] - a[i][j]*a[i][j]/b[i-1][j];
}
x[N-1][j] = x[N-1][j]/b[N-1][j];
}
//L4: Starts
for (j = 0; j < N; j++){
for (i = N-2; i > 1; i--){
	x[i][j]=(x[i][j]-a[i+1][j]*x[i+1][j])/b[i][j];
}
}
//***************ADI code: main loop ends****************************
}
//***************ADI code: main loop end****************************

	gettimeofday(&tv, NULL);
	esec = tv.tv_sec;
	eusec = tv.tv_usec;

	dtime = ((esec * 1.0) + ((eusec * 1.0)/1000000.0)) - ((ssec * 1.0) + ((susec * 1.0)/1000000.0));

	printf("%.3f\n", dtime);
	
	return 0;
}

