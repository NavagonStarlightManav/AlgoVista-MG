#include <iostream>
#include <algorithm>
#include <bitset>

using namespace std;
void sort(int array[], int n)
{
    int i, j, temp;

    for (i = 0; i < n; i++)
    {
        for (j = i; j < n; j++)
        {
            if (array[i] > array[j])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
            else
                continue;
        }
    }
}

void BinarySearch(int array[], int value, int n, int low, int high)
{
    int mid;
    mid = (low + high) / 2;

    if (mid < 0 || mid > n - 1)
    {
        cout << " Element is not present in the array " << endl;
        return;
    }
    if (value == array[mid])
    {
        cout << "Element is present at index " << mid << endl;
        return;
    }
    if (value != array[mid])
    {
        if (value >= array[mid])
        {
            low = mid;
            high = n - 1;
            if (mid == n - 2)
            {
                low=mid+1;
                BinarySearch(array, value, n, low, high);
            }
            else
            {

                BinarySearch(array, value, n, low, high);
            }
            if (value <= array[mid])
            {
                low = 0;
                high = mid;
                BinarySearch(array, value, n, low, high);
            }
        }
    }
}

    int main()
    {
        int m1, i;
        cout << " Please enter The number of elements you want in array " << endl;
        cin >> m1;

        int array1[m1] = {};
        cout << " Please enter the " << m1 << " elements of the array " << endl;
        for (i = 0; i < m1; i++)
        {
            cin >> array1[i];
        }
        cout << " Please enter the value to be checked in the array " << endl;
        int value;
        cin >> value;

        sort(array1, m1);
        BinarySearch(array1, value, m1, 0, m1-1);

        return 0;
    }