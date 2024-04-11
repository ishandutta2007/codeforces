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

const int N=3e5+3;
int n,m;
int a[N];
int cutt;
inline void work()
{
    n=rin();
    int l=1,r=cutt;
    int ans=0;
    for(;l<=r;)
    {
        int mid=l+r>>1;
        if(a[mid]<n)ans=mid,l=mid+1;
        else r=mid-1;
    }
    printf("%d\n",ans);
    return;
}

inline void init()
{
    int ed=2e9+1;
    for(LL i=3;i*i<=ed;i++)if(i&1)a[++cutt]=(i*i-1)>>1;
    return;
}
int main()
{
    init();
    for(int T=rin();T;T--)work();
    return 0;
}

//vjudge 