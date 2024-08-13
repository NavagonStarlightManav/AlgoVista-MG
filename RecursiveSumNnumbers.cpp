#include<iostream>
using namespace std;

int RecursiveSum(int array[], int number)
{
   if(number==0)
   {
    return 0;
   }
   if(number>0)
   {
    return array[number-1]+RecursiveSum(array,number-1);
   }
}

int main ()
{
    int m1,i;
    cout<<"Please enter How many numbers u want to be added"<<endl;
    cin>>m1;
    
    int array[m1]={};
    cout<<"Please enter the elements to be added"<<endl;
    for(i=0;i<m1;i++)
    {
        cin>>array[i];
    }
    RecursiveSum(array,m1);
    int sum = RecursiveSum(array, m1);
    cout << "Sum: " << sum << endl;
    return 0;



}