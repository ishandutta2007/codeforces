#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define sz(x) (int)(x.size())
#define PII pair<int,int>
#define ll long long
#define pb push_back
//#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2))?EOF:*p1++;
#define gc getchar()
#define iter set<int>::iterator
using namespace std;
char buf[100000],*p1=buf,*p2=buf;
inline int gi()
{
	int x=0,f=1;char ch=gc;
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=gc;}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48),ch=gc;}
	return (f==1)?x:-x;
}
const int maxn=3e5+5;
int pre[maxn],s,n,m,lst[maxn];
ll dis[maxn];
vector<pair<int,pair<int,int>>>e[maxn];
struct node{int u;ll dis;inline bool operator < (const node &b)const{return dis>b.dis;}};
priority_queue<node>pq;
ll ans;
inline void input()
{
	n=gi(),m=gi();
	FOR(i,1,m)
	{
		int u=gi(),v=gi(),w=gi();
		e[u].pb({i,{v,w}});
		e[v].pb({i,{u,w}});
	}
	s=gi();
}
bool vis[maxn];
inline void dijkstra(int u)
{
	pq.push({u,0});
	memset(dis,0x3f,sizeof(dis));
	dis[u]=0;
	while(!pq.empty())
	{
		int u=pq.top().u;pq.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto x:e[u])
		{
			int id=x.first,v=x.second.first,w=x.second.second;
			if(dis[v]>dis[u]+w)
			{
				ans-=lst[v],ans+=w;
				dis[v]=dis[u]+w;
				pre[v]=id;lst[v]=w;
				pq.push({v,dis[v]});
			}
			else if(dis[v]==dis[u]+w&&w<lst[v])
			{
				pre[v]=id;
				ans-=lst[v];ans+=w;
				lst[v]=w;		
			}
		}
	}
}
inline void solve()
{
	dijkstra(s);
	printf("%lld\n",ans);
	vector<int>answers;
	FOR(i,1,n)if(i!=s)answers.pb(pre[i]);
	sort(answers.begin(),answers.end());
	for(int x:answers)printf("%d ",x);
}
int main()
{
	input();
	solve();
	return 0;
}