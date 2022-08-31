#include <bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(int)N;i++)
using ll = long long;
using namespace std;

int main(){
    int N;
    cin>>N;
    ll a=1,b=1;
    for(int x=2;x*x<=N;x++){
        if(N%x==0){
            ll n = N;
            while(n%x==0) n/=x;
            a = n, b = N/n;
            break;
        }
    }
    if(a>b) swap(a,b);
    if(a==1){
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    for(ll x=0;x<a;x++){
        ll ya = a*b-1-x*b;
        if(ya%a==0){
            ll y = ya/a;
            cout<<2<<endl;
            cout<<x<<" "<<a<<endl;
            cout<<y<<" "<<b<<endl;
            return 0;
        }
    }
}