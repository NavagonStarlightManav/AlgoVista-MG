#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <bitset>

using namespace std;

int Partition(int array[], int low, int high)
{
    int i = low + 1;
    int j = high;
    int pivot = array[low];
    do
    {
        while (array[i] <= pivot)
        {
            i++;
        }

        while (array[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    } while (i <= j);

    int temp_now=array[low];
    array[low]=array[j];
    array[j]=temp_now;

    return j;
}

void Quick_Sort(int array[], int low, int high)
{
    if (low < high)
    {
        int Partitioned_Value;

        Partitioned_Value = Partition(array, low, high);
        Quick_Sort(array, low, Partitioned_Value - 1);
        Quick_Sort(array, Partitioned_Value + 1, high);
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

    Quick_Sort(array, 0, size - 1);

    display_array(array, size);

    return 0;
}