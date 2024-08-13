#include <iostream>
#include <algorithm>
#include <bitset>

using namespace std;

int SumSeries(int number , int array[] , int size_array,int fixed_X,int sum)
{
    

    if(number==0)
    {
        sum=sum+array[0];
        cout<<" Sum is "<<sum<<endl;
        return 0;
    }



    if(number>=1)
    {   int i,value=1;
        for(i=0;i<size_array-1;i++)
        {
          value=value*fixed_X;
        }
        sum=sum+array[size_array-1]*value;
        size_array=size_array-1;
        number--;
        SumSeries(number,array,size_array,fixed_X,sum);
    }

   
}

    int main()
    {
        int number_of_elements,m1,i,fixed;
        cout<<"Please enter the number of elements in the series you want "<<endl;
        cin>>number_of_elements;

         cout<<" Please enter size of array you want "<<endl;
        cin>>m1;


        int array[m1]={};
       
        cout<<" Please give elements of array to be associated with every element of series "<<endl;
        for(i=0;i<m1;i++)
        {
          cin>>array[i];
        }

        cout<<" Please enter fixed number whose powers you will take "<<endl;
        cin>>fixed;

        int sum=0;

        SumSeries(number_of_elements,array,m1,fixed,sum);

        return 0;
    }
