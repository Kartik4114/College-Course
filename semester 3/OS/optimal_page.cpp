#include <iostream>
#include <unordered_map>
#include <queue>
#include <climits>
using namespace std;

int find(vector<int> f, int p[], int n, int ci)
{

    unordered_map<int, int> mp;

    for (int i = 0; i < f.size(); i++)
    {
        mp[f[i]] = 0; // Initialize counts to zero
    }

    for (int i = ci; i < n; i++)
    {
        mp[p[i]]=n-i;
    }

    int min = INT_MAX;
    int minindex = -1;
    for (int i = 0; i < f.size(); i++)
    {
        if (mp[f[i]] < min)
        {
            min = mp[f[i]];
            minindex = i;
        }
    }
    return minindex;
}

int main()
{

    unordered_map<int, bool> check;

    int n;
    cout << "Enter no. of processes :" << endl;
    cin >> n;

    int p[n];
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }

    int f_size;
    cout << "Enter frame size:" << endl;
    cin >> f_size;

    vector<int> f;

    int hit = 0;
    for (int i = 0; i < n; i++)
    {
        if (check[p[i]])
        {
            hit++;
            continue;
        }
        if (f.size() == f_size)
        {
            int minindex = find(f, p, n, i);
            check[f[minindex]] = false;
            f[minindex] = p[i];
            check[p[i]] = true;
            continue;
        }
        f.push_back(p[i]);
        check[p[i]] = true;
    }

    cout << "Hit count are : " << hit << endl;
    cout << "Miss count are : " << n-hit << endl;

    return 0;
}

// 13
// 7 0 1 2 0 3 0 4 2 3 0 3 2
// 4