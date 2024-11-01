#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <bitset>

using namespace std;

class stack
{
  int Top;
  int size_now;
  int *stack_ptr;

public:
  stack(int size)
  {
    size_now = size;
    stack_ptr = new int[size];
    Top = -1;

    for (int i = 0; i < size_now; i++)
    {
      stack_ptr[i] = 0;
    }
  };

  void isEmpty()
  {
    if (Top == -1)
    {
      cout << " Yes The Stack is empty " << endl;
    }
    else
    {
      cout << " No The  Stack is not empty " << endl;
    }
  }

  void isFull()
  {
    if (Top == size_now - 1)
    {
      cout << " Yes  The Stack is full " << endl;
    }
    else
    {
      cout << " No The stack is not full " << endl;
    }
  }

  int pop()
  {

    if (Top == -1)
    {
      cout << " Sorry There is nothing to pop " << endl;
      return 0;
    }
    else
    {
      int element;
      element = stack_ptr[Top];
      stack_ptr[Top] = 0;
      Top = Top - 1;
      return element;
    }
  }

  void push(int value)
  {
    if (Top == size_now - 1)
    {
      cout << " Sorry sir There is no space to add new value " << endl;
    }
    else
    {
      stack_ptr[Top + 1] = value;
      Top = Top + 1;
    }
  }

  void peek()
  {

    if (Top == -1)
    {
      cout << "  Sorry There is nothing to peek " << endl;
    }
    else
    {
      int position;
      cout << " Please enter the position which values you want  " << endl;
      cin >> position;
      if (position >= 1 && position <= Top + 1)
      {

        int element;

        element = stack_ptr[position - 1];
        cout << " The element is " << element << endl;
      }
      else
      {
        cout << " Sorry sir there is nothing at this position " << endl;
      }
    }
  }
};

int main()
{
  cout << " Lets begin the play " << endl;

  cout << " Please enter the size of stack you want " << endl;
  int size;
  cin >> size;

  stack s1(size);

  int option;
  do
  {
    cout << " Please enter the option you want " << endl;
    cin >> option;

    switch (option)
    {
    case 1:
      s1.isEmpty();
      break;

    case 2:
      s1.isFull();
      break;

    case 3:
      int m;
      m = s1.pop();
      cout << "THe poop is " << m << endl;

      break;

    case 4:
      int value;
      cout << " Please enter the value " << endl;
      cin >> value;

      s1.push(value);
      break;

    case 5:
      s1.peek();
      break;
    case 6:
      exit(0);
    }

  } while (option != 0);

  return 0;
}