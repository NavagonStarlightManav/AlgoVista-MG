#include<iostream>
using namespace std;

int main()
{
    int arrOne[8],arrTwo[8];
    int i,product=1;
    cout<<" Pls enter values for First array "<<endl;
    for(i=0;i<8;i++)
    {
        cin>>arrOne[i];
        product=product*arrOne[i];
    }

    for(i=0;i<8;i++)
    {
        arrTwo[i]=product/arrOne[i];
    }

    for(i=0;i<8;i++)
    {
        cout<<arrTwo[i]<<endl;
    }


}