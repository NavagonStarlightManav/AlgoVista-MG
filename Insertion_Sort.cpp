#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <bitset>

using namespace std;

void Insertion_sort(int array[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = array[i];
        int j = i - 1;

        // Shift elements that are greater than key to the right
        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j--;
        }

        // Insert key at the correct position
        array[j + 1] = key;
    }
}

void display_array(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " " << endl;
    }
}

int main()
{
    cout << " Please tell the size you wanna use " << endl;
    int size;
    cin >> size;

    int array[size];
    cout << " Please enter the array elements " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
    }

    Insertion_sort(array, size);

    display_array(array, size);

    return 0;
}