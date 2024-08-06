#include <iostream>

using namespace std;

int linearSearch(int arr[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            return i ;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {2, 22, 56, 76, 90,10,54};
    int n = sizeof(arr);
    int x = 10;

    int result = linearSearch(arr, n, x);
    if (result == -1)
        cout << "Element is not present in array";
    else
        cout << "Element is present at index " << result;
    return 0;
}
