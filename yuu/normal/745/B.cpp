#include <iostream>
#include <stdio.h>
using namespace std;
int n, m;
bool a[501][501];
string s;
int main(){
//    freopen("B.INP", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    int lbound=m, ubound=n;
    int dbound=1;
    int rbound=1;
    for(int i=1; i<=n; i++){
        cin>>s;
        for(int j=0; j<m; j++)
            if(s[j]=='X'){
                a[i][j+1]=1;
                rbound=max(rbound, j+1);
                lbound=min(lbound, j+1);
                ubound=min(ubound, i);
                dbound=max(dbound, i);
            }
    }
    for(int i=ubound; i<=dbound; i++){
        for(int j=lbound; j<=rbound; j++){
            if(a[i][j]==0){
                cout<<"NO";
                return 0;
            }
        }
    }
    cout<<"YES";
}