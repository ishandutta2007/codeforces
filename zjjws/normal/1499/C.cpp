#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#define LL long long
using namespace std;
inline LL rin()
{
    LL x=0;
    char c;
    bool tag=false;
    for(c=getchar();c>'9'||c<'0';c=getchar())if(c=='-'){c=getchar();tag=true;break;}
    for(;c>='0'&&c<='9';c=getchar())x=(x<<1)+(x<<3)+(c^'0');
    if(tag)x=-x;
    return x;
}
inline void jh(int &x,int &y){if(x^y)x^=y^=x^=y;return;}
inline void jh(LL &x,LL &y){if(x^y)x^=y^=x^=y;return;}

const int N=3e5+3;
LL a[N];
inline void work()
{
    int n=rin();for(int i=1;i<=n;i++)a[i]=rin();
    LL x,y,ans;x=y=ans=0x3f3f3f3f3f3f3f3f;
    LL s_1=0,s_2=0;
    for(int i=1;i<=n;i++)
    {
        if(i%2==0)y=min(y,a[i]),s_2+=a[i];else x=min(x,a[i]),s_1+=a[i];
        if(i!=1)ans=min(ans,x*(n-(i+1>>1))+y*(n-(i>>1))+s_1+s_2);
    }
    printf("%lld\n",ans);
    return;
}
int main()
{
    for(int T=rin();T;T--)work();
    return 0;
}

//vjudge 