#include <iostream>
#include <stack>
using namespace std;
int board[20][20];
int col[20];
int ldig[30];
int rdig[30];
int n;
stack<pair<int,int>> s;
int cnt=0;
bool check(int i,int j);
void place(int i,int j);
void dfs();




int main() {
    cin>>n;
    for(int i=0;i<n;i++){
        s.push(make_pair(0,i));
    }
    dfs();
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

void dfs() {
    int i=s.top().first;
    int j=s.top().second;
    if(i==n-1) {
        cnt++; 
        return;
    }
    s.pop();
    place(i,j);
    for(int k=0;k<n;k++) {
        if(check(i+1,k)) {
            s.push(make_pair(i+1,k));
            dfs();
        } 
    }
    deplace(i,j);
    return;
}