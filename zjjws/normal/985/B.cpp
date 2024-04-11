#include <stdio.h>
using namespace std;
const int N=2e3+3;
int n,m;
int a[N][N];
int sum[N];
inline int gc(){char c=getchar();for(;c!='0'&&c!='1';c=getchar());return c-'0';}
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
int main()
{
    int i,j;
    n=rin();m=rin();
    for(i=1;i<=n;i++)for(j=1;j<=m;j++)a[i][j]=gc(),sum[j]+=a[i][j];
    for(i=1;i<=n;i++)
    {
        bool bj=true;
        for(j=1;j<=m;j++)if(a[i][j]&&sum[j]-a[i][j]==0){bj=false;break;}
        if(bj){puts("YES");return 0;}
    }
    puts("NO");
    return 0;
}