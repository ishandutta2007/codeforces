#include<stdio.h>
#include<cstring>
#define lowbit(o) o&-o
using namespace std;
int i,j,k,l,s,m,n,ff[1000005],f[1000005],a[1000005];
inline void insert(int o)
{
    for (;o<=n;o+=lowbit(o))
    ff[o]++;
}
inline int ask(int o)
{
    int s=0;
    for (;o;o-=lowbit(o))
    s+=ff[o];
    return s;
}
inline void work()
{
    for (int i=1;i<=n;i++)
    {
        int gt=a[i]-ask(a[i])-1;
        f[i]+=gt;
        insert(a[i]);
    }
}
int main()
{
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        a[i]++;
    }
    work();
    memset(a,0,sizeof(a));
    for (i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        a[i]++;
    }
    memset(ff,0,sizeof(ff));
    work();
    int t=0;
    for (i=n;i;i--)
    {
        t++;
        if (f[i]>=t)
        {
            f[i-1]+=((f[i])/t);
            f[i]=(f[i])%t;
        }
    }
    memset(ff,0,sizeof(ff));
    for (i=1;i<=n;i++)
    {
        int l=1,r=n,s=0;
        while (l<=r)
        {
            int mid=(l+r)>>1;
            int gt=mid-ask(mid)-1;
            if (gt>=f[i])
            {
                r=mid-1;
                s=mid;
            }
            else
            l=mid+1;
        }
        printf("%d ",s-1);
        insert(s);
    }
}