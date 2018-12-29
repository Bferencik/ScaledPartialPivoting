#include "matrix.h"
#include "systemClear.h" 	/* For portability... clear command adjusts to operating system */


/* Prints matrix to screen */
/* Passes matrix, b vector, and size of matrix and b */ 

void print(double **inputArray, double *b, int size){

        int i; 		//indexing variable 
	int j;		//indexing variable

	if(clearCommand != NULL){
		system(clearCommand);
	}	


	for(i = 0; i < size; i++){
		for(j = 0; j < size; j++){

			printf("%.3f ", inputArray[i][j]); 
			
			if(j == size-1){
			putchar('|'); 
			printf(" %.2f\n",b[i]);
			}
		}
	}

	putchar('\n');


}

/* Scales Row in array by a factor of k */
/* Passes matrix, b vector, size of matrix and b, row to be scaled, and scale factor */  

void ScaleRow(double **inputArray, double *b, int size, int Row, double k){

	int i; 		//indexing variable 
	int j;		//indexing variable 

	i = Row;

	for(j = 0; j < size; j++){
		inputArray[i][j] = inputArray[i][j] * k;
	}

	b[i] = b[i] * k;


}

/* Adds a row to another */ 
/* Passes Matrix, b vector, size of matrix and b, and the "fromRow" to add to "toRow" */

void AddRow(double **inputArray, double *b, int size, int fromRow, int toRow){

	int j;  

	for(j = 0; j < size; j++){

		inputArray[toRow][j] = inputArray[toRow][j] + inputArray[fromRow][j];
	}

	b[toRow] = b[toRow] + b[fromRow];
}

/* Swaps two rows */ 
/* Passes Matrix, b vector, size of matrix and b, and specified "Row1" to be switched with "Row2" */ 

void swapRow(double ** inputArray, double *b, int size, int Row1, int Row2){

	int j;	

	double * temp;
	double temp2;

	temp = malloc(size * sizeof(double)); 

	for(j = 0; j < size; j++){

		temp[j] = inputArray[Row1][j];
		inputArray[Row1][j] = inputArray[Row2][j]; 
		inputArray[Row2][j] = temp[j]; 
	}

	temp2 = b[Row1]; 
	b[Row1] = b[Row2];
	b[Row2] = temp2; 

	free(temp); 
}

/* Returns the value of the entry with largest magnitude */ 
/* Passes list (or single array) and size of array */ 

double max(double * inputRow, int size){

	int i;			//indexing variable 
	double maxEntry;	//max value to return

	maxEntry = inputRow[0];	

	for(i = 1; i < size; i++){

		if(fabs(inputRow[i]) > fabs(maxEntry)){

			maxEntry = inputRow[i];
		}
	}

	return maxEntry;
}

/* Returns the index value where the entry is located */ 
/* Passes list or (or single array) and key */ 


int matchIndex(double *inputRow, double entry){

	int i; 
	int found;

	found = 0; 

	i = 0;

	while(found == 0){

		if(inputRow[i] == entry){ 
			found = 1; 
			return i; 
		}

		i++;
	}
}

/* Zeros out all entries in temp array */
/* Passes temp array and size of array */

void ZeroTemp(double *inputTemp, int size){

	int i; 

	for(i = 0; i < size; i++){

		inputTemp[i] = 0; 
	}
}

/* Validates integer input. Flushes stream if bad input received */ 

int getInt(){

	int num; 

	while(!(scanf("%d", &num))){

		printf("%s", "\nError: interger not entered\n");
		flush();
	        printf("%s", "Please enter interger: "); 	
	}

	return num; 
}

/* Validates double input. Flushes stream if bad input received */ 

double getDouble(){

	double num;

	while(!(scanf("%lf", &num))){
		printf("%s", "\nError: float number not entered\n");
		flush();
		printf("%s", "Please enter float number: ");
	}

	return num;
}

/* Flushes stream in the event that unwanted input is received */  

void flush(){

	char c;

	while( (c = getchar()) != '\n');
	return; 
}






