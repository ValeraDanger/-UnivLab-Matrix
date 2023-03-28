#pragma once

void GaussMethod(double** A, double* b, double* x, size_t matrix_dim);

void FillMatrixRand(double** matrix, size_t matrix_dim);
void FillVectorRand(double* vector, size_t vector_dim);

double** CreateRandMatrix(size_t matrix_dim);
double* CreateRandVector(size_t vector_dim);

double** CreateManualMatrix(size_t matrix_dim);
double* CreateManualVector(size_t matrix_dim);

void PrintVector(double* vector, size_t vector_dim);
void PrintMatrix(double** matrix, size_t matrix_dim);

void DeleteArray(double* array);
void DeleteArray(double** matrix, size_t matrix_dim);

double* MatrixVectorMult(double** matrix, double* vector, size_t dim);
double ErrCalc(double** matrix, double* b_vector, double* x_vector, size_t dim);

