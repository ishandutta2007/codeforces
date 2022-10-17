#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define INF 0x3f3f3f3f3f3f3f3f
#define MN 10000
#define N 300100
#define M 
using namespace std;

ll T,n,m,ans,sum,tot,num[N];
map<ll,bool>use;
map<P,bool>gg;
map<ll,ll>cnt;
vector<ll>have[N];
priority_queue<P>pq;

inline void Max(ll &u,ll v){if(v>u) u=v;}
inline void Min(ll &u,ll v){if(v<u) u=v;}
inline ll calc(ll u,ll v)
{
	ll i,j,r=-1,res=0;
	for(i=have[u].size()-1;i>=0;i--)
	{
		for(j=have[v].size()-1;j>r;j--)
		{
			if(u==v && i==j) continue;
			if(gg.count(mp(have[u][i],have[v][j]))) continue;
			Max(res,(u+v)*(have[u][i]+have[v][j]));
			r=j;
			break;
		}
	}
	return res;
}

int main()
{
	ll i,j,k,p,q;
	cin>>T;
	while(T--)
	{
		ans=0;
		use.clear(),cnt.clear(),gg.clear();
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&num[i]);
			cnt[num[i]]++;
			have[i].clear();
		}
		for(i=1;i<=m;i++)
		{
			scanf("%lld%lld",&p,&q);
			gg[mp(p,q)]=gg[mp(q,p)]=1;
		}
		for(i=1;i<=n;i++)
		{
			if(use.count(num[i])) continue;
			use[num[i]]=1;
			have[cnt[num[i]]].push_back(num[i]);
		}
		for(i=1;i<=n;i++) sort(have[i].begin(),have[i].end());
		for(i=1;i<=n;i++)
		{
			if(!have[i].size()) continue;
			for(j=i;j<=n;j++)
			{
				if(!have[j].size()) continue;
				Max(ans,calc(i,j));
			}
		}
		printf("%lld\n",ans);
	}
}