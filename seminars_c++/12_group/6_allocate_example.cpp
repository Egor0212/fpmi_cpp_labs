#include <iostream>


void AllocateMatrix(int**& matrix, int rows, int cols) {

    std::cout << "AllocateMatrix(): matrx before alloc = " << matrix << '\n';
    matrix = new int*[rows];
    for (int row_ind = 0; row_ind < rows; ++row_ind) {
        matrix[row_ind] = new int[cols]{};
    }
    std::cout << "AllocateMatrix(): matrx after alloc = " << matrix << '\n';
}

void DestroyMatrix(int** matrix, int rows, int cols) {
    for (int row_ind = 0; row_ind < rows; ++row_ind) {
        delete[] matrix[row_ind];
    }
    delete[] matrix;
    std::cout << "Destroyed matrix " << rows << "x" << cols << '\n';
}


int main() {

    int** matrix;

    std::cout << "main(): matrix before aloc = " << matrix << '\n';
    AllocateMatrix(matrix, 3, 3);
    std::cout << "main(): matrix after alloc = " << matrix << '\n';

    if (matrix != nullptr) {
        DestroyMatrix(matrix, 3, 3);
    }

    return 0;
}
