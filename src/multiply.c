#include <stdlib.h>
#include <stdio.h>


void fill_matrix(int**A, int n, int m){
	
	for (int i=0; i<n; i++) {
		printf("set values for %d row ", i);
		for (int j=0; j<m; j++){
			scanf("%d", &(*((*(A+i))+j)) );
			//printf("\n [%d][%d] not crahshed yet lool\n",i,j);
		}
	}
}


// matrix A nxm, matrix B mxp
void multiply(int** A, int** B, int** C, int n, int m, int p){
	
	for (int i=0; i<n; i++){
		for (int j=0; j<p; j++){
			int tmp =0;
			for (int k=0; k<m;k++){
				//printf("%d ", (*((*(A+i))+k)));
				//printf("%d ", (*((*(B+k)+j))));
				tmp+= (*((*(A+i))+k)) * (*((*(B+k)+j)));
			}
			(*((*(C+i))+j)) = tmp;	
		}
	}	
}

void print_matrix(int** A, int n, int m){
	
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			printf("%d ", (*((*(A+i))+j)));
		}
			printf("\n");
	}
}	


int scalar_product(int* A, int* B, int* C, int n){
	
	int out = 0;
	for (int i=0; i<n; i++){ 
		out += (*(A + i)) * (*(B+i));
	}
	return out;
}

int main(){

// example
/*	int i=0;
	int n = 2;
	int m = 3;
	int p = 2;
	
	int** A;
	A = malloc(n*sizeof(int*));
	for (i=0;i<n;i++)
	{
		*(A+i)=malloc(m*sizeof(int));
	}
	
	int**B;
	B = malloc(m * sizeof(int*));
	for(i=0;i<m;i++)
	{
		*(B+i)=malloc(p*sizeof(int));
	}
	
	// output matrix
	int** C;
	C = malloc(n*sizeof(int*));
	for(i=0;i<n;i++)
	{
		*(C+i)=malloc(p*sizeof(int));
	}
	
	
	fill_matrix(A, n, m);
	fill_matrix(B, m,p);
	multiply(A, B, C, n, m, p);
	print_matrix(C, n, p); */
}





