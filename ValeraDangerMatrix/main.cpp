#include <iostream>
#include "MatrixTools.h"
#include <locale>

#define MATRIX_DIM 2

int main() {
    setlocale(LC_CTYPE, "RU");
    for (;;) {
        std::cout << "Выберите способ задания матрицы и векторов:" << std::endl;
        std::cout << "\t 0. Ручное" << std::endl;
        std::cout << "\t 1. Случайными числами" << std::endl;
        int chosen_fill;
        std::cin >> chosen_fill;

        double** A = nullptr;
        double* b = nullptr;
        double* x = nullptr;

        switch (chosen_fill) {
        case 0:
            A = CreateManualMatrix(MATRIX_DIM);
            b = CreateManualVector(MATRIX_DIM);
            x = CreateRandVector(MATRIX_DIM);
            break;
        case 1:
            A = CreateRandMatrix(MATRIX_DIM);
            b = CreateRandVector(MATRIX_DIM);
            x = CreateRandVector(MATRIX_DIM);
            break;
        default:
            std::cout << "Неверно указан способ задания!" << std::endl;
            break;
        }

        double* inital_b = CopyVector(b, MATRIX_DIM); //vector b chages in GaussMethod
        double** inital_A = CopyMatrix(A, MATRIX_DIM); //matrix A chages in GaussMethod

        std::cout << "Матрица A:" << std::endl;
        PrintMatrix(A, MATRIX_DIM);
        std::cout << std::endl;

        std::cout << "Вектор b:" << std::endl;
        PrintVector(b, MATRIX_DIM);
        std::cout << std::endl;


        GaussMethod(A, b, x, MATRIX_DIM);
        std::cout << "Вектор x:" << std::endl;
        PrintVector(x, MATRIX_DIM);
        std::cout << std::endl;

        double err = ErrCalc(inital_A, inital_b, x, MATRIX_DIM);
        std::cout << "ERR = " << err << std::endl;
        std::cout << "---------------------------------------------------------------------- " << std::endl;


        DeleteArray(A, MATRIX_DIM);
        DeleteArray(inital_A, MATRIX_DIM);
        DeleteArray(inital_b);
        DeleteArray(b);
        DeleteArray(x);

    }
}