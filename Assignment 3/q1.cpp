#include <iostream>
using namespace std;

int main()
{
    int arr[6] = {8, 6, 3, 8, -1, -70};
    int size = 6;

    for(int i = 0; i < size; i++)
    {
        for(int j = i + 1; j < size; j++)
        {
            if(arr[i] == arr[j])
            {
                cout << arr[i] << endl;
                break;
            }
        }
    }

    return 0;
}