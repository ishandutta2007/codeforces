#include <stdio.h>
#include <algorithm>
#define LL long long
using namespace std;
const int N=1e5+3;
int n,w,h;
inline LL rin()
{
    LL s=0;
    bool bj=false;
    char c=getchar();
    for(;(c>'9'||c<'0')&&c!='-';c=getchar());
    if(c=='-')bj=true,c=getchar();
    for(;c>='0'&&c<='9';c=getchar())s=(s<<1)+(s<<3)+(c^'0');
    if(bj)s=-s;
    return s;
}

struct gyq
{
    int opt,x,t;
    int xt;
    int num;
}a[N];
inline bool myru_a(gyq x,gyq y)
{
    if(x.xt==y.xt)
    {
        if(x.opt==y.opt)return (x.opt==2)?(x.x>y.x):(x.x<y.x);
        return x.opt<y.opt;
    }
    return x.xt<y.xt;
}

int x[N];
int y[N];
int d[N];
int head,tail;
int main()
{
    int i,j;
    n=rin();w=rin();h=rin();
    for(i=1;i<=n;i++)a[i].opt=rin(),a[i].x=rin(),a[i].t=rin(),a[i].xt=a[i].x-a[i].t,a[i].num=i;
    sort(a+1,a+n+1,myru_a);
    for(int l=1,r;l<=n;l=r+1)
    {
        int mid=l-1;
        for(r=l-1;r<n&&a[r+1].xt==a[l].xt;r++)if(a[r+1].opt==1)mid=r+1;
        head=1;tail=0;
        for(int i=mid+1;i<=r;i++)d[++tail]=a[i].num;
        // printf("d:");
        // for(int i=head;i<=tail;i++)printf("%d ",d[i]);printf("\n");
        for(int i=l;i<=mid;i++)
        {
            d[++tail]=a[i].num;
            int now=d[head++];
            x[now]=a[i].x;
            y[now]=h;
        }
        for(int i=mid+1;i<=r;i++)
        {
            int now=d[head++];
            x[now]=w;
            y[now]=a[i].x;
        }
    }
    for(i=1;i<=n;i++)printf("%d %d\n",x[i],y[i]);
    return 0;
}