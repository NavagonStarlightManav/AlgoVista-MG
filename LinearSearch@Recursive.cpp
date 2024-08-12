#include <iostream>
#include <algorithm>
#include <bitset>

using namespace std;

void LinearSearcch(int array[], int value, int n)
{

    if (n < 0)
    { 
        cout << "Element is not present in the array" << endl;
        return;
    }
    if (value == array[n])
    {
        cout << "Element is Present at index " << n << endl;
        return;
    }
    else
    {
        n--;
        LinearSearcch(array, value, n);
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

    LinearSearcch(array1, value, m1);

    return 0;
}
