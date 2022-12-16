#include<stdio.h>
#include<algorithm>
#include<map>
#include<cstring>
#define lowbit(o) o&-o
using namespace std;
struct node
{
    int x,y,id;
}a[200005];
int st,t,gt,i,j,k,l,s,m,n,f[600005],tot;
int ff[200005],q[600005];
map<int,int>ma;
inline bool cmp(node x,node y)
{
    return x.x<y.x;
}
inline void add(int o,int p)
{
    for (;o<=t;o+=lowbit(o))
    f[o]=max(f[o],p);
}
inline int ask(int o)
{
    int s=0;
    for (;o;o-=lowbit(o))
    s=max(s,f[o]);
    return s;
}
int main()
{
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        scanf("%d%d",&a[a[i].id=i].x,&a[i].y);
        q[++tot]=a[i].x;q[++tot]=a[i].x-a[i].y;
        q[++tot]=a[i].x+a[i].y;
    }
    sort(q+1,q+1+tot);
    for (i=1;i<=tot;i++)
    {
        if (!ma[q[i]])
        ma[q[i]]=++t;
    }
    sort(a+1,a+1+n,cmp);
    for (i=1;i<=n;i++)
    {
        ff[i]=ask(ma[a[i].x-a[i].y]);
        add(ma[a[i].x+a[i].y],ff[i]+1);
        gt=max(gt,ff[i]+1);
    }
    printf("%d\n",gt);
}