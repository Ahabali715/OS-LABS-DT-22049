#include <iostream>
using namespace std;

// Function to update the array in most recently used fashion
void recently(int* arr, int size, int elem) {
    int index = elem % size;  // Determine index based on hash
    int temp = index;
    int id = arr[index];      // Element to move

    // Shift elements from index down to 1
    while (temp > 0) {
        arr[temp] = arr[temp - 1];
        temp--;
    }

    arr[0] = id;  // Place most recently used item at the front
}

// Function to print array elements
void print(int* arr, int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int elem = 3;  // Element for which we apply MRU strategy
    int arr[] = {6, 1, 9, 5, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    recently(arr, size, elem);

    cout << "Array in most recently used fashion: ";
    print(arr, size);

    return 0;
}
