#include <iostream>


void merge(int* arr1, size_t size1,
           int* arr2, size_t size2,
           int* res) {

    int i = 0;
    int j = 0;
    //int* res = new int[size1 + size2];

    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            res[i + j] = arr1[i];
            ++i;
        } else {
            res[i + j] = arr2[j];
            ++j;
        }
    }

    while (i < size1) {
        res[i + j] = arr1[i];
        ++i;
    }

    while (j < size2) {
        res[i + j] = arr2[j];
        ++j;
    }

    //return res;
}
        


int main() {


    int arr1[5]{1, 3, 5, 7, 9};
    int arr2[3]{2, 3, 8};

    int* res = new int[5+3];
    merge(arr1, 5, arr2, 3, res);
    //int* res = merge(arr1, 5, arr2, 3);

    for (size_t i = 0; i < 8; ++i) {
        std::cout << res[i] << ' ';
    }
    
    std::cout << std::endl;

    delete[] res;

    return 0;
}
