#include <stdlib.h>
#include <stdio.h>
#define DEBUG

#ifdef DEBUG
	#define IF_DEBUG(code) code
#else
	#define IF_DEBUG(code)  
#endif

/*!
Fill in matrix from std input from console
\param[in] matrix 	Pointer to array of int
\param[in] a 		Count of strings
\param[in] b			Count of columns
*/
void ScanMatrix (int *matrix, int a, int b);


/*!
Print matrix from std input from console
\param[in] matrix 	Pointer to array of int
\param[in] a 		Count of strings
\param[in] b			Count of columns
*/
void PrintMatrix (int *matrix, int a, int b);


/*!
Multiply matrices
\param[in] first_matrix 	Pointer to first matrix size a * b
\param[in] second_matrix 	Pointer to second matrix size b * y
\param[in] result_matrix 	Pointer to resulting matrix (result size a * y)
*/
void MultiplyMatrix (int *first_matrix, int *second_matrix, int *result_matrix,	int a, int b, int y);


int main () {
	int a, b, x, y; // first matrix a*b, second x*y
	scanf ("%d %d %d %d", &a, &b, &x, &y);
	if (b != x) {
		printf ("-1");
		return 0;
	}
	int *first_matrix = (int *) calloc (a * b, sizeof (int));
	int *second_matrix = (int *) calloc (x * y, sizeof (int));
	int *result_matrix = (int *) calloc (a * y, sizeof (int));

	ScanMatrix (first_matrix, a, b);
	IF_DEBUG(PrintMatrix (first_matrix, a, b);)
	ScanMatrix (second_matrix, x, y);
	IF_DEBUG(PrintMatrix (second_matrix, x, y);)
	MultiplyMatrix (first_matrix, second_matrix, result_matrix, a, b, y);
	PrintMatrix (result_matrix, a, y);


	free (first_matrix);
	free (second_matrix);
	free (result_matrix);
	return 0;
}


void ScanMatrix (int *matrix, int a, int b) {
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			scanf ("%d", &matrix[i * b + j]);
		}
	}
}


void PrintMatrix (int *matrix, int a, int b) {
	IF_DEBUG(printf ("--------------------------\nDebug printing\n");)
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			printf ("%d ", matrix[i * b + j]);
		}
		printf ("\n");
	}
	IF_DEBUG(printf ("--------------------------\n");)
}


void MultiplyMatrix (int *first_matrix, int *second_matrix, int *result_matrix,	int a, int b, int y) {
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < y; j++) {
			int sum = 0;
			for (int k = 0; k < b; k++) {
				sum += first_matrix[i * b + k] * second_matrix[k * y + j];
			}
			result_matrix[i * y + j] = sum;
		}
	}
}
