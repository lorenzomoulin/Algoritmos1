#include <stdio.h>
#include <stdlib.h>

int pivot(float** A, int n, int linha){
	
	int maior = A[linha][linha];
	int p = linha;
	for (int k = linha + 1; k < n; k++){
		if (A[k][linha] > maior){
			maior = A[k][linha];
			p = k;
		}
	}
	return p;
}

void trocaLinha(float** A, int a, int b, int n){
	float* aux = (float*) malloc(sizeof(float)*n);
	for (int i = 0; i < n; i++){
		aux[i] = A[a][i];
		A[a][i] = A[b][i];
		A[b][i] = aux[i];
	}
}

void triangularSuperior(float** A, int n, float* b){

	for (int i = 0; i < n-1; i++){
		float m = A[i+1][i]/A[i][i];
		printf("MULTIPLICADOR M%d%d: %f\n\n",i+1,i,m);
		A[i+1][i] -= m*A[i][i];
		A[i+1][i+1] -= m*A[i][i+1];
		b[i+1] -= m*b[i];		
	}
	for (int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			printf("%.6f ",A[i][j]);
		printf("\n");
	}
	
}

float* solve (float** A, float* b, int n){

	float* x = (float* ) malloc(n * sizeof(float));
	
	triangularSuperior(A,n,b);	
		
	x[n-1] = b[n-1]/A[n-1][n-1];
	
	for (int i = n-2; i >= 0; i--){
		x[i] = (b[i] - A[i][i+1]*x[i+1])/A[i][i];
	}

	return x;
}

int main (){
	
	
	float** A;
	float* b;
	int n;
	scanf("%d", &n);
	A = (float**)malloc(sizeof(float*)*n);
	for (int i = 0; i < n; i++){
		A[i] = (float*)malloc(sizeof(float)*n);
	}
	b = (float*)malloc(sizeof(float)*n);
	getchar();
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			scanf("%f", &A[i][j]);
			
		}
		
	}
	for (int i = 0; i < n; i++){
		scanf("%f", &b[i]);
		
	}
	
	printf("******matrix A******\n");
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			printf("%.6f ", A[i][j]);
		}
		printf("\n");
	}
	
	printf("******vetor b*******\n");
	for (int j = 0; j < n; j++)
		printf("%f ", b[j]);
		
	float * x = solve(A,b,n);
	
	for (int j = 0; j < n; j++)
		printf("%f ", x[j]);
	

	return 0;
	
}  
