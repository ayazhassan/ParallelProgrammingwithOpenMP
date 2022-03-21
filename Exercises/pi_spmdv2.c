/*

This program will numerically compute the integral of

                  4/(1+x*x) 
				  
from 0 to 1.  The value of this integral is pi -- which 
is great since it gives us an easy way to check the answer.

The is the original sequential program.  It uses the timer
from the OpenMP runtime library

History: Written by Tim Mattson, 11/99.

*/
#include <stdio.h>
#include <omp.h>

static long num_steps = 100000000;
double step;
int main (int argc, char *argv[])
{
	  int i;
	  double x, pi;
	  double start_time, run_time;

	  step = 1.0/(double) num_steps;

	int num_threads=4;
	if(argc > 1)
		num_threads = atoi(argv[1]);

	double sum[num_threads];


	omp_set_num_threads(num_threads);
        	 
	  start_time = omp_get_wtime();

	#pragma omp parallel private(x,i)
{
	int nt = omp_get_num_threads();
	int id = omp_get_thread_num();
	int ept = num_steps/nt;
	int start = id * ept + 1;
	int end = start + ept - 1;
	sum[id] = 0.0;
	  for (i=start;i<= end; i++){
		 x =  (i+0.5)*step;
 		  sum[id] = sum[id] + 4.0/(1.0+x*x);
	  }

}

	pi = 0.0;
	for(i=0; i<num_threads; i++)
		pi += step * sum[i];
	  run_time = omp_get_wtime() - start_time;
	  printf("\n pi with %ld steps is %lf in %lf seconds\n ",num_steps,pi,run_time);
}	  





