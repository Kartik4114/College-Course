#include <iostream>
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

    // Process starts
    int j = 0;
    while (j < p)
    {
        for (int i = 0; i < blocks; i++)
        {
            if (mp[j] <= arr[i])
            {
                arr[i] = arr[i] - mp[j];
                break;
            }
        }
                j++;
    }


    // Printing

    cout<<"Memory left after usage is : "<<endl;
    for (int i = 0; i < blocks; i++)
    {
        cout<<i<<"block has :"<<arr[i]<<" bytes left"<<endl;
    }
    cout<<endl;
    

    return 0;
}
// 4
// 20 200 500 50
// 4
// 30 50 200 700