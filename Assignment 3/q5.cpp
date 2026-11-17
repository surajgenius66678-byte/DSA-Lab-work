#include <iostream>
using namespace std;

int main()
{
    int arr[7] = {1, 7, 3, 6, 0, 5, 6};
    int size = 7;

    int sumleft = 0;
    int sumright = 0;

    for(int i = 0; i < size; i++)
    {
        sumright += arr[i];
    }

    for(int i = 0; i < size; i++)
    {
        sumright -= arr[i];

        if(sumleft == sumright)
        {
            cout << "at " << i << endl;
        }

        sumleft += arr[i];
    }

    return 0;
}