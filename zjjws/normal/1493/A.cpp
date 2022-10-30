#include <queue>
#include <vector>
#include <string>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define LL long long
using namespace std;
inline LL rin()
{
    LL s=0;
    bool bj=false;
    char c=getchar();
    for(;(c>'9'||c<'0')&&c!='-';c=getchar());
    if(c=='-')bj=true,c=getchar();
    for(;c>='0'&&c<='9';c=getchar())s=(s<<1)+(s<<3)+(c^'0');
    if(bj)return -s;
    return s;
}
inline void jh(int &x,int &y){if(x^y)x^=y^=x^=y;return;}
inline void jh(LL &x,LL &y){if(x^y)x^=y^=x^=y;return;}

const int N=3e5+3;
int n,k;
inline void work()
{
    n=rin();k=rin();
    if(n==1){puts("0");return;}
    if(n==k)
    {
        printf("%d\n",n-(n+1>>1));
        for(int i=(n+1>>1);i<n;i++)printf("%d ",i);printf("\n");
        return;
    }
    printf("%d\n",k-(k+1>>1)+(n-k));
    for(int i=(k+1>>1);i<k;i++)printf("%d ",i);
    for(int i=k+1;i<=n;i++)printf("%d ",i);printf("\n");
    return;
}
int main()
{
    for(int T=rin();T;T--)work();
    return 0;
}

//vjudge 