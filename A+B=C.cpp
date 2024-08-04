#include<iostream>
using namespace std;

int main()
{
    int arr[10],i,j,k;
    cout << "Pls enter values "<<endl;
    for(i=0;i<10;i++)
    {
        cin>>arr[i];
    }
    //Again applying Brute force strategy
    for(i=0;i<10;i++)
    {
        for(j=i+1;j<10;j++)
        {
            for(k=0;k<10;k++)
            {
               if(arr[i]+arr[j]==arr[k])
               cout<<i+1<<" and  "<<j+1<<" give "<<k+1<<endl;
               else
               {
                continue;
               }
            }
        }
    }

}