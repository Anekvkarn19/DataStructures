#include <iostream>
using namespace std;
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i; 
        }
    }
    return -1;
}
int BinarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) {
            return mid; 
        }
        if (arr[mid] < key) {
            low = mid + 1; 
        } else {
            high = mid - 1; 
        }
    }
    return -1; 
}
int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements (sorted for Binary Search): ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int key;
    cout << "Enter the element to search: ";
    cin >> key;

    int linearResult = linearSearch(arr, n, key);
    if (linearResult != -1) {
        cout << "Element found at index (Linear Search): " << linearResult << "\n";
    } else {
        cout << "Element not found (Linear Search)" << "\n";
    }

    int binaryResult = BinarySearch(arr, n, key);
    if (binaryResult != -1) {
        cout << "Element found at index (Binary Search): " << binaryResult << "\n";
    } else {
        cout << "Element not found (Binary Search)" << "\n";
    }

    return 0;
}