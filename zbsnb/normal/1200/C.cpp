#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long

ll n,m;int q;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int main(){
    cin>>n>>m>>q;
    ll gcd1=gcd(n,m);
    ll base1=n/gcd1;
    ll base2=m/gcd1;
    for(int i=1;i<=q;i++){
        ll a,b,c,d;cin>>a>>b>>c>>d;

        if(a==1) a=(b-1)/base1;
        else a=(b-1)/base2;

        if(c==1) c=(d-1)/base1;
        else c=(d-1)/base2;

        if(a==c)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}