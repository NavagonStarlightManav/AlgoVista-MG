#include <iostream>
#include <algorithm>
#include <bitset>

using namespace std;

void LinearSearcch(int array[], int value, int n)
{
    int i,temp = 0;

    for (i = 0; i < n; i++)
    {
        if (array[i] == value)
        {
            cout << "Value is present at index " << i << endl;
            temp++;
        }
        else
        {
            continue;
        }
    }
    if (temp == 0)
    {
        cout << " Element is nowhere to be found in the array " << endl;
    }
}

int main()
{   
    int m1,i;
    cout<<" Please enter The number of elements you want in array "<<endl;
    cin>>m1;
    
    int array1[m1] = {};
    cout<<" Please enter the "<<m1<<" elements of the array "<<endl;
    for(i=0;i<m1;i++)
    {
        cin>>array1[i];
    }
    cout<<" Please enter the value to be checked in the array "<<endl;
    int value;
    cin>>value;
    
    LinearSearcch(array1 , value , m1);

    return 0;
}
