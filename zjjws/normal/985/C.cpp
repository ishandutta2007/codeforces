#include <stdio.h>
#include <algorithm>
#define LL long long
using namespace std;
const int N=1e5+3;
int n,k,m,l;
int a[N];
inline bool myru(int x,int y){return x<y;}
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

inline int work()
{
    return 0;
}
int main()
{
    int i,j;
    n=rin();k=rin();l=rin();
    m=n*k;
    for(i=1;i<=m;i++)a[i]=rin();
    sort(a+1,a+m+1,myru);
    if(n==1){printf("%d\n",a[1]);return 0;}
    int ed;
    for(ed=m;ed>0&&a[ed]-a[1]>l;ed--);
    if(ed<n){puts("0");return 0;}
    LL ans=0;
    ans+=a[1];
    int now=1;
    for(i=2;i<=n;i++)
    {
        if(now+k+(n-i)<=ed)now+=k,ans+=a[now];
        else 
        {
            now+=(ed)-(now+(n-i));
            for(;i<=n;i++,now++)ans+=a[now];
        }
    }
    printf("%lld\n",ans);
    return 0;
}