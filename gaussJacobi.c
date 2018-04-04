#include <stdio.h>
#include <stdlib.h>

int n;
int numIteracoes;

float mod(float x){return x >= 0 ? x : -1*x;}

float norm(float* x){
	
	float norm = x[0];
	for (int i = 1; i < n; i++)
		if (x[i] > norm)
			norm = x[i];
 	
	return norm;
}



float* resolve (float** A, float* b){
	
	//aloca vetor solução e aloca o vetor anterior inicializado com 0's
	float* xNovo = (float*) malloc(n*sizeof(float));
	float* xAnt = (float*) calloc(sizeof(float),n);
	float err = 0.000001;
	int continuar = 1;
	int num = 0;
	
	while (continuar && num < numIteracoes){
		
		for (int i = 0; i < n; i++){
			
			float Soma = 0;
			
			for (int j = 0; j < i; j++)
				Soma += A[i][j]*xAnt[j];
			for (int j = i + 1; j < n; j++)
				Soma += A[i][j]*xAnt[j];
			
			xNovo[i] = (b[i] - Soma)/A[i][i];
		}
		
		if ((mod(norm(xAnt) - norm(xNovo)) < err))
			continuar = 0;
		
		else
			for (int i = 0; i < n; i++)
				xAnt[i] = xNovo[i];
				
		num++;
	}
	free(xNovo);
	return xAnt;
} 

int main(){
	
	n = 3;
	numIteracoes = 150;
	
	//alocação da matriz Anxn
	float** A = (float**) malloc(n*sizeof(float*));
	for (int i = 0; i < n; i++)
		A[i] = (float*) malloc(n*sizeof(float));
	
	//leitura da matriz Anxn
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%f", &A[i][j]);
		
	
	//alocação do vetor b
	float* b = (float*) malloc(n*sizeof(float));
	
	//leitura do vetor b
	for (int i = 0; i < n; i++)
		scanf("%f", &b[i]);
	
	for (int i = 0; i < n; i++){
		printf("|");
		for (int j = 0; j < n; j++)
			printf(" %f ", A[i][j]);
		printf("|\n");
	}
	
	for (int i = 0; i < n; i++)
		printf("| %f |\n", b[i]);
	float* vetorSolucao = resolve(A,b);
	for (int i = 0; i < n; i++)
		printf("| %f |\n", vetorSolucao[i]);
	for (int i = 0; i < n; i++)
		free(A[i]);
	free(A);
	free(vetorSolucao);
	free(b);
	
	return 0;
}
