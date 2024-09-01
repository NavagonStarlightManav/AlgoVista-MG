#include <stdio.h>
#include <stdlib.h>

struct MyArray
{
    int total_size;
    int used_size;
    int *ptr; // So we are creating a structure that will ask size of array u want and how space u wanna use and
              // finally an array will created by address name ptr
};


void createArray(struct MyArray *a, int tsize , int usize)
{
   (*a).total_size=tsize;
   (*a).used_size=usize;
   (*a).ptr=(int *) malloc (tsize * sizeof(int));   // Way to create array of Given size 



}
int main()
{
    struct MyArray Marks;
    // instead of doing Marks.total_size=bla bla bla we use a function that does allocation work for us
    createArray(&Marks, 100, 20);

    return 0;
}