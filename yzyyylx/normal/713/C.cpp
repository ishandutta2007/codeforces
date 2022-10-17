#include<bits/stdc++.h>
#define ll long long
#define N 3010
using namespace std;

ll n,m,ans,lx;
multiset<ll>mu;

int main()
{
    ll i,j,t;
    cin>>n;
    for(i=1;i<=n;i++)
    {
	scanf("%lld",&t);t-=i-N;
	mu.insert(t),mu.insert(t);
	lx++,ans+=t;
//	for(;lx>i;lx--) ans-=(*mu.begin()),mu.erase(mu.begin());
	for(;-lx+mu.size()>0;) mu.erase(--mu.end());
    }
    for(;lx;lx--) ans-=(*mu.begin()),mu.erase(mu.begin());
    cout<<ans;
}