#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        int a,b,c,d;cin>>a>>b>>c>>d;
        if(c<a){
            swap(a,c);
            swap(b,d);
        }
        int x,y;
        // cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
        if(b<c)x=c-b,y=d-a;
        else if(b<d) x=0,y=c-a+d-b,k-=n*(b-c);
        else x=0,y=b-d+c-a,k-=n*(d-c);
        if(k<=0){
            cout<<0<<endl;
            continue;
        }
        if(y==0){
            cout<<2*k<<endl;
            continue;
        }
        int cnt=min(n,k/y);
        // cout<<x<<" "<<y<<" "<<cnt<<endl;
        if(cnt==n){
            cout<<cnt*(x+y)+2*(k-cnt*y)<<endl;
        }
        else if(cnt==0){
            cout<<(x+k)<<endl;
        }
        else{
            cout<<cnt*(x+y)+min(2*(k-cnt*y),x+(k-cnt*y))<<endl;
        }
    }
}