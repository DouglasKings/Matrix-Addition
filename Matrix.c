#include <stdio.h>
#include <stdlib.h> // Include this header for malloc and free.

// Function prototype for matrix addition
int** addMatrices(int** matA, int** matB, int rows, int cols); // Declares the function prototype here

int main() {
    int rows, cols;
    
    // Prompts the user to enter the number of rows and columns for the matrices
    printf("Enter the number of rows and columns for the matrices: ");
    scanf("%d %d", &rows, &cols);

    // Allocate memory for the matrices
    int** matA = (int**)malloc(rows * sizeof(int*)); // Allocates memory for the first matrix
    int** matB = (int**)malloc(rows * sizeof(int*)); // Allocates memory for the second matrix
    int** result = (int**)malloc(rows * sizeof(int*)); // Allocates memory for the result matrix

    // Initializing matrices
    for (int i = 0; i < rows; i++) {
        matA[i] = (int*)malloc(cols * sizeof(int)); // Allocates memory for each row in the first matrix
        matB[i] = (int*)malloc(cols * sizeof(int)); // Allocates memory for each row in the second matrix
        result[i] = (int*)malloc(cols * sizeof(int)); // Allocates memory for each row in the result matrix
    }

    // Reads matrices from user
    printf("\nEnter elements of first matrix:\n");
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            scanf("%d", &matA[i][j]); // Reads elements for the first matrix

    printf("\nEnter elements of second matrix:\n");
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            scanf("%d", &matB[i][j]); // Reads elements for the second matrix

    // Performs matrix addition
    result = addMatrices(matA, matB, rows, cols); // Calls the function to add the matrices

    // Displays the resulting matrix
    printf("\nThe resulting matrix is:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            printf("%d ", result[i][j]); // Prints each element of the result matrix
        printf("\n"); // Moves to the next line after printing each row
    }

    // Free allocated memory
    for (int i = 0; i < rows; i++) {
        free(matA[i]); // Free memory allocated for each row in the first matrix
        free(matB[i]); // Free memory allocated for each row in the second matrix
        free(result[i]); // Free memory allocated for each row in the result matrix
    }
    free(matA); // Free memory allocated for the first matrix
    free(matB); // Free memory allocated for the second matrix
    free(result); // Free memory allocated for the result matrix

    return 0;
}

// Function definition for matrix addition
int** addMatrices(int** matA, int** matB, int rows, int cols) {
    int** result = (int**)malloc(rows * sizeof(int*)); // Allocates memory for the result matrix
    
    for (int i = 0; i < rows; i++) {
        result[i] = (int*)malloc(cols * sizeof(int)); // Corrected: Allocates memory for each row in the result matrix
        
        for (int j = 0; j < cols; j++)
            result[i][j] = matA[i][j] + matB[i][j]; // Adds corresponding elements of the matrices
    }
    return result; // Returns the result matrix
}