#include <stdio.h>
#include <stdlib.h>
#include "funcionesmatrices.h"
#include <omp.h>
#include "ctime.h"

#define SIZE_DATA (1024*1024*64*3)

static double MEM_CHUNK[SIZE_DATA];

// Nueva versión del algoritmo multiplicación de matrices 2 filas * 2 filas
int N, numThreads;
double *matrizA, *matrizB, *matrizC;

int main(int argc, char **argv) {

    int N = (int) atof(argv[1]); //tamaño de la matriz
    int numThreads = (int) atof(argv[2]); // Cantidad de hilos

//	#pragma omp parallel 
	{
		int i, j, k;
		double *matrizA, *matrizB, *matrizC;
		matrizA = MEM_CHUNK;
		matrizB = matrizA + (N*N);
		matrizC = matrizB + (N*N);

		//Se deja que le hilo principal(maestro) haga las rutinas de inicialización
//		#pragma omp master //2,4,8	

		matrizInit(N, matrizA, matrizB, matrizC);
		/*printf("Impresion matriz A \n");
		imprimirMatriz(N,matrizA);
		printf("Impresion matriz B \n");
		imprimirMatriz(N,matrizB);*/

		omp_set_num_threads (numThreads);

		sampleStart();
		// Prueba de multiplicación de matrices con OpenMp

		#pragma omp parallel for
		for (i=0; i<N; i++) {
			for (j=0; j<N; j++) {
				double *pA, *pB, c0, c1, c2, c3;
				c0 = c1 = c2 = c3 = 0.0;
				pA = matrizA+(i*N); // Fila
				pB = matrizB+(j*N); // Columna
				k = N;
				while (k&3) {// En caso de que N no sea múltiplo de 4
					c0 += (*pA * *pB);
					k--;
					pA++;
					pB++;
				}
				for (; k > 0; k-=4, pA+=4, pB+=4) {
					c0 += (*pA * *pB);
					c1 += (*(pA + 1) * *(pB + 1));
					c2 += (*(pA + 2) * *(pB + 2));
					c3 += (*(pA + 3) * *(pB + 3));
				}

				matrizC[i * N + j] = c0 + c1 + c2 + c3;
			}
		}
		/*printf("impresion matriz C \n");
		imprimirMatriz(N,matrizC);*/
		sampleStop();
	}
	printTime();
}