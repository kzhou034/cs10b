#include "minFunc.h"
const int * min(const int arr[], int arrSize) {
    if (arrSize == 0) { //base case 0
        return nullptr;
    }
    else if (arrSize == 1) { //base case 1
        return &arr[0];
    }
    else {
        const int *minimum = min(arr, arrSize - 1);
        if (*minimum > arr[arrSize - 1]) {
            return &arr[arrSize - 1];
        }
        else {
            return minimum;
        }
    }
}