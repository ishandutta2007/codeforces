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
inline int min(int x,int y){return x<y?x:y;}
inline int max(int x,int y){return x>y?x:y;}
inline LL min(LL x,LL y){return x<y?x:y;}
inline LL max(LL x,LL y){return x>y?x:y;}
inline void jh(int &x,int &y){if(x!=y)x^=y^=x^=y;return;}
inline void jh(LL &x,LL &y){if(x!=y)x^=y^=x^=y;return;}

const int N=3e5+3;
int n,q,k;
int a[N];
LL f[N];

inline void work()
{
    n=rin();q=rin();k=rin();
    for(int i=1;i<=n;i++)a[i]=rin();
    for(int i=1;i<n;i++)f[i]=f[i-1]+a[i+1]-a[i-1]-2;
    for(;q;q--)
    {
        int l=rin(),r=rin();
        if(l==r)printf("%d\n",k-1);
        else printf("%lld\n",f[r-1]-f[l]+(k-a[r])+(a[r]-a[r-1]-1)+(a[l]-1)+(a[l+1]-a[l]-1));
    }
    return;
}

//
int main()
{
    work();
    return 0;
}