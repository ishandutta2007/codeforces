#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define N 80
#define M 150000
using namespace std;

int n,m,A,B,bb,tt,first[N],fa[N],num[N],sz[N],ans[N],dp[N][M];
struct Bn
{
    int to,next,quan;
}bn[410];
struct Zt
{
    int u,v,d;
    bool operator < (const Zt &u) const{return d>u.d;}
};
priority_queue<Zt>pq;

int ff(int u){return fa[u]==u?u:fa[u]=ff(fa[u]);}
inline int get(int u){return num[u]==-1?0:(1 << num[u]);}
inline void add(int u,int v,int w)
{
    bb++;
    bn[bb].to=v;
    bn[bb].quan=w;
    bn[bb].next=first[u];
    first[u]=bb;
}

int main()
{
    memset(first,-1,sizeof(first));
    memset(num,-1,sizeof(num));
    memset(dp,0x3f,sizeof(dp));
    memset(ans,0x3f,sizeof(ans));
    int i,j,p,q,o;
    cin>>n>>m>>A>>B;
    for(i=1;i<=n;i++) fa[i]=i;
    for(i=1;i<=m;i++)
    {
	scanf("%d%d%d",&p,&q,&o);
	add(p,q,o),add(q,p,o);
	if(o==A) fa[ff(p)]=ff(q);
    }
    for(i=1;i<=n;i++) sz[ff(i)]++;
    for(i=1;i<=n;i++) if(i==ff(i)&&sz[i]>3) num[i]=++tt;
    for(i=1;i<=n;i++) num[i]=num[ff(i)];
    dp[1][get(1)]=0;
    pq.push((Zt){1,get(1),0});
    for(;!pq.empty();)
    {
	Zt now=pq.top();
	pq.pop();
	if(dp[now.u][now.v]<now.d) continue;
	ans[now.u]=min(ans[now.u],now.d);
	for(p=first[now.u];p!=-1;p=bn[p].next)
	{
	    q=bn[p].to;
	    if(bn[p].quan==B&&num[q]!=-1&&((1 << num[q])&now.v)) continue;
	    if(bn[p].quan==B&&ff(now.u)==ff(q)) continue;
//	    if(bn[p].quan==B) cout<<now.u<<" "<<now.v<<endl;
	    int t=bn[p].quan+now.d;
	    if(t>=dp[q][get(q)|now.v]) continue;
	    dp[q][get(q)|now.v]=t;
	    pq.push((Zt){q,get(q)|now.v,t});
	}
    }
    for(i=1;i<=n;i++) printf("%d ",ans[i]);
}