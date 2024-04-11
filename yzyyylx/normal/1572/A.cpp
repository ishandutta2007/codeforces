#include<bits/stdc++.h>
#define ll long long
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define N 2001000
#define MN 2000000
using namespace std;

ll T,n,m,ans,num[N],deep[N],mx[N];
vector<ll>to[N];
priority_queue<P,vector<P>,greater<P> >pq;

int main()
{
	ll i,j,p,q,t;
	cin>>T;
	while(T--)
	{
		ans=0;
		scanf("%lld",&n);
		for(i=1;i<=n;i++) to[i].clear(),deep[i]=mx[i]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&t);
			num[i]=t;
			for(j=1;j<=t;j++)
			{
				scanf("%lld",&p);
				to[p].push_back(i);
				mx[i]=max(mx[i],p);
			}
			if(!t)
			{
				pq.push(mp(1,i));
				deep[i]=1;
			}
		}
		for(;!pq.empty();)
		{
			ll now=pq.top().se;
			pq.pop();
			ans=max(ans,deep[now]);
			for(i=0;i<to[now].size();i++)
			{
				t=to[now][i];
				num[t]--;
				if(!num[t])
				{
					deep[t]=deep[now]+(t<now);
					pq.push(mp(deep[t],t));
				}
			}
		}
		for(i=1;i<=n;i++) if(!deep[i]) break;
		if(i<=n) puts("-1");
		else printf("%lld\n",ans);
	}
}