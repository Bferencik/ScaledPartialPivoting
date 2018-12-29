#include "matrix.h"


int main(){

	int i; 			//Indexing variable
	int j;			//Indexing variable 
	int n;			//Size of square matrix

	double m;		//Ratio of position to pivot. Scales Row 
	double sum = 0; 	//For backwards substitution	

	double ** A; 		//Pointer to arrays
	double * temp;		//Stores entries of Pivot ratios
	double * b;		//Desired vector to map to; Ax = b  
	double * x; 		//Vector that maps A to b; Ax = b



	printf("%s", "Enter size of square matrix: ");
	n = getInt();

	flush();		//* Clears stream in case a double was entered *

	/* Allocating memory to double array, vector x, and vector b */	

	A = malloc(n * sizeof(double *));
	b = malloc(n * sizeof(double));
	x = malloc(n * sizeof(double));
	temp = malloc( n * sizeof(double));

	for(i = 0; i < n; i++){
		A[i] = malloc(n * sizeof(double)); 
	}


	/* Gathering input for Matrix and b vector */


	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){

			print(A,b,n);
			printf("Enter value for A(%d,%d): ", i+1,j+1); 
			A[i][j] = getDouble(); 

			if(j == n-1){
				print(A,b,n); 
				printf("Enter value for b(%d): ",i+1);
				b[i] = getDouble();  	
			}
			
		}
	}


	/* Commencing row swapping and Gaussian Elimination */



	for(i = 0; i < n; i++){


		for(j = i; j < n; j++){


			if(max(A[j],n) == 0){
				printf("No suitable pivot found\nAborting now\n");
				return 0;	/* If max entry is zero, then all entries in row are zero */
			}


			temp[j] = A[j][i]/max(A[j],n);		/* Assesing ratio of pivot to max entry in row */ 
		}



		putchar('\n');


		swapRow(A,b,n,i,matchIndex(temp,max(temp,n)));	/* Swaps Row to obtain the pivot with highest "pivot to max entry" ratio */ 

		ZeroTemp(temp,n);


		/* Finished row swap for an iteration. Proceed with Gaussian Elimintaion */
		/* Determines m Ratio, Scales ith row by m and adds to jth row, then rescales ith row to normal */	


		for(j = i+1; j < n; j++){

			if(A[j][i] != 0){

				m = -1*A[j][i]/A[i][i];
				ScaleRow(A,b,n,i,m);
				AddRow(A,b,n,i,j);
			       	ScaleRow(A,b,n,i,1/m);	
				print(A,b,n);
 			}
		}
	}

	/* Finished Gaussian Elimination. Proceed with backwards substitution */
        /* Takes the difference of b and the sum of all entries in row that are not the pivot (multiplied by x vector), and divides by pivot */	



	for(i = n-1; i >= 0; i--){

		for(j = 0; j < n; j++){

			if(j != i){

				sum = sum + x[j]*A[i][j];	
			}
		}


		x[i] = (b[i] - sum)/A[i][i];
		sum = 0;
	}

	/* Finished with backwards substitution. Prints output to screen */ 


	for(i = 0; i< n; i++){
		printf("x(%d) = %.3f\n", i+1,x[i]); 
	}

	putchar('\n');

		
	/* Deallocates memory */ 


       for(i = 0; i < n; i++){
       		free(A[i]); 
       }

	free(A);
	free(temp);
	free(b);
	free(x); 	



	return 0;
}
