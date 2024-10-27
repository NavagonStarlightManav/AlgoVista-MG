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
        next = nullptr;
    } // now we successfully defined all the contents of train dibba that should be there

    // Now we just declared the  head pointer which will point  to the first node of the linked list or the biggest train dibba that contains
    // all other dibbas . It will request some space in heap memory. Also note that its data type cant be int , it has to be similiar to class

    // Now There is one problem . Head Pointer will be created for every object of class . but we have to make for only intital  object of class . So we have to make it static .

}; // Now consider that we only made a new Data Type and everything is same as Array As ADT

class Circular_linked_list
{
    Required_Data_Type *head;

public:
    Circular_linked_list(int data, int key)
    {
        head = new Required_Data_Type(data, key);
        head->next = head;
    }

    Circular_linked_list()
    {
        head = new Required_Data_Type(0, 0); // This is the constructor of class . It will be called when we create an object of class . Especially for intial object of the class
        head->next = head;
    }

    void Append_Single_Linked_list(Required_Data_Type *new_pointer)
    {
        Required_Data_Type *Temp_Transversal = head;

        if (Temp_Transversal->next == head)
        {
            Temp_Transversal->next = new_pointer;
            new_pointer->next = head;
        }
        else
        {
            Temp_Transversal = Temp_Transversal->next;
            do
            {
                Temp_Transversal = Temp_Transversal->next;
            } while (Temp_Transversal->next != head);

            // Now Temp_Transversal is the last node; append the new node
            Temp_Transversal->next = new_pointer;
            new_pointer->next = head;
        }
    }

    void Insertion_linked_list_at_particular_place(Required_Data_Type *new_pointer, int position)
    {
        Required_Data_Type *Temp;

        Temp = head;

        if (Temp->next == head)
        {
            Append_Single_Linked_list(new_pointer);
        }
        else
        {
            int count = 1;
            while (count < position - 1)
            {
                Temp = Temp->next;
                count++;
            }
            new_pointer->next = Temp->next;
            Temp->next = new_pointer;
        }
    }

    void prepend_linked_list(Required_Data_Type *new_pointer)
    {
        Required_Data_Type *Temp_pre = head;

        new_pointer->next = Temp_pre;

        Temp_pre = Temp_pre->next;
        do
        {
            Temp_pre = Temp_pre->next;
        } while (Temp_pre->next != head);

        Temp_pre->next = new_pointer;
        head = new_pointer;
    }

    void insert_after_Node(Required_Data_Type *new_pointer, int position)
    {
        Required_Data_Type *Temp;

        Required_Data_Type *Temp_5;

        Temp = head;

        int count = 1;
        while (count < position)
        {
            Temp = Temp->next;
            count++;
        }
        Temp_5 = Temp->next;
        Temp->next = new_pointer;
        new_pointer->next = Temp_5;
    }

    void Insertion_at_end(Required_Data_Type *new_pointer)
    {
        Required_Data_Type *Temp = head;

        Temp = Temp->next;

        do
        {
            Temp = Temp->next;
        } while (Temp->next != head);

        Temp->next = new_pointer;
        new_pointer->next = head;
    }

    void deletion_linked_list(int position)
    {
        Required_Data_Type *Temp = head;

        Required_Data_Type *Temp_Fast = head->next;

        int count = 1;
        while (count < position - 1)
        {
            Temp = Temp->next;
            Temp_Fast = Temp_Fast->next;
            count++;
        }
        Temp->next = Temp_Fast->next;
    }

    void deletion_by_value(int value)
    {
        Required_Data_Type *Temp = head;

        Required_Data_Type *Temp_Fast = head->next;

        if (value == head->data)
        {
            head = head->next;
        }

        // Very important that this is also the case for delete at the beggining
        else
        {

            while (Temp_Fast->data != value)
            {
                Temp = Temp->next;
                Temp_Fast = Temp_Fast->next;
            }
            Temp->next = Temp_Fast->next;
        }
    }

    void deletion_at_last()
    {
        Required_Data_Type *Temp = head;
        Required_Data_Type *Temp_Fast = head->next;

        Temp = Temp->next;
        Temp_Fast = Temp->next;
        do
        {
            Temp = Temp->next;
            Temp_Fast = Temp_Fast->next;
        } while (Temp_Fast->next != head);

        Temp->next = head;
        Temp_Fast = NULL;
    }

    void display()
    {
        Required_Data_Type *temp;

        temp = head;
        cout << temp->data << endl;
        cout << temp->key << endl;

        cout << " \n \n " << endl;

        temp = temp->next;

        do
        {
            cout << temp->data << endl;
            cout << temp->key << endl;

            cout << " \n \n " << endl;
            temp = temp->next;
        } while (temp != head->next);
    }
};

int main()
{
    cout << " Lets begin The play " << endl;

    int option, position;
    int data, key;

    Circular_linked_list O1(10, 1);

    do
    {
        cout << " Please choose the option u wanna choose " << endl;
        cin >> option;

        switch (option)

        {
        case 1:
        {
            cout << "Please enter the data and key values for append a new node " << endl;
            cin >> data >> key;

            Required_Data_Type *wow = new Required_Data_Type(data, key);

            O1.Append_Single_Linked_list(wow);
            break;
        }

        case 2:
        {
            cout << " Please enter the position where u wanna perform the required operation " << endl;
            cin >> position;
            cout << "Please enter the data and key values for append a new node " << endl;
            cin >> data >> key;

            Required_Data_Type *smoothy = new Required_Data_Type(data, key);

            O1.Insertion_linked_list_at_particular_place(smoothy, position);
            break;
        }
        case 3:
        {
            cout << " So U wanna prepend node " << endl;
            cout << "Please enter the data and key values for append a new node " << endl;
            cin >> data >> key;

            Required_Data_Type *now = new Required_Data_Type(data, key);
            O1.prepend_linked_list(now);
            break;
        }

        case 4:
            O1.display();
            break;
        case 5:
        {
            cout << " Please enter the position which after you perform the required operation " << endl;
            cin >> position;
            cout << "Please enter the data and key values for append a new node " << endl;
            cin >> data >> key;

            Required_Data_Type *Nancy = new Required_Data_Type(data, key);

            O1.insert_after_Node(Nancy, position);
            break;
        }
        case 6:
        {
            cout << " Please enter the position at which u wanna delete " << endl;
            cin >> position;
            O1.deletion_linked_list(position);
            break;
        }
        case 7:
        {
            cout << " Please enter the key value of the node which u wanna delete " << endl;
            cin >> data;

            O1.deletion_by_value(data);
            break;
        }
        case 8:
        {
            cout<<" So deletion at last eh "<<endl;
            O1.deletion_at_last();
            break;
        }
        case 9:
        {
            cout << "Please enter the data and key values for append a new node at last " << endl;
            cin >> data >> key;

            Required_Data_Type *queen = new Required_Data_Type(data, key);
            O1.Insertion_at_end(queen);
            break;
        }

        default:
            break;
        }
    } while (option != 0);

    return 0;
}