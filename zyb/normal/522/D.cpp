#include<stdio.h>
#include<map>
#include<algorithm>
#define inf 10000000
using namespace std;
int i,j,k,l,m,n,x,y;
map<int,int>f;
struct node
{
    int l,r,id;
}b[500005],q[500005];
int tot,d[2000005],s[2000005],a[500005],ans[500005];
inline bool cmp(node x,node y)
{
    return x.r<y.r;
}
inline void build(int o,int l,int r)
{
    d[o]=inf;
    if (l==r)
    return ;
    int mid=(l+r)>>1;
    build(o*2,l,mid);
    build(o*2+1,mid+1,r);
}
inline void up(int o)
{
    d[o]=min(d[o],min(d[o*2],d[o*2+1]));
}
inline void insert(int o,int l,int r,int ll,int rr,int p)
{
    if (l==ll&&r==rr)
    {
        d[o]=min(d[o],p);
        return ;
    }
    int mid=(l+r)>>1;
    if (ll<=mid)
    insert(o*2,l,mid,ll,rr,p);
    else
    insert(o*2+1,mid+1,r,ll,rr,p);
    up(o);
}
inline int ask(int o,int l,int r,int ll,int rr)
{
    if (l==ll&&r==rr)
    return d[o];
    int mid=(l+r)>>1;
    int gt;
    if (rr<=mid)
    gt=ask(o*2,l,mid,ll,rr);
    else
    if (ll>mid)
    gt=ask(o*2+1,mid+1,r,ll,rr);
    else
    {
        gt=ask(o*2,l,mid,ll,mid);
        gt=min(gt,ask(o*2+1,mid+1,r,mid+1,rr));
    }
    up(o);
    return gt;
}
int main()
{
    scanf("%d%d",&n,&m);
    for (i=1;i<=n;i++)
    scanf("%d",&a[i]);
    for (i=1;i<=n;i++)
    {
        if (f[a[i]])
        {
            q[++tot].r=i;
            q[tot].l=f[a[i]];
        }
        f[a[i]]=i;
    }
    for (i=1;i<=m;i++)
    scanf("%d%d",&b[i].l,&b[b[i].id=i].r);
    sort(b+1,b+1+m,cmp);
    j=1;
    build(1,1,n);
    for (i=1;i<=m;i++)
    {
        while (q[j].r<=b[i].r&&j<=tot)
        {
            insert(1,1,n,q[j].l,q[j].l,q[j].r-q[j].l);
            j++;
        }
        int gt=ask(1,1,n,b[i].l,b[i].r);
        if (gt==inf)
        gt=-1;
        ans[b[i].id]=gt;
    }
    for (i=1;i<=m;i++)
    printf("%d\n",ans[i]);
}