#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int arr[8];
    int n = 8;

    cout << "Please enter values" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int max_volume = 0;
    int difference_height,n1,m;

    // Brute force approach
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int height = min(arr[i], arr[j]);
            int width = j - i;
            int volume = height * width;
            if (volume > max_volume) 
            {
                max_volume = volume;
                n1 = i;
                m = j;
            }
        }
    }

    cout << "Maximum volume: " << max_volume << " Given by " << n1 <<" and " << m<< endl;
    difference_height=abs(arr[m]-arr[n1]);
    cout << " Triangular volume is " << abs(m-n1)*difference_height/2;


    return 0;
}
