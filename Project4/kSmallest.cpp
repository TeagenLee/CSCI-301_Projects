/**
The goal of this program is to find the k smallest term in an array using recursion.
Teagen Lee
Due: 10/13/2025
*/

#include <iostream>
using namespace std;

/**
 * Partition the array around the first element (pivot).
 * @param arr Pointer to the integer array
 * @param left Starting index of the current range
 * @param right Ending index of the current range
 * @pre none
 * @post Re-arranges the array
 */
int partition(int* arr, int left, int right) {
    int pivot = arr[left]; // Use first element as pivot
    int i = left + 1;      // Start scanning from next element
    int j = right;         // Start scanning from the end

    // Loop until pointers cross
    while (i <= j) {
        // Move i right as long as arr[i] < pivot
        while (i <= right && arr[i] < pivot) {
            i++;
        }

        // Move j left as long as arr[j] > pivot
        while (j >= left + 1 && arr[j] > pivot) {
            j--;
        }

        // Swap elements if i and j have not crossed
        if (i < j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    // Place pivot in its correct sorted position
    arr[left] = arr[j];
    arr[j] = pivot;

    // Return the final position of the pivot
    return j;
}

/**
 * Find the kth smallest element in the array using the Quickselect approach.
 * @param arr Pointer to the array
 * @param left Starting index of the current range
 * @param right Ending index of the current range
 * @param k The order statistic
 * @pre none
 * @post The k smallest number is found in the array
 */
int kSmall(int* arr, int left, int right, int k) {
    if (left <= right) {
        // Partition the array and find the pivot index
        int pivotIndex = partition(arr, left, right);

        // Compute the pivot's rank in the current partition
        int rank = pivotIndex - left + 1;

        if (rank == k) {
            // kth smallest is the pivot
            return arr[pivotIndex];
        }
        else if (k < rank) {
            // kth smallest is in the left partition (S1)
            return kSmall(arr, left, pivotIndex - 1, k);
        }
        else {
            // kth smallest is in the right partition (S2)
            return kSmall(arr, pivotIndex + 1, right, k - rank);
        }
    }

    // Invalid case
    return -1;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    // Dynamically allocate array
    int* arr = new int[n];

    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cout << "Enter the value of k (to find kth smallest element): ";
    cin >> k;

    // Display the original array
    cout << endl;
    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Call kSmall and display result
    int result = kSmall(arr, 0, n - 1, k);
    cout << endl;
    cout << "The " << k << "th smallest element is: " << result << endl;

    // Display array after partition(s)
    cout << "Array after applying kSmall: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;

    return 0;
}
