#include <iostream>
using namespace std;

int main()
{
    int arr[15] = {1, 2, 3, 4, 4, 4, 5, 5,
                   6, 7, 7, 7, 7, 7, 8};

    int size = 15;

    int result[30];
    int rsize = 0;
    int count = 1;

    for(int i = 0; i < size - 1; i++)
    {
        if(arr[i] == arr[i + 1])
        {
            count++;
        }
        else
        {
            result[rsize] = arr[i];
            result[rsize + 1] = count;

            rsize += 2;
            count = 1;
        }
    }

    result[rsize] = arr[size - 1];
    result[rsize + 1] = count;
    rsize += 2;

    for(int i = 0; i < rsize; i++)
    {
        cout << result[i] << ",";
    }

    cout << endl;

    return 0;
}