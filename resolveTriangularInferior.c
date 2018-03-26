#include <stdio.h> 
#include <stdlib.h>

float* solve (float** A, float* b, int n){
	
	float* x = (float* ) malloc(n * sizeof(float));
	x[0] = b[0]/A[0][0];
	
	for (int i = 1;i < n; i++){
	
		float S = 0;
		for (int j = 0; j < i; j++){
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
