#include <stdio.h>
#include <string.h>
#include <algorithm>
#define LL long long
using namespace std;
const int N=1e2+3;
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

bool vit[N];
int a[N];
inline void work()
{
    memset(vit,0,sizeof(vit));
    int n=rin();
    for(int i=1;i<=n;i++)a[i]=rin();
    sort(a+1,a+n+1);
    int cutt=0;
    for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)if(!vit[a[j]-a[i]])vit[a[j]-a[i]]=true,cutt++;
    printf("%d\n",cutt);
    return;
}
int main()
{
    int i,j;
    for(int T=rin();T;T--)work();
    return 0;
}