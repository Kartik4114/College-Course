#include <iostream>
#include <unordered_map>
#include <climits>
using namespace std;

int main()
{
    int p;
    cout << "Enter the no. of processes:" << endl;
    cin >> p;

    unordered_map<int, int> mp;
    cout << "Enter the size of processes:" << endl;

    for (int i = 0; i < p; i++)
    {
        int p_size;
        cin >> p_size;
        mp[i] = p_size;
    }

    int blocks;
    cout << "Enter no. of blocks :" << endl;
    cin >> blocks;

    int arr[blocks];
    cout << "Enter the size of Blocks :" << endl;
    for (int i = 0; i < blocks; i++)
    {
        cin >> arr[i];
    }
    // Process Starts

    int j = 0;
    while (j < p)
    {
        int max = INT_MIN;
        int maxindex = -1;

        for (int i = 0; i < blocks; i++)
        {
            if (arr[i] > max && arr[i] >= mp[j])
            {
                max = arr[i];
                maxindex = i;
            }
        }

        arr[maxindex] = arr[maxindex] - mp[j];
        j++;
    }

    cout << "Memory left after usage is : " << endl;
    for (int i = 0; i < blocks; i++)
    {
        cout << i << "block has :" << arr[i] << " bytes left" << endl;
    }
    cout << endl;
    return 0;
}

// 3
// 30 100 45
// 3
// 45 100 400