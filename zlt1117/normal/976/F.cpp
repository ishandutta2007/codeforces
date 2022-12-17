#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define sz(x) (int)(x.size())
#define pb push_back
#define PII pair<int,int>
#define ll long long
#define gc getchar()
//#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
using namespace std;
char buf[100000],*p1=buf,*p2=buf;
inline int gi()
{
	int x=0,f=1;char ch=gc;
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=gc;}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=gc;}
	return (f==1)?x:-x;
}
const int inf=1e9;
struct edge
{
	int v,w,nxt,id;
	edge(int vv=0,int ii=0,int ww=0,int nn=0){id=ii,v=vv,w=ww,nxt=nn;}
};
struct Dinic
{
	static const int maxn=50005,maxm=4e5+5;
	edge e[maxm<<1];
	int p[maxn],tot,s,t,sz;
	int dis[maxn],q[maxn],hd,tl,cur[maxn];
	Dinic(){memset(p,-1,sizeof(p));sz=-1;} 
	inline void clear()
	{
		FOR(i,0,tot)p[i]=-1;
		sz=-1;
	}
	inline void ins(int u,int v,int w,int id)
	{
		e[++sz]=edge(v,id,w,p[u]);
		p[u]=sz;
	}
	inline void add(int u,int v,int w,int id)
	{
		ins(u,v,w,id);
		ins(v,u,0,id);
	}
	inline bool bfs()
	{
		q[hd=tl=0]=s;
		FOR(i,0,tot)cur[i]=p[i],dis[i]=-1;
		dis[s]=0;
		while(hd<=tl)
		{
			int u=q[hd++];
			for(int i=p[u];i!=-1;i=e[i].nxt)
			{
				int v=e[i].v;
				if(dis[v]==-1&&e[i].w)
				{
					dis[v]=dis[u]+1;
					if(v==t)return true;
					q[++tl]=v;
				}
			}
		}
		return dis[t]!=-1;
	}
	inline int dfs(int u,int flow)
	{
		if(u==t)return flow;
		int ret=0;
		for(int &i=cur[u];i!=-1;i=e[i].nxt)
		{
			int v=e[i].v;
			if(dis[v]==dis[u]+1&&e[i].w)
			{
				ll val=dfs(v,min(flow,e[i].w));
				if(val==0)dis[v]=-1;
				else
				{
					ret+=val,e[i].w-=val,e[i^1].w+=val,flow-=val;
					if(flow==0)break;
				}
			}
		}
		return ret;
	}
	inline ll dinic()
	{
		ll ans=0;
		while(bfs())
		ans+=dfs(s,inf);
		return ans;
	}
}G;
const int maxn=4005;
int n1,n2,m,s,t;
int ind[maxn],index[maxn][maxn];
inline void input()
{
	n1=gi(),n2=gi(),m=gi();
	G.s=s=0,G.t=G.tot=t=n1+n2+1;
	FOR(i,1,m)
	{
		int u=gi(),v=gi();v+=n1;
		ind[u]++,ind[v]++;
		G.add(u,v,1,i);
	}
}
int id[maxn];
inline void solve()
{
	int mind=*min_element(ind+1,ind+n1+n2+1);
	FOR(i,1,n1)G.add(s,i,ind[i]-mind,0),id[i]=G.sz-1;
	FOR(i,n1+1,n2+n1)G.add(i,t,ind[i]-mind,0),id[i]=G.sz-1;
	int now=m;
	vector<vector<int>>answer;
	FOR(k,0,mind)
	{
		now-=G.dinic();
		vector<int>ans;
		FOR(i,1,n1)
		{
			for(int j=G.p[i];j!=-1;j=G.e[j].nxt)
			{
				int v=G.e[j].v;
				if(G.e[j].w==1&&v!=s)ans.pb(G.e[j].id);
			}
		}
		answer.pb(ans);
		FOR(i,1,n1+n2)G.e[id[i]].w++;
	}
	reverse(answer.begin(),answer.end());
	for(auto ans:answer)
	{
		printf("%d ",sz(ans));
		for(int x:ans)printf("%d ",x);
		puts("");
	}
}
int main()
{
	input();
	solve();
	return 0;
}