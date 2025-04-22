#include <iostream>
using namespace std;
int board[20][20];
int col[20];
int ldig[30];
int rdig[30];
int n;
int cnt=0;
bool check(int i,int j);
void place(int i,int j);
void dfs(int i,int j);




int main() {
    cin>>n;
    for(int i=0;i<n;i++){
        dfs(0,i);
    }
    cout<<cnt;
}


bool check(int i,int j) {
    if(!col[j]&&!ldig[n-(i-j)-1]&&!rdig[i+j]) return 1;
    else return 0;
}

void place(int i,int j) {
    col[j]=1;
    ldig[n-(i-j)-1]=1;
    rdig[i+j]=1;
    return;
}

void unplace(int i,int j) {
    col[j]=0;
    ldig[n-(i-j)-1]=0;
    rdig[i+j]=0;
    return;
}

void dfs(int i,int j) {
    if(i==n-1) {
        cnt++; 
        return;
    }
    place(i,j);
    for(int k=0;k<n;k++) {
        if(check(i+1,k)) {
            dfs(i+1,k);
        } 
    }
    unplace(i,j);
    return;
}