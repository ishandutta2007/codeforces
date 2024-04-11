#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,k;cin>>n>>k;
    int l,r;cin>>l>>r;
    ll minn=1e18,maxn=0;
    ll tot=1ll*n*k;
    for(int i=0;i<n;i++){
        ll p1=abs(1ll*i*k+r-l);
        ll p2=abs(1ll*i*k+l+r);
        ll g1=__gcd(tot,p1);
        ll g2=__gcd(tot,p2);
        minn=min(minn,tot/g1);
        minn=min(minn,tot/g2);
        maxn=max(maxn,tot/g1);
        maxn=max(maxn,tot/g2);
    }
    cout<<minn<<" "<<maxn<<endl;
}