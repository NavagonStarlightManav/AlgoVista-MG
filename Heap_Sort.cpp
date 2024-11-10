#include <iostream>
using namespace std;

// Function to swap two elements by reference
void swap(int &value_1, int &value_2) {
    int temp = value_1;
    value_1 = value_2;
    value_2 = temp;
}

// Function to "heapify" a subtree rooted at index `i`
// `n` is the size of the heap
void heapify(int array[], int n, int i) {
    int largest = i;          // Initialize largest as root
    int left = 2 * i + 1;     // Left child index
    int right = 2 * i + 2;    // Right child index

    // Check if left child exists and is greater than root
    if (left < n && array[left] > array[largest]) {
        largest = left;
    }

    // Check if right child exists and is greater than largest
    if (right < n && array[right] > array[largest]) {
        largest = right;
    }

    // If largest is not root, swap and recursively heapify
    if (largest != i) {
        swap(array[i], array[largest]);
        heapify(array, n, largest);
    }
}

// Function to perform heap sort
void heapSort(int array[], int n) {
    // Step 1: Build a max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(array, n, i);
    }

    // Step 2: Extract elements one by one from the heap
    for (int i = n - 1; i > 0; i--) {
        // Move the current root (largest) to the end of the array
        swap(array[0], array[i]);

        // Reduce the size of the heap by one and heapify the root element
        heapify(array, i, 0);
    }
}

// Helper function to print the array
void printArray(int array[], int n) {
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

// Main function to test the heap sort algorithm
int main() {
    int array[] = {4, 10, 3, 5, 1};
    int n = sizeof(array) / sizeof(array[0]);

    cout << "Original array: ";
    printArray(array, n);

    heapSort(array, n);

    cout << "Sorted array: ";
    printArray(array, n);

    return 0;
}
