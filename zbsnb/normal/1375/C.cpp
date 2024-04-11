#include<bits/stdc++.h>
using namespace std;
int vis[1000010];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int a,b;
        for(int i=1;i<=n;i++){
            int tmp;cin>>tmp;
            if(i==1)a=tmp;
            if(i==n)b=tmp;
        }
        cout<<(a<b?"YES":"NO")<<endl;
    }
}