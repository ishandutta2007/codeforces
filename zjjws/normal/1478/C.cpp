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
    if(bj)s=-s;
    return s;
}

const int N=3e5+3;

inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
inline LL max(LL x,LL y){return x>y?x:y;}
inline LL min(LL x,LL y){return x<y?x:y;}
inline void jh(int x,int y){if(x!=y)x^=y^=x^=y;return;}
inline void jh(LL x,LL y){if(x!=y)x^=y^=x^=y;return;}

int n,m;
LL a[N];
inline void work()
{
    n=rin();m=(n<<1);
    for(int i=1;i<=m;i++)a[i]=rin();
    sort(a+1,a+m+1);
    LL les=0;
    LL sum=0;
    for(int i=1,j;i<=m;i=j)
    {
        for(j=i;j<=m&&a[j]==a[i];j++);
        if(j-i!=2){puts("NO");return;}
        if(a[i]&1){puts("NO");return;}
        if(i>1&&(a[i]-a[i-1])%(i-1)){puts("NO");return;}
        if(i>1)les+=(a[i]-a[i-1])/(i-1);
        sum+=les;
    }
    sum=a[1]-(sum<<1);
    if(sum>0&&sum%m==0)puts("YES");
    else puts("NO");
    return;
}
int main()
{
    int i,j;
    for(int T=rin();T;T--)work();
    return 0;
}