#include<bits/stdc++.h>
#define ll long long
#define P pair<ll,ll>
#define PP pair<P,P>
#define mp make_pair
#define fi first
#define se second
#define INF 0x3f3f3f3f3f3f3f3f
#define N 510
using namespace std;
 
ll T,n,m,K,tt,d[N*N];
bool vis[N*N];
vector<P>to[N*N];
map<P,ll>mm;
map<PP,ll>have;
priority_queue<P,vector<P>,greater<P> >pq;
 
int main()
{
	memset(d,0x3f,sizeof(d));
	ll i,j,p,q,a,b,t;
	cin>>T;
	while(T--)
	{
		for(i=1;i<=tt;i++) to[i].clear(),d[i]=INF,vis[i]=0;
		tt=0,mm.clear(),have.clear();
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld%lld",&p,&q,&a,&b);
			have[mp(mp(p,q),mp(a,b))]++;
			have[mp(mp(a,b),mp(p,q))]++;
		}
		for(i=2;i<=m;i++) for(j=2;j<=m;j++) mm[mp(i,j)]=++tt;tt++;
		for(i=1;i<=m+1;i++) mm[mp(1,i)]=mm[mp(m+1,i)]=mm[mp(i,1)]=mm[mp(i,m+1)]=tt;
		for(i=2;i<=m;i++)
		{
			for(j=2;j<=m;j++)
			{
				t=mm[mp(i,j)];
				to[t].push_back(mp(mm[mp(i,j-1)],have[mp(mp(i-1,j-1),mp(i,j-1))]+have[mp(mp(m-i+2,m-j+2),mp(m-i+1,m-j+2))]));
				to[t].push_back(mp(mm[mp(i-1,j)],have[mp(mp(i-1,j-1),mp(i-1,j))]+have[mp(mp(m-i+2,m-j+2),mp(m-i+2,m-j+1))]));
				to[t].push_back(mp(mm[mp(i,j+1)],have[mp(mp(i,j),mp(i-1,j))]+have[mp(mp(m-i+1,m-j+1),mp(m-i+2,m-j+1))]));
				to[t].push_back(mp(mm[mp(i+1,j)],have[mp(mp(i,j),mp(i,j-1))]+have[mp(mp(m-i+1,m-j+1),mp(m-i+1,m-j+2))]));
			}
		}
		ll S=mm[mp(m/2+1,m/2+1)],T=mm[mp(1,1)];
		pq.push(mp(d[S]=0,S));
		for(;!pq.empty();)
		{
			P now=pq.top();
			pq.pop();
			if(vis[now.se]) continue;
			vis[now.se]=1;
			for(i=0;i<to[now.se].size();i++)
			{
				P tmp=to[now.se][i];
				if(d[tmp.fi]<=d[now.se]+tmp.se) continue;
				d[tmp.fi]=d[now.se]+tmp.se;
				pq.push(mp(d[tmp.fi],tmp.fi));
			}
		}
		printf("%lld\n",n-d[T]);
	}
}