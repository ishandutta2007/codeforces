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
int b[N];
int c[N];
inline bool check(int mid)
{
    for(int i=1;i<=n;i++)c[i]=c[i-1]+(a[i]>=b[mid]?1:-1);
    int maxl=-0x3f3f3f3f;
    for(int i=n-m+1;i>0;i--){maxl=max(maxl,c[i-1+m]);if(maxl>c[i-1])return true;}
    return false;
}
inline void work()
{
    n=rin();m=rin();
    for(int i=1;i<=n;i++)a[i]=b[i]=rin();
    sort(b+1,b+n+1);
    int l=1,r=n;
    int lst=-1;
    for(;l<=r;)
    {
        int mid=l+r>>1;
        if(check(mid))lst=mid,l=mid+1;
        else r=mid-1;
    }
    printf("%d\n",b[lst]);
    return;
}
int main()
{
    work();
    return 0;
}