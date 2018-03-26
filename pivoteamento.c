#include <stdio.h>
#include <stdlib.h>

float mod (float n){
	return n >= 0 ? n : -n;
}

int pivot(float** A, int n, int linha){
	
	float maior = A[linha][linha];
	int p = linha;
	for (int k = linha + 1; k < n; k++){
		if (mod(A[k][linha]) > mod(maior)){
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

	for (int k = 0 ; k < n-1 ; k++){
		/*int p = pivot(A,n,k);
		printf("pivot de errado \n");
		if (p != k){
			trocaLinha(A,p,k,n);
		}*/
		for(int i = k+1; i < n ; i++){
			float m = A[i][k]/A[k][k];
			for(int j = k+1; j < n; j++){
				A[i][j]-= m*A[k][j];
			}
			b[i] -= m*b[k];
		}
	}
	
}

float* solve (float** A, float* b, int n){

	float* x = (float* ) malloc(n * sizeof(float));
	
	triangularSuperior(A,n,b);	
		
	x[n-1] = b[n-1]/A[n-1][n-1];
	
	for (int i = n-2;i >= 0; i--){
	
		float S = 0;
		for (int j = n-1; j >= 0; j--){
			S += A[i][j]*x[j];
		}
		x[i] = (b[i] - S)/A[i][i];
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
