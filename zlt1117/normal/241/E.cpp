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
const int maxn=5005;
int vis[maxn];
vector<int>e[maxn];
vector<pair<int,int>>ne[maxn];
int n,m,u[maxn],v[maxn];
bool ok[maxn];
inline void input()
{
	n=gi(),m=gi();
	FOR(i,1,m)
	{
		u[i]=gi(),v[i]=gi();
		e[u[i]].pb(v[i]);
	}
	queue<int>q;q.push(1);
	while(!q.empty())
	{
		int u=q.front();q.pop();
		for(int v:e[u])if(!vis[v])q.push(v),vis[v]++; 
	}
	FOR(i,1,n)e[i].clear();
	FOR(i,1,m)e[v[i]].pb(u[i]);
	q.push(n);
	while(!q.empty())
	{
		int u=q.front();q.pop();
		for(int v:e[u])if(!ok[v])q.push(v),vis[v]++,ok[v]=1; 
	}
	vis[1]++,vis[n]++;
}
int cnt[maxn],dis[maxn],in[maxn];
inline bool spfa()
{
	queue<int>q;
	FOR(i,1,n)q.push(i),cnt[i]=1;
	while(!q.empty())
	{
		int u=q.front();in[u]=0,q.pop();
		for(auto x:ne[u])
		{
			int v=x.first,w=x.second;
			if(dis[v]>dis[u]+w)
			{
				dis[v]=dis[u]+w;
				if(!in[v])in[v]=1,cnt[v]++,q.push(v);
				if(cnt[v]>n)return false; 
			 } 
		}
	}
	return true;
}
inline void solve()
{
	//FOR(i,1,n)printf("vis[%d]=%d\n",i,vis[i]);
	if(vis[1]!=2||vis[n]!=2)puts("No");
	else
	{
		FOR(i,1,m)
		{	
			if(vis[u[i]]==2&&vis[v[i]]==2)
			{
				ne[u[i]].pb({v[i],2});
				ne[v[i]].pb({u[i],-1});
			}
		}	
		if(!spfa())puts("No");
		else
		{
			puts("Yes");
			FOR(i,1,m)
			{
				if(vis[u[i]]==2&&vis[v[i]]==2)printf("%d ",dis[v[i]]-dis[u[i]]);
				else printf("1 ");
			}
			puts("");
		}
	}
	//FOR(i,1,n)printf("%d ",dis[i]);
}
int main()
{
	input();
	solve();
	return 0;
}