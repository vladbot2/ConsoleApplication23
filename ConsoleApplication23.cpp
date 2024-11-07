#include <iostream>

using namespace std;

template <typename T>
T findMax(T array[], int size) {
    T maxVal = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > maxVal) {
            maxVal = array[i];
        }
    }
    return maxVal;
}

template <typename T>
T findMin(T array[], int size) {
    T minVal = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] < minVal) {
            minVal = array[i];
        }
    }
    return minVal;
}

template <typename T>
void sortArray(T array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                T temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

template <typename T>
int binarySearch(T array[], int size, T value) {
    int left = 0;
    int right = size - 1;
    int mid = -1;

    while (left <= right && mid == -1) {
        int middle = left + (right - left) / 2;
        if (array[middle] == value) mid = middle;
        if (array[middle] < value) left = middle + 1;
        if (array[middle] > value) right = middle - 1;
    }
    return mid;
}

template <typename T>
void replaceElement(T array[], int position, T newValue) {
    array[position] = newValue;
}

int main() {
    int arr[] = { 7, 2, 9, 4, 5 };
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Maximum: " << findMax(arr, size) << endl;
    cout << "Minimum: " << findMin(arr, size) << endl;

    cout << "Array before sorting: ";
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;

    sortArray(arr, size);

    cout << "Array after sorting: ";
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;

    int value = 4;
    if (binarySearch(arr, size, value) != -1) {
        cout << "Element " << value << " found in array" << endl;
    }
    else {
        cout << "Element " << value << " not found" << endl;
    }

    replaceElement(arr, 2, 10);
    cout << "Array after replacing element at position 2: ";
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}