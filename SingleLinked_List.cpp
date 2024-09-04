#include <iostream>
#include <algorithm>
#include <bitset>
#include <vector>
#include <map>
#include <string>
#include <list>
using namespace std;

class Node
{ // is class ka kaam bas train ka dibba banao aur khule maidaan me rahna hai
public:
    int key;
    int data;
    Node *next;

    Node()
    {
        key = 0;
        data = 0;
        next = NULL;
    }

    Node(int key1, int data1)
    {
        key = key1;
        data = data1;
    }
    // This class will create a train dibba with things + small space in it for next train dibba so that they will interlock
};

class Single_Linked_list
{ // Ye class uss khule maidaan me pade object ko patri par rakh us par operations karegi
public:
    Node *head;
    // suppose ek train dibba with more dibbas attached to it train track par nhi hai and
    // khule maidan me pada hai . To ye class ek train track par particular plot number
    // reserve kar legi and us reserved space ( with particular address) par maidan wala dibba
    // rakh dehga
    Single_Linked_list()
    {
        head = NULL;
    }
    Single_Linked_list(Node *node)
    {
        head = node;
    }

    Node *Node_exists(int k) // for checking given key of an random object of class node
                             // if is equal to key of object stored earlier in reserved space with address
                             // kind of ek filter jo us space me pade dibbon ki checking karega
    {
        Node *temp = NULL;

        Node *ptr = head;

        while (ptr != NULL)
        {
            if (ptr->key == k)
            {
                temp = ptr;
            }
            ptr = ptr->next; // ptr has a class Node object next as in beginning . Object ke andar same data type wala object hai
            // like in train , suppose u begin with first train dibba and all further dibbas are connected
            // some part of next train dibba is in intial dibba
        }
        return temp; // temp will store address of that train dibba that matches key while checking from first dibba
                     // in our earlier stored dibba in address  ' head ';
    }

    void append_node(Node *n) // Ab ye method maidaan me pade ek external dibba ko  ' head ' naam ke plot me
                              // pade dibbon ke saath  last me jod degi .

    {
        // ab pehle check ke external dibbe ki key hamare address pe dibbon ke saath match to nhi karti
        if (Node_exists(n->key) != NULL)
        {
            cout << " Node Already exists" << endl;
        }
        else
        {
            if (head == NULL) // agar hamare plot me koi dibba hi nhi hai to naya dibba hi pehla dibba hai
            {
                head = n;
            }
            else
            {
                Node *ptr = head;
                while (ptr->next != NULL) // last dibba tak jana takin naya dibba vahan connect kar sakein
                {                         // humne hamare plot me ek chhoti jagah bana kar usme last dibba ka address store lia
                    ptr = ptr->next;      // aur phir us last dibba ke reserved spacing me naya dibba daal diya
                }
                ptr->next = n;
                cout << " Node Appended " << endl;
            }
            n->next = NULL; 
        }
    }

    void prepend_node(Node *n)
    {
        if (Node_exists(n->key) != NULL)
        {
            cout << " Node Already exists" << endl;
        }
        else
        {

            n->next = head;
            head = n;

            cout << " Node PreAppended " << endl;
        }
    }

    void insert_node_particular_place(Node *n)
    {
        int option;
        cout << " Please enter option where u want node to be inserted " << endl;
        cin >> option;

        if (Node_exists(n->key) != NULL)
        {
            cout << " Node Already exists" << endl;
        }

        else
        {
            if (option != 1)
            {
                Node *Temp = NULL;

                Node *Ptr = head;

                for (int i = 0; i < option - 1; i++)
                {
                    Ptr = Ptr->next;
                }
                Temp = Ptr;
                Temp->next = n;
                n->next = Ptr;
            }
            else
            {
                Node *Temp = NULL;

                Node *Ptr = head;

                for (int i = 0; i < option - 1; i++)
                {
                    Ptr = Ptr->next;
                }
                Temp = Ptr;
                Temp->next = n;
                n->next = Ptr;
                head = n;
            }
        }
    }

