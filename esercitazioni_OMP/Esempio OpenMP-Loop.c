#include <omp.h>
#include <stdio.h>
#include <time.h>


int main() {
    const int N = 1;
    const int M = 10000;
    const int NITER = 10000;
    int var=0;
    int array[NITER];

    clock_t start = clock();
    #pragma omp parallel num_threads(4)
    //#pragma omp for schedule(static) //nel caso static, presuppongo che la durata di ogni singola iterazione sia sempre la stessa
    #pragma omp for schedule(dynamic, N) //nel caso dynamic, devo specificare il fattore di chunking; piu' grande e' il fattore, minore e' l'overhead introdotto dal parallelismo e minore e' il tempo di esecuzione
    
        for(int j=0; j<M ; j++) {
            for (int i=0; i<NITER ; i++) {
                //array[i] = -3;
            }
        }
    

    clock_t stop = clock();

    double time = (stop-start) / (double) CLOCKS_PER_SEC;
    printf ("Ececution time: %f\n", time);
    return 0;
}