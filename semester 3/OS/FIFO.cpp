#include<iostream>
#include<unordered_map>
#include<queue>
using namespace std;

int main() {
    
    unordered_map<int,bool>mp;

    int n;
    cout<<"Enter no. of processes :"<<endl;
    cin>>n;

    queue<int>q;
    int p[n];

    for (int i = 0; i < n; i++)
    {
        cin>>p[i];
    }

    int f_size;
    cout<<"Enter frame size:"<<endl;
    cin>>f_size;

    int miss=0;
    int hit=0;
    for (int i = 0; i < n; i++)
    {
        if(mp[p[i]]==true){
            hit++;
            continue;
        }

        if(q.size()==f_size){
            int front=q.front();
            q.pop();
            mp[p[front]]=false;
        }

        q.push(p[i]);
        mp[p[i]]=true;

    }
    
    cout<<"No. of hits are: "<<hit<<endl;
    cout<<"No. of misses are: "<<n-hit<<endl;

    return 0;
}