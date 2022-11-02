#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        int m,d,w;cin>>m>>d>>w;
        if(d==1){
            cout<<0<<endl;
            continue;
        }
        int x=w/__gcd(d-1,w);
        int y=min(m,d)/x;
        int r=min(m,d)%x;
        // cout<<"x:"<<x<<endl;
        if(y==0){
            cout<<0<<endl;
            continue;
        }
        cout<<((y-1)*y/2*x+r*y)<<endl;
    }
}