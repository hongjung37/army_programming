/*
#include <cmath>
#include <iostream>
using namespace std;

int n;
int dp1[1001];
int dp2[1001];
int arr[1001];

int main() {
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        dp1[i]=1;
        dp2[i]=1;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j]) {
                dp1[i]=max(dp1[j]+1,dp1[i]);
            }
        }
    }
    for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>i;j--){
            if(arr[i]>arr[j]) {
                dp1[i]=max(dp1[j]+1,dp1[i]);
            }
        }
    }
    int mx=1;
    for(int i=0;i<n;i++){
        mx=max(mx,dp1[i]+dp2[i]-1);
    }
    
    cout<<mx;
}