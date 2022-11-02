#include <vector>
#include <string>
#include <stdio.h>
#include <string.h>
#include <iostream>
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
inline void jh(int &x,int &y){if(x!=y)x^=y^=x^=y;return;}
inline void jh(LL &x,LL &y){if(x!=y)x^=y^=x^=y;return;}

const int N=1e2+3;
int n,m;
int a[N][N];
int du[N];
inline void work()
{
    n=rin();m=n*(n-1)>>1;m/=n;
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)a[i][j]=0;
    for(int i=1;i<=n;i++)du[i]=0;
    for(int i=1;i<=n;i++)
    {
        int les=m;
        for(int j=i+1;j<=n&&les;j++)
        {
            if(i==j||a[j][i]==1||du[j]+1+m+1>(n-1)+(n&1))continue;
            a[i][j]=1;les--;du[j]++;
        }
        for(int j=1;j<i&&les;j++)
        {
            if(i==j||a[j][i]==1||du[j]+1+m+1>(n-1)+(n&1))continue;
            a[i][j]=1;les--;du[j]++;
        }
        // if(les)printf("%d can't \n",i);
    }
    for(int i=1;i<n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(a[i][j]){printf("1 ");continue;}
            if(a[j][i]){printf("-1 ");continue;}
            printf("0 ");continue;
        }
        // printf("\n");
    }
    printf("\n");
    return;
}
int main()
{
    for(int T=rin();T;T--)work();
    return 0;
}

//vjudge 