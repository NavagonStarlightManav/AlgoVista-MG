#include <iostream>
#include <cstdlib> // For rand()
using namespace std;

class Array_Operations
{
    int element, size;
    int capacity;
    int *array; // Pointer to dynamically allocated array

public:
    Array_Operations(int cap) : capacity(cap), size(0)
    {
        array = new int[capacity]; // Dynamically allocate array

        cout << "Please enter the size you want to use (must be <= " << capacity << "):" << endl;
        cin >> size;

        // Check if size is valid
        if (size > capacity)
        {
            cout << "Size cannot be greater than capacity. Setting size to capacity." << endl;
            size = capacity;
        }

        for (int i = 0; i < size; i++)
        {
            array[i] = rand(); // Assign random numbers
        }

        // Initialize remaining elements to 0 if size < capacity
        for (int i = size; i < capacity; i++)
        {
            array[i] = 0;
        }
    }

    ~Array_Operations()
    {
        delete[] array; // Free allocated memory
    }

    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << array[i] << " ";
        }
        cout << endl;
    }

    void insertion()
    {
        int position;
        cout << "Please enter the position where the element is to be inserted (0 to " << size << "):" << endl;
        cin >> position;

        if (position < 0 || position > size || size >= capacity)
        {
            cout << "Invalid position or array is full." << endl;
            return;
        }

        cout << "Please enter the element to be inserted:" << endl;
        cin >> element;

        for (int i = size; i > position; i--)
        {
            array[i] = array[i - 1];
        }
        array[position] = element;
        size++;
    }

    void deletion()
    {
        int position;

        cout << " Please enter the position where element is to be deleted " << endl;
        cin >> position;

        cout << " Currently Size is " << size << endl;

        if (position == size)
        {
            array[size - 1] = 0;
            cout << " Element deleted successfully at last posistion with Time Complexity of Big O Of O(1) " << endl;
            size--;
        }
        else
        {
            int option;
            cout << " Press 0 for swapping deleted space with last element and 1 for Shifting all elements towards left " << endl;
            cin >> option;

            if (option == 1)
            {
                array[position - 1] = 0;
                for (int i = position - 1; i < size; i++)
                {
                    array[i] = array[i + 1];
                }
                array[size] = 0;

                cout << "Element successsfully deleted at specified position with time complexity of big O of O(" << size << ")" << endl;
            }

            else if (option == 0)
            {

                array[position - 1] = array[size - 1];
                array[size - 1] == 0;
                cout << "Element Successfully Deleted with Time Complexity of big O of O(1)" << endl;
            }
            size--;
        }
    }

    void show_size()
    {
        cout << "Current size is " << size << endl;
    }
};

int main()
{
    int capacity;
    cout << "Please enter the capacity of the array:" << endl;
    cin >> capacity;

    if (capacity <= 0)
    {
        cout << "Capacity must be a positive integer." << endl;
        return 1;
    }

    Array_Operations exp1(capacity);

    int choice;
    do
    {
        cout << "Please enter your choice:" << endl;
        cout << "0 for Size" << endl;
        cout << "1 for Display" << endl;
        cout << "2 for Insertion" << endl;
        cout << "3 for Deletion" << endl;
        cout << "5 for Exit" << endl;

        cin >> choice;

        switch (choice)
        {
        case 0:
            exp1.show_size();
            break;
        case 1:
            exp1.display();
            break;
        case 2:
            exp1.insertion();
            break;
        case 3:
            exp1.deletion();
            break;
        case 5:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice." << endl;
            break;
        }
    } while (choice != 5);

    return 0;
}
