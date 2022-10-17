#include<bits/stdc++.h>
#define ll long long
#define LG 17
#define N 100100
#define M 1000000007
using namespace std;

int n,m,rt,tt,in[N],out[N],num[N],fa[N][20],deep[N],d[N],dp[N][310];
struct Sz
{
    int num[N];
    vector<int>cle;
    inline int lb(int u){return u&(-u);}
    inline void add(int u,int v){for(;u<=n;u+=lb(u)) num[u]+=v,cle.push_back(u);}
    inline int ask(int u){int res=0;for(;u;u-=lb(u)) res+=num[u];return res;}
    inline void clear(){int i;for(i=0;i<cle.size();i++) num[cle[i]]=0;cle.clear();}
}sz;
vector<int>to[N],son[N];

inline bool cmp(int u,int v){return d[u]<d[v];}
void dfs(int now,int last)
{
    int i,t;
    in[now]=++tt;
    for(i=0;i<to[now].size();i++)
    {
	t=to[now][i];
	if(t==last) continue;
	son[now].push_back(t);
	fa[t][0]=now;
	deep[t]=deep[now]+1;
	dfs(t,now);
    }
    out[now]=tt;
}

inline int ts(int u,int v)
{
    int l,r,mid;
    for(l=0,r=son[u].size();l<r;)
    {
	mid=((l+r)>>1);
	if(in[son[u][mid]]<=in[v]) l=mid+1;
	else r=mid;
    }
    return son[u][l-1];
}

inline int lca(int u,int v)
{
    int i,j;
    if(deep[u]<deep[v]) swap(u,v);
    for(i=LG;deep[u]!=deep[v];i--)
    {
	if(deep[fa[u][i]]>=deep[v])
	    u=fa[u][i];
    }
    if(u==v) return u;
    for(i=LG;i>=0;i--)
    {
	if(fa[u][i]!=fa[v][i])
	{
	    u=fa[u][i];
	    v=fa[v][i];
	}
    }
    return fa[u][0];
}

inline int dis(int u,int v)
{
    int l=lca(u,v);
    return deep[u]+deep[v]-2*deep[l];
}

int main()
{
    int i,j,p,q;
    cin>>n>>m;
    for(i=1;i<n;i++)
    {
	scanf("%d%d",&p,&q);
	to[p].push_back(q);
	to[q].push_back(p);
    }
    deep[1]=1;
    dfs(1,-1);
    for(i=1;i<=LG;i++)
    {
	for(j=1;j<=n;j++)
	{
	    fa[j][i]=fa[fa[j][i-1]][i-1];
	}
    }
    while(m--)
    {
	scanf("%d%d%d",&p,&q,&rt);
	sz.clear(),dp[0][0]=1;
	for(i=1;i<=p;i++) scanf("%d",&num[i]),d[num[i]]=dis(num[i],rt);
	sort(num+1,num+p+1,cmp);
	for(i=1;i<=p;i++)
	{
	    int as=sz.ask(in[num[i]]);
	    for(j=as+1;j<=q;j++)
	    {
		dp[i][j]=((ll)dp[i-1][j-1]+(ll)dp[i-1][j]*(j-as)%M)%M;
	    }
	    if(num[i]==rt) sz.add(1,1);
	    else if(in[rt]>=in[num[i]] && in[rt]<=out[num[i]])
	    {
		int t=ts(num[i],rt);
		sz.add(1,1),sz.add(in[t],-1);
		sz.add(out[t]+1,1);
	    }
	    else
	    {
		sz.add(in[num[i]],1);
		sz.add(out[num[i]]+1,-1);
	    }
	}
	ll ans=0;
	for(i=1;i<=q;i++) ans=(ans+dp[p][i])%M;
	for(i=0;i<=p;i++) memset(dp[i],0,sizeof(dp[i]));
	printf("%lld\n",ans);
    }
}