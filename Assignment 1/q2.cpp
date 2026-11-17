
#include <iostream>
#include <vector>
using namespace std;

int target, size, ans = 0;
vector<int> arr, subset;

void dfs(int i, int sum)
{
    if (sum == target)
    {
        ans++;

        cout << "Subset " << ans << " -> ";

        for (int x : subset)
            cout << x << " ";

        cout << endl;
        return;
    }

    if (sum > target || i == size)
        return;

    subset.push_back(arr[i]);

    dfs(i + 1, sum + arr[i]);

    subset.pop_back();

    dfs(i + 1, sum);
}

int main()
{
    cout << "Enter the size of the array: ";
    cin >> size;

    if (size < 0)
        return 0;

    arr.resize(size);

    cout << "Enter the elements of the array: ";

    for (int i = 0; i < size; i++)
        cin >> arr[i];

    cout << "Enter the target sum: ";
    cin >> target;

    dfs(0, 0);

    cout << "Number of Subsets = " << ans << endl;

    return 0;
}
