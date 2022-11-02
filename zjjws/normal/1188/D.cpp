#include <bits/stdc++.h>
#define LL long long
#define min(a,b) a>b?b:a
using namespace std;
const int N=1e5+2;
LL M;
LL now;
LL a[N];
int f[2][N];
int n;
inline bool myru(LL x,LL y){return (x&M)>(y&M);}
LL rin()
{
    LL s=0;
    char c=getchar();
    bool bj=0;
    for(;(c>'9'||c<'0')&&c!='-';c=getchar());
    if(c=='-')c=getchar(),bj=true;
    for(;c>='0'&&c<='9';c=getchar())s=(s<<1)+(s<<3)+(c^'0');
    if(bj)return -s;
    return s;
}
int main()
{
    int i,j;
    n=rin();
    for(i=1;i<=n;i++)a[i]=rin();
    M=(1LL<<60)-1;
    sort(a+1,a+n+1,myru);
    for(i=2;i<=n;i++)a[i]=a[1]-a[i];
    a[1]=0;
    now=M=0;
    for(i=0;i<=60;i++)
    {
        bool _=(i&1);
        memset(f[_],0x3f,sizeof(f[_]));
        now=(i>0)?(now<<1):1;
        M=(i>0)?((M<<1)|1):0;
        sort(a+1,a+n+1,myru);
        int s_1,s_0;
        int sum;//
        s_1=s_0=sum=0;
        for(j=1;j<=n;j++)(a[j]&now)?s_1++:s_0++;//10
        f[_][0]=min(f[_][0],f[!_][0]+s_1);
        f[_][s_1]=min(f[_][s_1],f[!_][0]+s_0);
        if(i>0)
        for(j=1;j<=n;j++)//
        {
            // if(f[!_][j]>=0x3f3f3f3f)break;
            (a[j]&now)?(s_1--,s_0++,sum++):(s_1++,s_0--);
            f[_][sum]=min(f[_][sum],f[!_][j]+s_1);
            f[_][sum+s_1]=min(f[_][sum+s_1],f[!_][j]+s_0);
        }
    }
    printf("%d\n",f[0][0]);
    return 0;
}