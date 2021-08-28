#include <stdio.h>
#include "omp.h"
static long num_pasos=100000000;
double paso;
#define NUM_THREADS 170
void main()
{
    int i, nthreads; double pi, sum[NUM_THREADS],t1,t2,tiempo;
    paso=2.0/num_pasos;
    omp_set_num_threads(NUM_THREADS);
    const double startTime = omp_get_wtime();
#pragma omp parallel
{
  int i, id, nthrds; double x;
  id = omp_get_thread_num();
  nthrds = omp_get_num_threads();
  if(id==0){
      nthreads=nthrds;
  }
  for(i=50000000, sum[id]=0.0; i<num_pasos; i=i+nthrds){
      x=(i+0.5)*paso;
      sum[id]+= 1/x;
  }
}
for(i=0, pi=0.0; i<nthreads;i++){
    pi+=sum[i]*paso;
}
    const double endTime = omp_get_wtime();
    tiempo=t2-t1;
    printf("resultado = (%lf\n",pi);
    printf("tomo (%lf) segundos\n",(endTime - startTime));
}

