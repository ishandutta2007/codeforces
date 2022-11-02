#include <bits/stdc++.h>
using namespace std;
const int N=2e5+3;
const int M=3e5+3;
const int Q=5e5+3;
struct milk
{
    int x,y,z;
}a[M];
int b[Q];
int c[Q];
int p[N];

int num[N];
struct cow
{
    int l,r;
    int v;
}t[Q];
int F[20][Q];
vector<int>to[Q];
int n,m,q;
int cutt;
int nam;
int val[N];
struct Slim
{
    int l,r;
    int ls,rs;
    int s;
}T[N<<1];
inline void bing(int now){T[now].s=max(T[T[now].ls].s,T[T[now].rs].s);}
inline void make_tree(int l,int r,int i)
{
    T[i].l=l;T[i].r=r;
    T[i].ls=T[i].rs=0;
    if(l==r){T[i].s=val[l];return;}
    int mid=(l+r)>>1;
    T[i].ls=++cutt;make_tree(l,mid,T[i].ls);
    T[i].rs=++cutt;make_tree(mid+1,r,T[i].rs);
    bing(i);
    return;
}
inline int cheak(int l,int r,int i)
{
    if(l<=T[i].l&&T[i].r<=r)return T[i].s;
    int ans=0;
    if(T[T[i].ls].r>=l)ans=max(ans,cheak(l,r,T[i].ls));
    if(T[T[i].rs].l<=r)ans=max(ans,cheak(l,r,T[i].rs));
    return ans;
}
inline void delete_(int s,int i)
{
    if(T[i].l==T[i].r){T[i].s=0;return;}
    delete_(s,(T[T[i].ls].s==s)?T[i].ls:T[i].rs);
    bing(i);
    return;
}
inline void add(int l,int r,int s,int i)
{
    if(l<=T[i].l&&T[i].r<=r){if(T[i].s==s)delete_(s,i);return;}
    if(T[T[i].ls].r>=l)add(l,r,s,T[i].ls);
    if(T[T[i].rs].l<=r)add(l,r,s,T[i].rs);
    bing(i);
    return;
}
inline void work(int st,int v)
{
    for(int s=0;s>=0;)
    {
        int to=F[s][st];
        if(t[to].v<=v)s--;
        else st=to,s++;
    }
    int maxl=cheak(t[st].l,t[st].r,1);
    printf("%d\n",maxl);
    if(maxl)add(t[st].l,t[st].r,maxl,1);
    return;
}
inline void dfs(int x,int fa)
{
    t[x].l=cutt+1;
    if(x<=n)num[x]=++cutt;
    for(int i=to[x].size()-1;i>=0;i--)
    {
        int next=to[x][i];
        if(next==fa)continue;
        F[0][next]=x;
        dfs(next,x);
    }
    t[x].r=cutt;
    return;
}
int f[Q];
inline int find(int x){return (f[x]==x)?(x):(f[x]=find(f[x]));}
inline bool myru(milk x,milk y){return x.z>y.z;}
inline int rin()
{
    int s=0;
    bool bj=false;
    char c=getchar();
    for(;(c>'9'||c<'0')&&c!='-';c=getchar());
    if(c=='-')bj=true,c=getchar();
    for(;c>='0'&&c<='9';c=getchar())s=(s<<1)+(s<<3)+(c^'0');
    if(bj)s=-s;
    return s;
}
int main()
{
    int i,j;
    n=rin();m=rin();q=rin();
    for(i=1;i<=n;i++)p[i]=rin();
    for(i=1;i<=m;i++)a[i].x=rin(),a[i].y=rin(),a[i].z=0x3f3f3f3f;
    for(i=1;i<=q;i++)(rin()==1)?(b[++nam]=rin(),c[nam]=i):(j=rin(),a[j].z=min(a[j].z,i));
    sort(a+1,a+m+1,myru);
    for(i=n+m;i>=1;i--)f[i]=i;
    for(i=1;i<=m;i++)
    if(find(a[i].x)!=find(a[i].y))to[i+n].push_back(find(a[i].x)),to[i+n].push_back(find(a[i].y)),f[find(a[i].x)]=f[find(a[i].y)]=i+n,t[i+n].v=a[i].z;
    for(i=1;i<=n;i++)if(!num[i])dfs(find(i),0);
    for(i=1,m+=n;(1<<i)<=m;i++)for(j=1;j<=m;j++)F[i][j]=F[i-1][F[i-1][j]];m-=n;t[0].v=0;
    for(i=1;i<=n;i++)val[num[i]]=p[i];
    cutt=0;make_tree(1,n,++cutt);
    for(i=1;i<=nam;i++)work(b[i],c[i]);
    return 0;
}