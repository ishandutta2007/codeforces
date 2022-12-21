#include<stdio.h>
#include<cstring>
using namespace std;
int cnt,i,j,k,l,m,n;
int s=0;
int a[100005];
inline int min(int o,int p)
{
    if (o<p)
    return o;
    else return p;
}
inline int max(int o,int p)
{
    if (o>p)
    return o;
    else return p;
}
int main()
{
    memset(a,0,sizeof(a));
    scanf("%d%d",&n,&m);
    int yyy=0;
    for (i=1;i<=n;i++)
    {
        scanf("%d",&j);
        scanf("%d",&k);
        yyy=max(yyy,j);
        a[j]+=k;
    }
    cnt=0;
    for (i=1;i<=yyy+1;i++)
    {
        int yy=m;
        int u=min(cnt,yy);
        s=s+u;
        yy=yy-u;
        u=min(yy,a[i]);
        s=s+u;
        cnt=a[i]-u;
    }
    printf("%d",s);
}