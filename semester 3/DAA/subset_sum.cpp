#include<bits/stdc++.h>
using namespace std;

int solve(int arr[],int n,int k,int index,int sum){

    if(index==n){
        if(sum==k){
            return 1;
        }
        return 0;
    }

        int opt1=solve(arr, n, k, index+1, sum+arr[index]);
        int opt2=solve(arr, n, k, index+1, sum);

        return opt1+opt2;
}

int subsetSum(int arr[],int n,int k){
    int ans=solve(arr,n,k,0,0);
    return ans;
}

int main(){
    
    int test;
    cin>>test;
    while(test>0){

    int n,k;
    cin>>n>>k;
    int arr[n];

    for (int i = 0; i < n; i++) {
            cin >> arr[i];
    }

    int output = subsetSum(arr, n, k);
    cout << output << endl;

    test--;
    }

    return 0;
}