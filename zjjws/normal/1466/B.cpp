#include <stdio.h>
#include <algorithm>
#define LL long long
using namespace std;
const int N=1e5+3;
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

int n;
int a[N];
int b[N];
int nam;
bool vit[N<<1];
inline void work()
{
    n=rin();
    nam=0;
    for(int i=1;i<=n;i++)a[i]=rin();
    sort(a+1,a+n+1);
    int j;
    for(int i=1;i<=n;i=j)
    {
        a[++nam]=a[i];
        b[nam]=1;
        for(j=i+1;j<=n&&a[j]==a[nam];j++)b[nam]++;
    }
    int ans=1;
    for(int i=1;i<nam;i++)
    {
        ans++;
        if(b[i]>1)
        {
            if(a[i+1]!=a[i]+1)ans++;
            else b[i+1]+=b[i]-1;
        }
    }
    if(b[nam]>1)ans++;
    printf("%d\n",ans);
    return;
}
int main()
{
    int i,j;
    for(int T=rin();T;T--)work();
    return 0;
}