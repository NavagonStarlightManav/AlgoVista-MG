#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <bitset>
using namespace std;

void display_array(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " " << endl;
    }
}

void Merge_Algo(int array_1[], int low,int mid, int high)
{
    if (low < high)
    {

        int first = mid - low + 1;
        int second = high - mid;

    
        int left[first];
        int right[second];

        for (int i = 0; i < first; i++)
            left[i] = array_1[low + i];
        for (int j = 0; j < second; j++)
            right[j] = array_1[mid + 1 + j];

        int i = low, j = 0, k = 0;

        // Merge elements until one of the arrays is exhausted
        while (j < first && k < second)
        {
            if (left[j] <= right[k])
            {
                array_1[i] = left[j];
                i++;
                j++;
            }
            else
            {
                array_1[i] = right[k];
                i++;
                k++;
            }
        }

        // Copy remaining elements of array_1, if any
        while (j < first)
        {
            array_1[i] = left[j];
            i++;
            j++;
        }

        // Copy remaining elements of array_2, if any
        while (k < second)
        {
            array_1[i] = right[k];
            i++;
            k++;
        }

       
    }
}

void Merge_sort(int array[], int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        Merge_sort(array, low, mid);
        Merge_sort(array, mid + 1, high);
        Merge_Algo(array, low, mid ,high);
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

    Merge_sort(array, 0, size - 1);

    display_array(array, size);

    return 0;
}
