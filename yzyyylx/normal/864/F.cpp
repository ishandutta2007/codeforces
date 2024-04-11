#include<bits/stdc++.h>
#define LG 12
#define N 3010
#define M 400100
using namespace std;

int n,m,Q,bb,deep[N],first[N],ans[M],fa[N][15];
bool ok[N][N],vis[N];
struct Bn
{
    int to,next;
}bn[N];
struct Que
{
    int u,k,id;
};
vector<int>to[N];
vector<Que>que[N];

inline void add(int u,int v)
{
    bb++;
    bn[bb].to=v;
    bn[bb].next=first[u];
    first[u]=bb;
}

void dfs(int now,int fr)
{
    if(ok[fr][now]) return;
    ok[fr][now]=1;
    int i,t;
    for(i=0;i<to[now].size();i++)
    {
	t=to[now][i];
	dfs(t,fr);
    }
}

void Dfs(int now)
{
    int p,q;
    vis[now]=1;
    for(p=first[now];p!=-1;p=bn[p].next)
    {
	q=bn[p].to;
	fa[q][0]=now;
	deep[q]=deep[now]+1;
	Dfs(q);
    }
}

inline int jump(int u,int v)
{
    int i;
    for(i=LG;v;i--)
    {
	if(v>=(1 << i))
	{
	    v-=(1 << i);
	    u=fa[u][i];
	}
    }
    return u;
}

void work(int now)
{
    bb=0;
    memset(first,-1,sizeof(first));
    memset(vis,0,sizeof(vis));
    int i,j,t;
    for(i=1;i<=n;i++)
    {
	if(!ok[i][now] || i==now) continue;
	for(j=0;j<to[i].size();j++)
	{
	    t=to[i][j];
	    if(ok[t][now]) break;
	}
	if(j==to[i].size()) puts("gg");
	add(t,i);
    }
    deep[now]=1;
    Dfs(now);
    for(i=1;i<=LG;i++)
    {
	for(j=1;j<=n;j++)
	{
	    fa[j][i]=fa[fa[j][i-1]][i-1];
	}
    }
    for(i=0;i<que[now].size();i++)
    {
	Que tmp=que[now][i];
	if(!vis[tmp.u] || tmp.k>deep[tmp.u])
	{
	    ans[tmp.id]=-1;
	    continue;
	}
	ans[tmp.id]=jump(tmp.u,tmp.k-1);
    }
}

int main()
{
    int i,j,p,q,o;
    cin>>n>>m>>Q;
    for(i=1;i<=m;i++)
    {
	scanf("%d%d",&p,&q);
	to[p].push_back(q);
    }
    for(i=1;i<=n;i++) sort(to[i].begin(),to[i].end());
    for(i=1;i<=n;i++) dfs(i,i);
    for(i=1;i<=Q;i++)
    {
	scanf("%d%d%d",&p,&q,&o);
	if(!ok[p][q]) ans[i]=-1;
	else que[q].push_back((Que){p,o,i});
    }
    for(i=1;i<=n;i++) work(i);
    for(i=1;i<=Q;i++) printf("%d\n",ans[i]);
}