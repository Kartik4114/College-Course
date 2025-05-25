#include <iostream>
#include <climits>
#include <unordered_map>
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
        int min = INT_MAX;
        int minindex = -1;

        for (int i = 0; i < blocks; i++)
        {
            if (arr[i] < min && arr[i] >= mp[j])
            {
                min = arr[i];
                minindex = i;
            }
        }

        arr[minindex] = arr[minindex] - mp[j];
        j++;
    }

    cout << "Memory left after usage is : " << endl;
    cout << endl;
    for (int i = 0; i < blocks; i++)
    {
        cout << i << "block has :" << arr[i] << " bytes left" << endl;
    }
    cout << endl;
    return 0;
}

    // 4
    // 20 200 500 50
    // 4
    // 30 50 200 700