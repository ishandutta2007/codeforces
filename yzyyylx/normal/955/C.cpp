#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define ll long long
#define MX (ll)1e18
using namespace std;

ll T;
map<ll,bool>mm;
vector<ll>num;

inline bool pf(ll u){ll t=sqrt(u);return t*t==u;}
int main()
{
    ll i,j,p,q;
    for(i=2;i<=1000000;i++)
    {
	ll t=i*i*i,mx;
	mx=MX/i;
	for(;;)
	{
	    if(!pf(t)&&!mm.count(t)) num.push_back(t),mm[t]=1;
	    if(t>mx) break;
	    t*=i;
	}
    }
//    return 0;
    sort(num.begin(),num.end());
    cin>>T;
    while(T--)
    {
	scanf("%lld%lld",&p,&q);
	ll ans=upper_bound(num.begin(),num.end(),q)-lower_bound(num.begin(),num.end(),p);
	printf("%lld\n",ans+(ll)sqrt(q)-(ll)sqrt(p-1));
    }
}