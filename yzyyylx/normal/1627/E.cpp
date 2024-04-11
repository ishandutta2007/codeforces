#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define INF 0x3f3f3f3f3f3f3f3f
#define MN 1000000
#define N 500100
#define M
using namespace std;
 
ll T,n,m,K,ans,tt,x[N],d[N],num[N],X[N];
bool vis[N];
map<P,ll>mm;
vector<ll>have[N];
vector<P>to[N];
priority_queue<P,vector<P>,greater<P> >pq;
 
inline void Min(ll &u,ll v){if(v<u) u=v;}
int main()
{
	memset(d,0x3f,sizeof(d));
	ll i,j,k,a,b,p,q,t;
	cin>>T;
	while(T--)
	{
		for(i=1;i<=tt;i++) to[i].clear(),d[i]=INF,vis[i]=0;
		tt=0,mm.clear();
		scanf("%lld%lld%lld",&m,&n,&K);
		for(i=1;i<=m;i++) have[i].clear();
		for(i=1;i<=m;i++) scanf("%lld",&x[i]);
		mm[mp(1,1)]=++tt,mm[mp(m,n)]=++tt;
		have[1].push_back(1ll);
		have[m].push_back(n);
		for(i=1;i<=K;i++)
		{
			scanf("%lld%lld%lld%lld%lld",&a,&b,&p,&q,&t);
			if(!mm.count(mp(a,b))) have[a].push_back(b),mm[mp(a,b)]=++tt;
			if(!mm.count(mp(p,q))) have[p].push_back(q),mm[mp(p,q)]=++tt;
			to[mm[mp(a,b)]].push_back(mp(mm[mp(p,q)],-t));
		}
		/*
		for(i=1;i<=m;i++)
		{
			sort(have[i].begin(),have[i].end());
			for(j=0;j<(ll)have[i].size()-1;j++)
			{
//				cout<<i<<" "<<j<<" "<<have[i].size()<<" "<<(j<(ll)have[i].size()-1)<<endl;
				p=mm[mp(i,have[i][j])],q=mm[mp(i,have[i][j+1])];
				t=x[i]*(have[i][j+1]-have[i][j]);
//				cout<<" "<<p<<" "<<q<<" "<<t<<endl;
				to[p].push_back(mp(q,t));
				to[q].push_back(mp(p,t));
			}
		}
		//*/
		d[mm[mp(1,1)]]=0;
		for(i=1;i<=m;i++)
		{
			sort(have[i].begin(),have[i].end());
			ll mn=INF;
			for(j=0;j<have[i].size();j++)
			{
				t=have[i][j];
				Min(d[mm[mp(i,t)]],mn+x[i]*t);
				Min(mn,d[mm[mp(i,t)]]-x[i]*t);
//				cout<<i<<" "<<have[i][j]<<" "<<d[mm[mp(i,have[i][j])]]<<endl;
			}
			mn=INF;
			for(j=(ll)have[i].size()-1;j>=0;j--)
			{
				t=have[i][j];
				Min(d[mm[mp(i,t)]],mn+(n-t)*x[i]);
				Min(mn,d[mm[mp(i,t)]]-(n-t)*x[i]);
			}
			for(j=0;j<have[i].size();j++)
			{
				t=mm[mp(i,have[i][j])];
				for(k=0;k<to[t].size();k++)
				{
					Min(d[to[t][k].fi],d[t]+to[t][k].se);
				}
			}
		}
		if(d[mm[mp(m,n)]]>1e16) puts("NO ESCAPE");
		else printf("%lld\n",d[mm[mp(m,n)]]);
	}
}