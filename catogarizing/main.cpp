#include<iostream>
#define MAX 100
using namespace std;

class Project {
private:
    int size = 0;
    int arr[MAX];

public:
    void input_array();
    void display();
    void selection_sort();
    void linear_search();
    void binary_search();
    void merge(int [], int, int, int);
    void merge_sort(int [], int, int);
    void call_merge();
};

void info();

int main() {
    Project obj;
    int choice;

    do {
        
        info();

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            obj.input_array();
            break;
        case 2:
            obj.selection_sort();
            cout << "Selection Sort Successfully" << endl;
            break;
        case 3:
            obj.call_merge();
            break;
        case 4:
            obj.linear_search();
            break;
        case 5:
            obj.binary_search();
            break;
        case 6:
            obj.display();
            break;
        case 0:
            cout << "Exited Successfully" << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 0);

}

void info()
{
    cout << endl << "----- MENU -----" << endl;
    cout << "| 1. Input Array " << endl;
    cout << "| 2. Selection Sort " << endl;
    cout << "| 3. Merge Sort " << endl;
    cout << "| 4. Linear Search " << endl;
    cout << "| 5. Binary Search " << endl;
    cout << "| 6. Display Array " << endl;
    cout << "| 0. Exit " << endl;
    cout << "----- ---- -----" << endl;
}

void Project::input_array()
{
    cout << "Enter Array Size: ";
    cin >> size;

    cout << "Enter Array Elements: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "arr[" << i << "]: ";
        cin >> arr[i];
    }
}

void Project::display()
{
    if (size == 0)
    {
        cout << "Input Array Elements First" << endl;
        return;
    }

    cout << "Array is: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void Project::selection_sort()
{
    if (size == 0)
    {
        cout << "Input Array Elements First" << endl;
        return;
    }

    for (int i = 0; i < size - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

void Project::linear_search()
{
    if (size == 0)
    {
        cout << "Input Array Elements First"<<endl;
        return;
    }

    int target;
    cout << "Enter Target to Search: ";
    cin >> target;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            cout << target << " Found at index " << i << endl;
            return;
        }
    }
    cout << "Target " << target << " Not Found in Array" << endl;
}

void Project::binary_search()
{
    if (size == 0)
    {
        cout << "Input Array Elements First"<<endl;
        return;
    }

    selection_sort();

    int target;
    cout << "Enter Target to Search: ";
    cin >> target;

    int low = 0, high = size - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == target)
        {
            cout << target << " Found at index " << mid << endl;
            return;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << "Target " << target << " Not Found in Array" << endl;
}

void Project::merge(int arr[], int start, int mid, int end)
{
    int size1 = mid - start + 1;
    int size2 = end - mid;
    int first[100], second[100];

    for (int i = 0; i < size1; i++)
    {
        first[i] = arr[start + i];
    }
    for (int i = 0; i < size2; i++)
    {
        second[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = start;

    while (i < size1 && j < size2)
    {
        if (first[i] <= second[j])
        {
            arr[k++] = first[i++];
        }
        else
        {
            arr[k++] = second[j++];
        }
    }

    while (i < size1)
    {
        arr[k++] = first[i++];
    }
    while (j < size2)
    {
        arr[k++] = second[j++];
    }
}

void Project::merge_sort(int arr[], int start, int end)
{
    if (start >= end)
    {
        return;
    }

    int mid = (start + end) / 2;
    merge_sort(arr, start, mid);
    merge_sort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}

void Project::call_merge()
{
    if (size == 0)
    {
        cout << "Input Array Elements First"<<endl;
        return;
    }

    merge_sort(arr, 0, size - 1);
    cout << "Merge Sort Successfully" << endl;
}