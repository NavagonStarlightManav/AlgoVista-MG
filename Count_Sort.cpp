#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <bitset>

using namespace std;

void Count_sort(int array[], int size)
{
    int max = array[0];
    int size_current = size;

    int final_array[size];

    for (int i = 0; i < size_current; i++)
    {
        if (array[i] < array[i + 1])
        {

            max = array[i + 1];
        }
        else
        {
            continue;
        }
    }

    int New_Array[max];

    for (int j = 0; j < max; j++)
    {
        New_Array[j] = 0;
    }

    for (int x = 0; x < size; x++)
    {
        New_Array[array[x]]++;
    }

    int y = 0;

    for (int t = 0; t < max; t++)
    {
        if (New_Array[t] != 0)
        {

            while (New_Array[t] != 0)
            {
                final_array[y] = t;
                New_Array[t]--;
                y++;
            }
        }
        else
        {
            continue;
        }
    }

    for (int k = 0; k < size; k++)
    {
        array[k] = final_array[k];
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

    Count_sort(array, size);

    display_array(array, size);

    return 0;
}