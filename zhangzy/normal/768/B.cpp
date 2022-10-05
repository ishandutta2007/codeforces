#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,l,r,ans=0;

ll len(ll x){
    return ( (ll)1<<((int)log2(x)+1) )-1;
}

void doit(ll x,ll st,ll en){
    if (en<l) return;
    if (st>r) return;
    
    if (x<=1){
        ans+=x;
        return;
    }
    
    ll l=len(x>>1);
    doit(x>>1,st,st+l-1);
    doit(x&1,st+l,st+l);
    doit(x>>1,st+l+1,en);
}

int main(){
    cin>>n>>l>>r;
    doit(n,1,len(n));
    cout<<ans;
}