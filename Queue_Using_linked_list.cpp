#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <bitset>

using namespace std;

class Required_Data_Type //  lets make the class data type as we  did in case of array as adt
{

public:
    int data;
    int key;
    Required_Data_Type *next;

    Required_Data_Type(int data_1, int key_1)
    {
        data = data_1;
        key = key_1;
        next = NULL;
    }
};

class Queue
{
public:
    Required_Data_Type *front, *rear;

    Queue(int data, int key)
    {
        front = new Required_Data_Type(data, key);
        rear = front;
    }
    Queue()
    {
        front = new Required_Data_Type(0, 0);
        rear = front;
    }

    void isEmpty()
    {
        if (front->data == 0 && front->key == 0 && front->next == NULL)
        {
            cout << " The Queue is Empty sir " << endl;
        }
        else
        {
            cout << " The Queue is not Empty sir " << endl;
        }
    }

    void isFull(int upperlimit)
    {
        if (front->data == 0 && front->key == 0 && front->next == NULL)
        {
            cout << " The Queue is not full and is empty  sir " << endl;
        }
        else
        {
            int count = 0;
            Required_Data_Type *temp_full = front;
            while (temp_full != NULL)
            {
                temp_full = temp_full->next;
                count++;
            }
            if (count >= upperlimit)
            {
                cout << " The Queue is full sir " << endl;
            }
            else
            {
                cout << " The Queue is not full  sir " << endl;
            }
        }
    }

    void enqueue(Required_Data_Type *new_pointer)
    {
        if (front->data == 0 && front->key == 0 && front->next == NULL)
        {
            front = new_pointer;
            rear = front;
        }
        else if (front == NULL)
        {
            front = new_pointer; // Point front to the new node
            rear = front;        // Point rear to the new node as well
        }
        else
        {
            rear->next = new_pointer;
            rear = new_pointer;
        }
    }

    Required_Data_Type *dequeue()
    {
        if (front->data == 0 && front->key == 0 && front->next == NULL)
        {
            cout << " Sorry sir there is nothing to dequeue " << endl;
            return NULL;
        }
        else
        {
            Required_Data_Type *temp_dequeue;
            if (front != NULL)
            {
                temp_dequeue = front;
                front = front->next;
                if (front == NULL)
                {
                    rear = NULL;
                }
                return temp_dequeue;
            }
            else
            {
              return NULL;
            }
        }
    }

    void display()
    {
        if (front->data == 0 && front->key == 0 && front->next == NULL)
        {
            cout << "  Sorry sir there is nothing to display " << endl;
        }
        else if (front != NULL)
        {
            cout << "  Sorry sir there is nothing to display " << endl;
        }
        else
        {
            Required_Data_Type *temp_display = front;
            while (temp_display != NULL)
            {
                cout << "   " << temp_display->data << "  " << temp_display->key << endl;
                temp_display = temp_display->next;
            }
        }
    }

    Required_Data_Type *peek(int position)
    {
        if (front->data == 0 && front->key == 0 && front->next == NULL)
        {
            cout << " Sorry sir there is nothing to peek " << endl;
            return NULL;
        }
        else
        {
            int count = 1;
            Required_Data_Type *temp_peek = front;
            while (count != position && count < position)
            {
                temp_peek = temp_peek->next;
                count++;
            }
            return temp_peek;
        }
    }
};

int main()
{
    int position;
    int upperlimit;

    cout << " Please choose the upperlimit " << endl;
    cin >> upperlimit;

    int data, key;

    Queue *Q1 = new Queue();

    int option;

    do
    {
        cout << " Please choose the option " << endl;
        cin >> option;

        switch (option)
        {
        case 1:
        {
            cout << " Please enter the data and key values " << endl;
            cin >> data >> key;
            Required_Data_Type *Add = new Required_Data_Type(data, key);
            Q1->enqueue(Add);
            break;
        }
        case 2:
        {
            cout << " So you wanna dequeue " << endl;
            Required_Data_Type *dequeue = Q1->dequeue();
            if (dequeue != NULL)
            {
                cout << "  Dequeued item is " << dequeue->data << " " << dequeue->key << endl;
            }
            delete dequeue;
            break;
        }
        case 3:
        {
            cout << " Please choose the position you wanna see " << endl;
            cin >> position;
            Required_Data_Type *peek = Q1->peek(position);
            if (peek != NULL)
            {
                cout << " Peek is " << peek->data << " " << peek->key << endl;
            }
            break;
        }

        case 4:
        {
            Q1->display();
            break;
        }

        case 5:
        {
            Q1->isFull(upperlimit);
            break;
        }

        case 6:
        {
            Q1->isEmpty();
            break;
        }
        }

    } while (option != 0);

    return 0;
}