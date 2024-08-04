#include <iostream>
#include <bitset>
using namespace std;

int main()
{
    int arr[8], i, n;
    cout << " Pls enter 8 consecutive numbers " << endl;
    for (i = 0; i < 8; i++)
    {
        cin >> arr[i];
    }

    bitset<32> binary_arr[8];

    for (i = 0; i < 7; i++)
    {
        binary_arr[i] = bitset<32>(arr[i]);

        bool last_bit_num1 = arr[i] & 1;     // Last bit of num1
        bool last_bit_num2 = arr[i + 1] & 1; // Last bit of num2

        // Check if both last bits are the same
        if (last_bit_num1 == last_bit_num2)
        {
            cout << "These numbers arent consecutive " << arr[i] << " and " << arr[i + 1] << endl;
            cout<<" Number missing lies between " << arr[i] << " and " << arr[i + 1] << endl;
        }
    }
}