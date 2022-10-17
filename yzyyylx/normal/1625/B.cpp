#include<bits/stdc++.h>
#define ll long long
#define N 300100
using namespace std;
 
ll T,n,m,ans,num[N],cnt[N];
map<ll,ll>pos;
 
inline void calc(ll u,ll v){ans=max(ans,u+n-v);}
int main()
{
	ll i,j;
	cin>>T;
	while(T--)
	{
		pos.clear();
		ans=-1;
		scanf("%lld",&n);
		for(i=1;i<=n;i++) scanf("%lld",&num[i]);
		for(i=1;i<=n;i++)
		{
			if(pos.count(num[i])) calc(pos[num[i]],i);
			pos[num[i]]=i;
		}
		printf("%lld\n",ans);
	}
}