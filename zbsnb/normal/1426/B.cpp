#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int t;cin>>t;
    while(t--){
        int n,m;cin>>n>>m;
        int flg=0;
        for(int i=1;i<=n;i++){
            int a,b,c,d;cin>>a>>b>>c>>d;
            if(b==c) flg=1;
        }
        cout<<(flg&&m%2==0?"YES":"NO")<<endl;
    }
}