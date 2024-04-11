#include<stdio.h>
#define maxn 100005
#define maxm 200005
#define P 1000000007
using namespace std;
long long tot,f[maxn][2],to[maxm],last[maxn],next[maxm];
long long ans,fa[maxn],q[maxn],i,j,k,l,s,m,n,x,a[maxn];
inline void add(int o,int p)
{
    next[++tot]=last[o];last[o]=tot;to[tot]=p;
}
inline void build()
{
    int l=0,r=1;
    q[1]=1;
    while (l<r)
    {
        int k=q[++l];
        for (int i=last[k];i;i=next[i])
        {
            int gt=to[i];
            if (fa[k]!=gt)
            {
                fa[gt]=k;
                q[++r]=gt;
            }
        }
    }
}
int main()
{
    scanf("%I64d",&n);
    for (i=1;i<n;i++)
    {
        scanf("%I64d",&x);
        x++;
        add(i+1,x);add(x,i+1);
    }
    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&a[i]);
        f[i][a[i]]=1;
        f[i][a[i]^1]=0;
    }
    build();
    for (i=n;i;i--)
    {
        int gt=q[i];
        for (j=last[gt];j;j=next[j])
        {
            int gtw=to[j];
            if (gtw!=fa[gt])
            {
                f[gt][1]=((f[gt][1]*(f[gtw][1]+f[gtw][0]))%P+f[gt][0]*f[gtw][1])%P;
                f[gt][0]=(f[gt][0]*f[gtw][0]+f[gt][0]*f[gtw][1])%P;
            }
        }
    }
    printf("%I64d\n",f[q[1]][1]);
}