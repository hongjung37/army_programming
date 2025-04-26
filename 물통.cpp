#include <iostream>
#include <cmath>
using namespace std;
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long x,N;
    cin>>x>>N;
    long* arr=new long[N];
    long left=0,right=x;
    long ln=0,rn=x;
    for(int i=0;i<N;i++) {
        cin>>arr[i];
        if(right+arr[i]>x) {
            rn=max((long)0,rn-right-arr[i]+x);
            right=x;
            left=min(x,left+arr[i]);
        }
        else if(left+arr[i]<0) {
            ln=min(x,ln-left-arr[i]);
            left=0;
            right=max(right+arr[i],(long)0);
        }
        else {
            left+=arr[i];
            right+=arr[i];
        }
    }
    
    long m;
    cin>>m;
    for(long i=0;i<m;i++) {
        long num;
        cin>>num;
        if(num<=ln) cout<<left;
        else if (num<rn) cout<<left+num-ln;
        else cout<<right;
        cout<<"\n";
    }
    free(arr);
}

