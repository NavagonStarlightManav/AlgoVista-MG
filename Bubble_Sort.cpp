#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <bitset>

using namespace std;

void Bubble_sort(int array[],int size)
{

    
    for (int j = size; j > 0; j--)
    {
        for (int i = 0; i < j-1; i++)
        {
            int temp;
            if (array[i] > array[i + 1])
            {
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
            else
            {
                continue;
            }
        }
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

    Bubble_sort(array,size);

    display_array(array,size);

    return 0;
}