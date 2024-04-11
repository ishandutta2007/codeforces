#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#define N 4000003
using namespace std;
int vis[N],n,m,num[N],ans;
int point[N],nxt[N],v[N],tot,l[N],r[N],mark[N],bel[N],tmp[N],f[N],g[N];
void add(int x,int y)
{
tot++; nxt[tot]=point[x]; point[x]=tot; v[tot]=y;
tot++; nxt[tot]=point[y]; point[y]=tot; v[tot]=x;
//cout<<x<<" "<<y<<endl;
}
void del(int x)
{
vis[x]=1;
r[l[x]]=r[x];
l[r[x]]=l[x];
}
void bfs(int x)
{
queue<int> p; p.push(x);
while(!p.empty())
{
int now=p.front(); p.pop();
tmp[now]=ans;
for (int i=point[now];i;i=nxt[i]) mark[v[i]]=1;
for (int i=r[0];i;i=r[i])
if (!vis[i]&&!mark[i]) del(i),p.push(i);
for (int i=point[now];i;i=nxt[i]) mark[v[i]]=0;
}
}
struct E
{
int u,v,w;
bool operator<(const E&x)
{
return w<x.w;
}
}e[N];
int get(int x)
{
return x==f[x]?x:(f[x]=get(f[x]));
}
int find(int x){
return x==g[x]?x:(g[x]=find(g[x]));
}
int main()
{
scanf("%d%d",&n,&m);
for (int i=1;i<=m;i++)
{
int x,y,z; scanf("%d%d%d",&x,&y,&z);
add(x,y); e[i]=(E){x,y,z};
}
sort(e+1,e+m+1);
for (int i=0;i<=n;i++) l[i]=i-1,r[i]=i+1;
r[n]=0;
for (int i=1;i<=n;i++)
if(!vis[i])
{
ans++;
del(i);
bfs(i);
}
long long res=0;iota(g+1,g+n+1,1);
for(int i=1;i<=n;++i)bel[tmp[i]]=i;
for(int i=1;i<=n;++i)f[i]=bel[tmp[i]];
for(int i=1;i<=m;++i)
{
int u=e[i].u,v=e[i].v,w=e[i].w;
if(get(u)!=get(v))
{
res+=w;
f[get(u)]=get(v);
g[find(u)]=find(v);
}
}
if(1ll*n*(n-1)/2-m==n-ans){
int cur=0;
for(int i=1;i<=m;++i)cur^=e[i].w;
for(int i=1;i<=m;++i)if(find(e[i].u)!=find(e[i].v))cur=min(cur,e[i].w);
res+=cur;
}
printf("%lld\n",res);
}