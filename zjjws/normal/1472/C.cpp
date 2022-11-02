#include <stdio.h>
#define LL long long
using namespace std;
const int N=2e5+3;
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
inline int max(int x,int y){return x>y?x:y;}

int a[N];
int f[N];
inline void work()
{
    int n=rin();
    for(int i=1;i<=n;i++)a[i]=rin(),f[i]=0;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        f[i]+=a[i];
        ans=max(ans,f[i]);
        if(i+a[i]<=n)f[i+a[i]]=max(f[i+a[i]],f[i]);
    }
    printf("%d\n",ans);
    return;
}
int main()
{
    int i,j;
    for(int T=rin();T;T--)work();
    return 0;
}