#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

int n,c;
int arr[200'001];

int find(int x);

int main() {
    cin>>n>>c;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int ans;
    int left=1,right=(arr[n-1]-arr[0])/(c-1);
    while(left<right){
        int mid=(left+right)/2;
        int cnt=1;
        int prev=arr[0];
        while (prev+mid<=arr[n-1]) {
            int k = find(prev+mid);
            prev=arr[k];
            cnt++;
        }
        if(cnt>=c) {
            left=mid+1;
            ans=mid;
        }
        else {
            right=mid;
        }
    }
    cout<<ans;
}

int find(int x) {
    int left=0;
    int right=n-1;
    int mid=(left+right)/2;
    while(left<right){
        mid=(left+right)/2;
        if(arr[mid]<=x) {
            if(arr[mid]==x) return mid;
            left=mid+1;
        }
        else {
            right=mid;
        }
    }
    return left;
}