    void insert_node_after_Particular_node(int key, Node *n)
    {
        Node *ptr = Node_exists(key); // jis key node ke baad insert karna us node ko ek pointer mein pehle store karlo

        if (ptr == NULL)
        {
            cout << "No node Exist with Your Given Key Value " << endl;
        }
        else
        {
            if (Node_exists(n->key) != NULL) // naye dibbe ke key pehle kahin hai to nhi bhai check karlo
            {
                cout << " This Node already exists " << endl;
            }
            else
            {
                n->next = ptr->next;
                ptr->next = n;
                cout << " Node Appneded after given key " << endl;
            }
        }
    }

    void delete_Particular_key_node(int key)
    {
        Node *temp = Node_exists(key);

        if (head == NULL)
        {
            cout << " There is no node to be deleted " << endl;
        }
        else
        {
            if (Node_exists(key) == NULL)
            {
                cout << " No such node exists " << endl;
            }
            else
            {
                if (Node_exists(key) == head)
                {
                    head = head->next;
                    cout << " Node successfully unlinked " << endl;
                }
                else
                {
                    Node *target_deletion = NULL;
                    Node *previous = head;
                    Node *current = head->next;

                    while (current != NULL)
                    {
                        if (current->key == key)
                        {
                            target_deletion = current;
                            current = NULL;
                        }
                        else
                        {
                            previous = previous->next;
                            current = current->next;
                        }
                    }

                    if (temp != NULL)
                    {
                        previous->next = target_deletion->next;
                        cout << " Target Node With Target Values " << endl;
                    }
                    else
                    {
                        cout << " Node Doesnt exist with your given key value " << endl;
                    }
                }
            }
        }
    }

    void update_Node_given_key(int key, int d)
    {
        Node *ptr = Node_exists(key);
        if (ptr != NULL)
        {
            ptr->data = d;
            cout << " Data Updated Successfully " << endl;
        }
        else
        {
            cout << " Node Doesnt Exist of given key value " << endl;
        }
    }

    void printlist()
    {
        if(head==NULL)
        {
          cout<< " No Nodes to be printed "<<endl;
        }
        else
        {
           Node* Temp=head;
           while(Temp!=NULL)
           {
            cout<<" temp key is " <<Temp->key<<endl;
            cout<<" temp data is "<<Temp->data<<endl;
            cout<<" /n"<<endl;

            Temp=Temp->next;
           }
        }
    }
};

int main()
{
    Single_Linked_list s1;
    int option;
    int key1 , data1, k1;;
    do
    {
        cout << " Please enter the option u want to perform operation accordingly " << endl;
        cout << " Press 1 for append to node " << endl;
        cout << " Press 2 for preppend to node " << endl;
        cout << " Press 3 for insert to node " << endl;
        cout << " Press 4 for delete  to node " << endl;
        cout << " Press 5 for update to node " << endl;
        cout << " Press 6 for print()  " << endl;
        cout << " Press 7 for clear screen " << endl;

        cin >> option;

        Node *n1 = new Node();

        switch (option)
        {
        case 0:
            break;

        case 1:
            cout << " Please give key and data values to be appended " << endl;
            cin >> key1;
            cin >> data1;
            n1->data = data1;
            n1->key = key1;
            s1.append_node(n1);
            break;

        case 2:
            cout << " Please enter the key and data values to be prepended " << endl;
            cin >> key1;
            cin >> data1;
            n1->data = data1;
            n1->key = key1;
            s1.prepend_node(n1);
            break;

        case 3:
            cout << " Please enter key after which u want value to be inserted " << endl;
            cin >> k1;
            cout << " Please enter data and key values of new node to be inserted " << endl;
            cin >> key1;
            cin >> data1;
            n1->data = data1;
            n1->key = key1;
            s1.insert_node_after_Particular_node(k1, n1);
            break;

        case 4:
            cout << " Pls enter the key of node to be deleted " << endl;
            cin >> k1;
            s1.delete_Particular_key_node(k1);
            break;

        case 5:
            cout << " enter the key and data values for updation " << endl;
            cin >> key1;
            cin >> data1;
            n1->data = data1;
            n1->key = key1;
            s1.update_Node_given_key(key1, data1);
            break;

        case 6:
            cout << " Lets print this list " << endl;
            s1.printlist();
            break;

        case 7:
            system("cls");
            break;

        default:
            cout << "Enter valid option " << endl;
        }

    } while (option!=0);

    return 0;
}