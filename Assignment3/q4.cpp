#include <iostream>
using namespace std;

int main()
{
    int arr[6] = {8, 6, 3, 8, -1, -70};
    int size = 6;

    for(int i = 0; i < size; i++)
    {
        if(arr[i] < 0)
        {
            int temp = arr[i];

            for(int j = i; j > 0; j--)
            {
                arr[j] = arr[j - 1];
            }

            arr[0] = temp;
        }
    }

    for(int i = 0; i < size; i++)
    {
        cout << arr[i] << ",";
    }

    cout << endl;

    return 0;
}