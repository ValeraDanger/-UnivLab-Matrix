#include "MatrixTools.h"
#include <random>
#include <iostream>
#include <cmath>

void GaussMethod(double** A, double* b, double* x, size_t matrix_dim){
	/*Прямой ход*/
	for (size_t i = 0; i < matrix_dim; i++){
		for (size_t j = i+1; j < matrix_dim; j++) {
			double coef = A[j][i] / A[i][i];
			for (size_t k = i; k < matrix_dim; k++) {
				A[j][k] = A[j][k] - A[i][k] * coef;
			}
			b[j] -= b[i] * coef;
		}
	}

	/*Обратный ход*/
	for (int i = matrix_dim-1; i >= 0; i--) {
		x[i] = 0;
		for (size_t j = i+1; j < matrix_dim; j++) {
			x[i] += x[j] * A[i][j];
		}
		x[i] = (b[i] - x[i]) / A[i][i];
	}
}

void FillMatrixRand(double** matrix, size_t matrix_dim) {
	for (size_t i = 0; i < matrix_dim; i++) {
		for (size_t j = 0; j < matrix_dim; j++) {
			matrix[i][j] = rand() / double(1000);
		}
	}
}

void FillVectorRand(double* vector, size_t vector_dim) {
	for (size_t i = 0; i < vector_dim; i++) {
		vector[i] = rand() / double(1000);
	}
}

double** CreateRandMatrix(size_t matrix_dim) {
	if (matrix_dim == 0) {
		throw "Zero matrix dim";
	}
	if (matrix_dim > 1000000) {
		throw "Too large matrix dim";
	}

	double** matrix = new double* [matrix_dim];
	for (size_t i = 0; i < matrix_dim; i++) {
		matrix[i] = new double[matrix_dim];
	}
	FillMatrixRand(matrix, matrix_dim);
	
	return matrix;
}

double* CreateRandVector(size_t vector_dim) {
	if (vector_dim == 0) {
		throw "Zero vector dim";
	}
	if (vector_dim > 1000000) {
		throw "Too large vector dim";
	}

	double* vector = new double[vector_dim];
	FillVectorRand(vector, vector_dim);
	return vector;
}

double** CreateManualMatrix(size_t matrix_dim) {
	if (matrix_dim == 0) {
		throw "Zero matrix dim";
	}
	if (matrix_dim > 1000000) {
		throw "Too large matrix dim";
	}

	double** matrix = new double* [matrix_dim];
	for (size_t i = 0; i < matrix_dim; i++) {
		matrix[i] = new double[matrix_dim];
	}

	for (size_t row_n = 0; row_n < matrix_dim; row_n++) {
		std::cout << "Введите " << row_n << " строку массива поэлементно:" << std::endl;
		for (size_t column_n = 0; column_n < matrix_dim; column_n++) {
			std::cin >> matrix[row_n][column_n];
		}
	}
	return matrix;
}

double* CreateManualVector(size_t vector_dim) {
	if (vector_dim == 0) {
		throw "Zero vector dim";
	}
	if (vector_dim > 1000000) {
		throw "Too large vector dim";
	}

	double* vector = new double[vector_dim];

	std::cout << "Введите вектор поэлементно" << std::endl;
	for (size_t i = 0; i < vector_dim; i++) {
		std::cin >> vector[i];
	}

	return vector;
}

double* CopyVector(double* vector, size_t vector_dim) {
	double* copied_vector = new double[vector_dim];
	for (size_t i = 0; i < vector_dim; i++) {
		copied_vector[i] = vector[i];
	}
	return copied_vector;
}

double** CopyMatrix(double** matrix, size_t matrix_dim) {
	double** copied_matrix = new double* [matrix_dim];
	for (size_t i = 0; i < matrix_dim; i++) {
		copied_matrix[i] = CopyVector(matrix[i], matrix_dim);
	}
	return copied_matrix;
}

void PrintVector(double* vector, size_t vector_dim) {
	if (vector_dim == 0) {
		throw "Zero vector dim";
	}

	for (int i = 0; i < vector_dim; i++) {
		std::cout << vector[i] << " ";
	}
	std::cout << std::endl;
}

void PrintMatrix(double** matrix, size_t matrix_dim) {
	if (matrix_dim == 0) {
		throw "Zero matrix dim";
	}

	for (int i = 0; i < matrix_dim; i++) {
		PrintVector(matrix[i], matrix_dim);
	}
}

void DeleteArray(double* array) {
		delete[] array;
	}

void DeleteArray(double** matrix, size_t matrix_dim) {
	for (size_t i = 0; i < matrix_dim; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}

double* MatrixVectorMult(double** matrix, double* vector, size_t dim) {
	double* res_vector{ new double[dim] {0} }; //new array filled with 0
	for (size_t i = 0; i < dim; i++) {
		for (size_t j = 0; j < dim; j++) {
			res_vector[i] += matrix[i][j] * vector[j];
		}
	}
	return res_vector;
}

double ErrCalc(double** matrix, double* b_vector, double* x_vector, size_t dim) {
	double* calc_b_vector = MatrixVectorMult(matrix, x_vector, dim);
	double max_err = -1; //max_err is max abs diff betwen element of calc_b_vector and b_vector
	for (size_t i = 0; i < dim; i++) {
		double t_err = abs(calc_b_vector[i] - b_vector[i]);
		if (t_err > max_err) {
			max_err = t_err;
		}
	}
	DeleteArray(calc_b_vector);
	return max_err;
}




