#include <iostream>


void AllocateMatrix(int**& matrix, int rows, int cols) {
    matrix = new int*[rows];
    for (int row = 0; row < rows; ++row) {
        matrix[row] = new int[cols]{};
    }
}

void DestroyMatrix(int** matrix, int rows /*int cols*/) {
    for (int row = 0; row < rows; ++row) {
        delete[] matrix[row];
    }
    delete[] matrix;
}

void PrintMatrix(int** matrix, int rows, int cols) {
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            std::cout << matrix[row][col] << ' ';
        }
        std::cout << '\n';
    }
}


int main() {

    //int a[5] = {1,2};

    int a[5][5] = {{1,2}, {2}};
    // [ [1 2 . . .], [2 . . . .], [. . . . .], [. . . . .], [ . . . . .] ]
    // std::cout << a[1][2]; // 0
    
    
    int rows = 5, cols = 5; 
    int** matrix = nullptr;
    AllocateMatrix(matrix, rows, cols);
    PrintMatrix(matrix, rows, cols);
    int* avgs = CalculateRowsAvg(matrix, rows, cols);
    DestroyMatrix(matrix, rows);

    
    
    // a[i*m + j]
    // [.....|.....|.....|.....|.....]
    return 0;
}

