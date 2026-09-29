
int* merge(int* arr1, int l1,
           int* arr2, int l2); // bad!

void merge(int* arr1, int l1,
           int* arr2, int l2,
           int* dest);


int main() {

    int arr1[5]{1,3,7,9,12};
    int arr2[3]{2,3,6};

    int res[8];
    int* res = new int[5 + 3];
    
    // int* res = merge(arr1, 5, arr2, 3);
    merge(arr1, 5, arr2, 3, res);

    delete[] res;

}
