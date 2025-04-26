#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;


int arr[100'001];
int ans;
int curr[5]={1,0,0,0,0};

int st(int i) {
    if(i==1) {
        if(curr[2]) return 2;
        else if(curr[4]) return 4;
    }
    else if(i==2) {
        if(curr[1]) return 1;
        else if(curr[3]) return 3;
    }
    else if(i==3) {
        if(curr[2]) return 2;
        else if(curr[4]) return 4;
    }
    else if(i==4) {
        if(curr[1]) return 1;
        else if(curr[3]) return 3;
    }
    return 0;
}

int ln(int i) {
    int k=st(i);
    for(int j=1;j<=4;j++){
        if(j!=k,curr[i]) return j; 
    }
    return 0;
}
int main() {
    int buff=1,cnt=0;
    while(buff) {
        cin>>buff;
        if(!buff) break;
        arr[cnt++]=buff;
    }
    curr[arr[0]]=1;
    ans+=2;
    for(int i=1;i<cnt;i++){
        if(curr[arr[i]]) ans++;
        else {
            int s=st(arr[i]);
            int l=ln(arr[i]);
            if(s==0) {
                ans+=2;
                curr[s]=0;
                curr[arr[i]]=1;
                continue;
            }
            if(arr[i+1]==l) {
                ans+=4;
                curr[l]=0;
                curr[arr[i]]=1;
            }
            else {
                ans+=3;
                curr[s]=0;
                curr[arr[i]]=1;
            }
        } 
    }
    cout<<ans;

}