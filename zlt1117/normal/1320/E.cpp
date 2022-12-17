#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define sz(x) (int)(x.size())
#define rd (rand()<<16^rand())
#define pb push_back
#define PII pair<int,int>
#define db double
#define ll long long
#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
#define poly vector<int> 
using namespace std; 
char buf[100000],*p1=buf,*p2=buf;
inline int gi()
{
	int x=0,f=1;char ch=gc;
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=gc;}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=gc;}
	return (f==1)?x:-x;
}
inline int min(int a,int b){return a<b?a:b;}
inline int max(int a,int b){return a>b?a:b;}
const int maxn=4e5+5,inf=1e9;
int n,q,m,k;
vector<int>e[maxn];
int st[20][maxn<<1],Log[maxn<<1],dep[maxn],fir[maxn],dfn[maxn],tot,tim,low[maxn];
struct node
{
	int u,turn,dis,col;
	inline bool operator < (const node &b)const
	{
		if(turn!=b.turn)return turn>b.turn;
		return col>b.col;
	} 
}dis[maxn];
priority_queue<node>pq;
int vis[maxn];
vector<int>u,v,s;
inline void dfs(int u,int f)
{
	dfn[u]=++tim,st[0][++tot]=u;fir[u]=tot;
	for(auto x:e[u])
	{
		if(x==f)continue;
		dep[x]=dep[u]+1;
		dfs(x,u); 
		st[0][++tot]=u;
	}
	low[u]=tim;
}
inline int compare(int x,int y){return dep[x]<dep[y]?x:y;}
inline void prepare()
{
	FOR(i,1,Log[tot])
	{
		FOR(j,1,tot-(1<<i)+1)
		{
			st[i][j]=compare(st[i-1][j],st[i-1][j+(1<<(i-1))]);
		}
	}
}
inline int LCA(int x,int y)
{
	x=fir[x],y=fir[y];
	if(x>y)swap(x,y);
	int l=Log[y-x+1];
	return compare(st[l][x],st[l][y-(1<<l)+1]);
}
namespace Virtual_Tree
{
	int sz;
	struct edge
	{
		int v,nxt,w;
		edge(int vv=0,int ww=0,int nn=0){v=vv,w=ww,nxt=nn;}
	}e[maxn<<1];
	int p[maxn],Q[maxn<<1],cnt,stk[maxn],top;
	inline void add(int u,int v,int w)
	{
		e[++sz]=edge(v,w,p[u]);
		p[u]=sz;
	}
	inline void init()
	{
		memset(p,-1,sizeof(p));
		sz=1;
		FOR(i,0,maxn-1)dis[i].turn=inf;
	}
	inline bool cmp(const int &x,const int &y){return dfn[x]<dfn[y];}
	inline void build()
	{
		cnt=0,top=0,sz=1;
		for(auto x:u)Q[++cnt]=x;
		for(auto x:v)Q[++cnt]=x;
		sort(Q+1,Q+cnt+1,cmp);
		for(int i=cnt-1;i>=1;--i)Q[++cnt]=LCA(Q[i],Q[i+1]);
		Q[++cnt]=1; 
		sort(Q+1,Q+cnt+1,cmp);
		cnt=unique(Q+1,Q+cnt+1)-Q-1;
		FOR(i,1,cnt)
		{
			while(top&&low[stk[top]]<dfn[Q[i]])top--;///while
			if(top)add(Q[i],stk[top],dep[Q[i]]-dep[stk[top]]);
			if(top)add(stk[top],Q[i],dep[Q[i]]-dep[stk[top]]);
			stk[++top]=Q[i];
		}
	}
	inline void work()
	{
		FOR(i,0,k-1)dis[v[i]]={v[i],0,s[i],i},pq.push(dis[v[i]]);
		while(!pq.empty())
		{
			node x=pq.top();
			pq.pop();
			if(vis[x.u])continue;
			vis[x.u]++;
			REP(x.u)
			{
				int v=e[i].v;
				node now=x;now.u=v;
				if(now.dis+e[i].w<=s[now.col])now.dis+=e[i].w;
				else 
				{
					int temp=s[now.col]-now.dis;
					temp=e[i].w-temp;
					now.dis=0,now.turn+=temp/s[now.col]+(temp%s[now.col]!=0);
					now.dis=(temp-1)%s[now.col]+1;
				}
				if(now.turn<dis[v].turn||(now.turn==dis[v].turn&&now.col<dis[v].col))
				{
					dis[v]=now;
					pq.push(dis[v]);
				}	
			}
		}
		for(auto x:u)printf("%d ",dis[x].col+1);
		printf("\n");
	}
	inline void clear()
	{
		FOR(i,1,cnt)p[Q[i]]=-1,vis[Q[i]]=0,dis[Q[i]]={0,inf,0,0};
	}
}
inline void init()
{
	Virtual_Tree::init();
}
inline void input()
{
	n=gi();
	FOR(i,2,n<<1)Log[i]=Log[i>>1]+1;
	FOR(i,1,n-1)
	{
		int x=gi(),y=gi();
		e[x].pb(y),e[y].pb(x);
	}
}
inline void solve()
{
	dfs(1,0);
	prepare();
	int q=gi();
	while(q--)
	{
		k=gi(),m=gi();
		u.resize(m),v.resize(k),s.resize(k);
		FOR(i,0,k-1)v[i]=gi(),s[i]=gi();
		FOR(i,0,m-1)u[i]=gi();
		Virtual_Tree::build();
		Virtual_Tree::work();
		Virtual_Tree::clear();
	}
}
int main()
{
	init();
	input();
	solve();
	return 0;
}
/*
5
1 2
2 3
3 4
4 5

*/