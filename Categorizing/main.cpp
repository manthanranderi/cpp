 #include <iostream>
using namespace std;

// Inline swap for efficiency
inline void swapVals(int &a, int &b) {
    int t = a; a = b; b = t;
}

// Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) minIdx = j;
        }
        if (minIdx != i) swapVals(arr[i], arr[minIdx]);
    }
}

// Merge function
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}

// Merge Sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Linear Search
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) return i;
    }
    return -1;
}

// Binary Search
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) return mid;
        else if (arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

// Print Array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    if (!(cin >> n) || n <= 0) {
        cout << "Invalid size.\n";
        return 0;
    }

    int* arr = new int[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    bool isSorted = false;
    int choice;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Selection Sort\n";
        cout << "2. Merge Sort\n";
        cout << "3. Linear Search\n";
        cout << "4. Binary Search\n";
        cout << "5. Display Array\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            selectionSort(arr, n);
            isSorted = true;
            cout << "Array after Selection Sort: ";
            printArray(arr, n);
            break;

        case 2:
            mergeSort(arr, 0, n - 1);
            isSorted = true;
            cout << "Array after Merge Sort: ";
            printArray(arr, n);
            break;

        case 3: {
            int key;
            cout << "Enter element to search (Linear Search): ";
            cin >> key;
            int idx = linearSearch(arr, n, key);
            if (idx != -1) cout << "Element found at index " << idx << "\n";
            else cout << "Element not found.\n";
            break;
        }

        case 4: {
            int key;
            if (!isSorted) {
                cout << "Array not sorted. Sorting with Merge Sort first...\n";
                mergeSort(arr, 0, n - 1);
                isSorted = true;
                cout << "Sorted array: ";
                printArray(arr, n);
            }
            cout << "Enter element to search (Binary Search): ";
            cin >> key;
            int idx = binarySearch(arr, n, key);
            if (idx != -1) cout << "Element found at index " << idx << "\n";
            else cout << "Element not found.\n";
            break;
        }

        case 5:
            cout << "Array elements: ";
            printArray(arr, n);
            break;

        case 0:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    delete[] arr;
    return 0;
}
