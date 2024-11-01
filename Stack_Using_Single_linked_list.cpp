#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <bitset>

using namespace std;

class Required_Data_Type //  Lets make the class data type as we  did in case of array as adt
{

public:
    int data;
    int key;
    Required_Data_Type *next;

    Required_Data_Type(int data_1, int key_1)
    {
        data = data_1;
        key = key_1;
        next = nullptr;
        // now we successfully defined all the contents of train dibba that should be there

        // Now we just declared the  head pointer which will point  to the first node of the linked list or the biggest train dibba that contains
        // all other dibbas . It will request some space in heap memory. Also note that its data type cant be int , it has to be similiar to class

        // Now There is one problem . Head Pointer will be created for every object of class . but we have to make for only intital  object of class . So we have to make it static .
    }
    Required_Data_Type()
    {
        data = 0;
        key = 0;
        next = nullptr;
    }
}; // Now consider that we only made a new Data Type and everything is same as Array As ADT

class Double_Linked_list
{
    Required_Data_Type *head;

public:
    Double_Linked_list(int data, int key)
    {
        head = new Required_Data_Type(data, key);
        head->next = NULL;
    }

    Double_Linked_list()
    {

        head = new Required_Data_Type(0, 0); // This is the constructor of class . It will be called when we create an object of class . Especially for intial object of the class
        head->next = NULL;
    }

    void push(Required_Data_Type *new_pointer) // Or You can say that Insertion At The Beggining .
    {
        Required_Data_Type *Temp;

        Temp = head;

        new_pointer->next = Temp;
        head = new_pointer;
    }

    Required_Data_Type *Pop(int upperlimit)
    {
        Required_Data_Type *Temp;

        Temp=head;
        head=head->next;
        return Temp;
    }

    Required_Data_Type *peek(int position)
    {
        Required_Data_Type *Temp = head;

        int count = 1;

        while (count < position)
        {
            Temp = Temp->next;
            count++;
        }

        return Temp;
    }

    void isEmpty()
    {
        if (head->data==0 &&  head->next == NULL && head->key==0)

        {
            cout << " Yes Sir Stack is Empty " << endl;
        }
        else
        {
            cout << " No Sir Stack is Not Empty " << endl;
        }
    }

    void isFull(int upperlimit)
    {
        cout << " Let me check honey " << endl;

        Required_Data_Type *Temp;

        Temp = head;
        int count = 0;

        while (Temp->next == NULL)
        {
            Temp = Temp->next;
            count++;
        }

        if (count == upperlimit - 1)
        {
            cout << " Yes Sir Stack is Full " << endl;
        }
        else
        {
            cout << " No Sir Stack is Not Full " << endl;
        }
    }
};

int main()
{

    int position;
    int value;

    int option;
    int upperlimit;
    int data, key;

    cout << " Please tell the upperlimit " << endl;
    cin >> upperlimit;

    Double_Linked_list *R1=new  Double_Linked_list();

    do
    {
        cout << " Please select the OPTION " << endl;
        cin >> option;

        switch (option)
        {
        case 1:
        {
            cout << " So You wanna push " << endl;
            cout << " please enter the new values " << endl;
            cin >> data >> key;
            Required_Data_Type *Temp = new Required_Data_Type(data,key);
            R1->push(Temp);
            break;
        }

        case 2:
        {
            cout << " So You wanna pop " << endl;
            Required_Data_Type *Temp_2;
            Temp_2 = R1->Pop(upperlimit);
            if (Temp_2 != NULL)
            {
                cout << " The data values are " << Temp_2->data << endl;
                cout << " The key values are " << Temp_2->key << endl;
            }
            break;
        }

        case 3:
        {
            cout << " So You wanna peek " << endl;
            cout << " Please enter the position " << endl;
            cin >> position;

            Required_Data_Type *Temp_2;
            Temp_2 = R1->peek(position);
            if (Temp_2 != NULL)
            {
                cout << " The data values are " << Temp_2->data << endl;
                cout << " The key values are " << Temp_2->key << endl;
            }
            break;
        }

        case 4:
        {
            cout << "  So You wanna check empty " << endl;
            R1->isEmpty();
            break;
        }

        case 5:
        {
            cout << "So You wanna check full " << endl;
            R1->isFull(upperlimit);
            break;
        }
        }
    }

    while (option != 0);

    return 0;
}