#include<stdio.h>
#include<map>
#include<set>
#include<algorithm>
#define P 1000000009
using namespace std;
map<int,int>f[100005];
set<int>gt;
set<int>::iterator gtw;
int sss[100005],i,j,k,l,s,m,n;
long long ans;
struct node
{
    int x,y,tot;
}a[100005];
inline bool cmp(node x,node y)
{
    return x.y>y.y;
}

int gg[100005];
inline long long quick(int o,int p)
{
    long long oo=o*1ll,pp=p*1ll,ans=1;
    while (pp)
    {
        if (pp&1)
        ans=(ans*oo)%P;
        pp/=2;oo=(oo*oo)%P;
    }
    return ans;
}
inline bool check(int o)
{
    int i=o;
    int tot=gg[i];
    if (!(f[tot-1][a[i].x-1]||f[tot-1][a[i].x]||f[tot-1][a[i].x+1]))
    return true;
    else
    if ((!(f[tot-1][a[i].x-1])||((f[tot][a[i].x-1]||f[tot][a[i].x-2]))))
    if ((!(f[tot-1][a[i].x+1])||((f[tot][a[i].x+1]||f[tot][a[i].x+2]))))
    if ((!(f[tot-1][a[i].x])||((f[tot][a[i].x-1]||f[tot][a[i].x+1]))))
    return true;
    return false;
}
int main()
{
    scanf("%d",&m);
    for (i=1;i<=m;i++)
    {
        scanf("%d%d",&a[i].x,&a[a[i].tot=i].y);
        a[i].x+=P;
        a[i].y+=P;
    }
    sort(a+1,a+1+m,cmp);
    int tot=0;
    for (i=1;i<=m;i++)
    {
        if (a[i].y!=a[i-1].y)
        tot++;
        f[tot][a[i].x]=a[i].tot;
        gg[i]=tot;
        sss[a[i].tot]=i;
    }
    for (i=1;i<=m;i++)
    {
        int tot=gg[i];
        if (!(f[tot-1][a[i].x-1]||f[tot-1][a[i].x]||f[tot-1][a[i].x+1]))
        gt.insert(a[i].tot);
        else
        if ((!(f[tot-1][a[i].x-1])||((f[tot][a[i].x-1]||f[tot][a[i].x-2]))))
        if ((!(f[tot-1][a[i].x+1])||((f[tot][a[i].x+1]||f[tot][a[i].x+2]))))
        if ((!(f[tot-1][a[i].x])||((f[tot][a[i].x-1]||f[tot][a[i].x+1]))))
        gt.insert(a[i].tot);
    }
    for (i=1;i<=m;i++)
    {
        if (i%2==1)
        {
            
            while (1)
            {
                gtw=gt.end();       
                gtw--;
                int uuu=(*gtw);
                if (!check(sss[uuu]))
                gt.erase(uuu);
                else
                break;
            }
        }
        else
        {
            
            while (1)
            {
                gtw=gt.begin();
                int uuu=(*gtw);
                if (!check(sss[uuu]))
                gt.erase(uuu);
                else
                break;
            }
        }
        int uuu=(*gtw);
        long long pppp=uuu-1;
        ans=(ans+pppp*quick(m,m-i)%P)%P;
        int uu=sss[uuu];
        int x=a[uu].x,y=a[uu].y;
        int qqqq=f[gg[uu]][x];
        f[gg[uu]][x]=0;
        for (j=x-1;j<=x+1;j++)
        {
            if (f[gg[uu]+1][j])
            {
                if (check(sss[f[gg[uu]+1][j]]))
                gt.insert(f[gg[uu]+1][j]);
            }
        }
        gt.erase(qqqq);
    }
    printf("%I64d\n",ans);
}