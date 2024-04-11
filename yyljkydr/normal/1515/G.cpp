#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=1e6+1e3+7;

int dfn[N],low[N],dfs_num;

int vis[N],st[N],top;

int head[N],color[N],col_num;

int cnt;

struct Edge{
	int next,to,w;
}e[N];

void build(int u,int v,int w)
{
	++cnt;
	e[cnt].to=v;
	e[cnt].next=head[u];
	head[u]=cnt;
	e[cnt].w=w;
}

void Tarjan ( int x ) {
         dfn[ x ] = ++dfs_num ;
         low[ x ] = dfs_num ;
         vis [ x ] = true ;//
         st [ ++top ] = x ;
         for ( int i=head[ x ] ; i!=0 ; i=e[i].next ){
                  int temp = e[ i ].to ;
                  if ( !dfn[ temp ] ){
                           Tarjan ( temp ) ;
                           low[ x ] = min ( low[ x ] , low[ temp ] ) ;
                 }
                 else if ( vis[ temp ])low[ x ] = min ( low[ x ] , dfn[ temp ] ) ;
         }
         if ( dfn[ x ]==low[ x ] ) {//
                  vis[ x ] = false ;
                  color[ x ] = ++col_num ;//
                  while ( st[ top ] != x ) {//
                           color [st[ top ]] = col_num ;
                           vis [ st[ top-- ] ] = false ;
                 }
                 top -- ;
         }
}

int n,m;

int q;

int v[N],s[N],t[N];

typedef pair<int,int> pii;
#define fs first
#define sd second
#define mp make_pair

vector<pii>g[N];

int dc,d[N],gc[N];

void dfs(int x,int f)
{
	dfn[x]=++dc;
	for(auto [v,w]:g[x])
	{
		if(v==f)
			continue;
		if(!dfn[v])
		{
			d[v]=d[x]+w;
			dfs(v,x);
		}
		else if(dfn[v]<dfn[x])
		{
			int td=d[x]-d[v]+w;
			gc[color[x]]=__gcd(gc[color[x]],td);
		}
		else if(dfn[v]>dfn[x])
		{
			int td=d[x]-d[v]+w;
			gc[color[x]]=__gcd(gc[color[x]],td);
		}
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		build(u,v,w);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			Tarjan(i);
	for(int i=1;i<=n;i++)
		for(int tmp=head[i];tmp;tmp=e[tmp].next)
		{
			int v=e[tmp].to;
			if(color[i]==color[v])
				g[i].push_back(mp(v,e[tmp].w)),g[v].push_back(mp(i,-e[tmp].w));
		}
	for(int i=1;i<=n;i++)
		dfn[i]=0;
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			dfs(i,0);
	cin>>q;
	while(q--)
	{
		int x,y,z;
		cin>>x>>y>>z;
		int cx=color[x];
		int G=gc[cx];
		G=((G%z)+z)%z;
		y=(z-y)%z;
		if(y%__gcd(G,z))
			cout<<"NO\n";
		else
			cout<<"YES\n";
		// if(//y+kG=tz)
	}
}