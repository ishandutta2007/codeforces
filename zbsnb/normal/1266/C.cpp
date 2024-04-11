#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
#define ll long long
// #define int long long

char s[1000010];
int a[1000010];
int b[1000010];

signed main(){
    int n,m;cin>>n>>m;
    if(n==1&&m==1)cout<<"0"<<endl;
    else if(n==1){
        for(int i=1;i<=m;i++)cout<<i+1<<" ";cout<<endl;
    }
    else if(m==1){
        for(int i=1;i<=n;i++)cout<<i+1<<endl;
    }
    else{
        for(int i=1;i<=n;i++){
            for(int j=n+1;j<=n+m;j++){
                cout<<i*j<<" ";
            }
            cout<<endl;
        }
    }
}