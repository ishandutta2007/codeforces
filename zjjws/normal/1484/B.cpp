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
int n;
int a[N];
inline void work()
{
    n=rin();for(int i=1;i<=n;i++)a[i]=rin();
    bool tag=true;
    for(int i=1;i<=n;i++)if(a[i]!=a[1]){tag=false;break;}if(tag){puts("0");return;}
    LL s_1=0,s_2=0;
    for(int i=2;i<=n;i++){int s=a[i]-a[i-1];if(!s){puts("-1");return;}if(s>0){if(!s_1)s_1=s;if(s_1!=s){puts("-1");return;}}}
    for(int i=2;i<=n;i++){int s=a[i]-a[i-1];if(s<0){if(!s_2)s_2=s;if(s_2!=s){puts("-1");return;}}}
    if(!s_1||!s_2){puts("0");return;}
    for(int i=1;i<=n;i++)if(s_1-s_2<=a[i]){puts("-1");return;}
    printf("%lld %lld\n",s_1-s_2,s_1);
    return;
}
int main()
{
    for(int T=rin();T;T--)work();
    return 0;
}

//vjudge 