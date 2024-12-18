#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <bitset>

using namespace std;

class Queue
{
public:
    int front;
    int end;
    int size_now;
    int *Queue_Ptr;

    Queue(int size)
    {
        Queue_Ptr = new int[size];
        size_now = size;

        for (int i = 0; i < size_now; i++)
        {
            Queue_Ptr[i] = 0;
        }
        front = -1;
        end = -1;
    }

    void IsFull()
    {
        if ((end + 1) % size_now == front)
        {
            cout << "Stack is full" << endl;
        }
        else
        {
            cout << "Stack is not full" << endl;
        }
    }

    void IsEmpty()
    {
        if (front == -1 && end == -1)
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            cout << "Stack is not empty" << endl;
        }
    }

    void enqueue(int value)
    {
        if (front == -1 && end == -1)
        {
            Queue_Ptr[0] = value;
            front = 0;
            end = 0;
        }

        else if ((end + 1) % size_now == front)
        {
            cout << " The Queue is Full Sir . It cant be  added" << endl;
        }
        else
        {
            Queue_Ptr[(end + 1) % size_now] = value;
            end = (end + 1) % size_now;
        }
    }

    int Dequeue()
    {
        if (front == -1 && end == -1)
        {
            cout << " Sorry  the Queue is Empty" << endl;
        }
        else
        {
            int temp = Queue_Ptr[front];

            if (front == 0 && end == 0)
            {
                Queue_Ptr[front] = 0;
                front = -1;
                end = -1;
            }
            else
            {

                Queue_Ptr[front] = 0;
                front = (front + 1) % size_now;
            }
            return temp;
        }
    }
    void peek(int position)
    {
        if (front == -1 && end == -1)
        {
            cout << " Sorry  the Queue is Empty" << endl;
        }
        else
        {
            cout << "The element at position " << position << " is " << Queue_Ptr[position - 1];
        }
    }
    void display()
    {
        if (front == -1 && end == -1)
        {
            cout << " Cant display an empty array " << endl;
        }
        else
        {
            for (int i = 0; i < size_now; i++)
            {
                cout << Queue_Ptr[i] << endl;
            }
        }
    }
    void display_front_end()
    {
        cout<<"front is "<<front<<endl;
        cout<<"end is "<<end<<endl;
    }
};

int main()
{
    cout << " Please enter the size u wanna have " << endl;
    int size;
    cin >> size;

    int position;

    int value;

    int option;
    Queue *Q1 = new Queue(size);

    do
    {
        cout << " Please select The Option " << endl;
        cin >> option;

        switch (option)
        {
        case 1:
        {
            cout << " Please enter the value u wanna add " << endl;
            cin >> value;
            Q1->enqueue(value);
            break;
        }

        case 2:
        {
            cout << " Please enter the position u wanna peek " << endl;
            cin >> position;
            Q1->peek(position);
            break;
        }

        case 3:
        {
            cout << " So You wanna  dequeue " << endl;
            int temp = Q1->Dequeue();
            cout << " THe value of dequeue is " << temp << endl;
            break;
        }

        case 4:
        {
            Q1->IsEmpty();
            break;
        }

        case 5:
        {
            Q1->IsFull();
            break;
        }

        case 6:
        {
            Q1->display();
            break;
        }

        case 7:
        {
            Q1->display_front_end();
            break;
        }
        
        }
    } while (option != 0);

    return 0;
}