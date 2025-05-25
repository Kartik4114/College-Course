#include <iostream>
#include <unordered_map>
#include <queue>
#include <climits>
using namespace std;

int find_min(vector<int> f, unordered_map<int, int> mp)
{
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

    unordered_map<int, int> mp;

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
        if (mp[p[i]] > 0)
        {
            mp[p[i]] = i + 1;
            hit++;
            continue;
        }

        if (f.size() == f_size)
        {

            int minindex = find_min(f, mp);
            mp[f[minindex]] = 0;
            f[minindex] = p[i];
            mp[p[i]] = i + 1;
            continue;
        }

        f.push_back(p[i]);
        mp[p[i]] = i + 1;
    }

    cout << "Hit count is :" << hit << endl;
    cout << "Miss count is :" << n-hit << endl;
    return 0;
}

// 14
// 7 0 1 2 0 3 0 4 2 3 0 3 2 3
// 4