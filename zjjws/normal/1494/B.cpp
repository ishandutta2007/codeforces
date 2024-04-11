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

LL n;
LL l,r,x,y;
inline void work()
{
    n=rin();x=rin();r=rin();y=rin();l=rin();
    if((l==n)+(r==n)>min(x,y)){puts("No");return;}
    if((x==n)+(y==n)>min(l,r)){puts("No");return;}
    int s_1=(l==n-1)+(r==n-1),s_2=(x==n-1)+(y==n-1);
    int s_3=(l==n)+(r==n),s_4=(x==n)+(y==n);
    if(s_2==2&&max(l,r)<2&&min(l,r)==0){puts("No");return;}
    if(s_2==1&&max(l,r)==0){puts("No");return;}
    if(s_2==1&&s_4==1&&(min(l,r)==0||max(l,r)<2)){puts("No");return;}
    if(s_1==2&&max(x,y)<2&&min(x,y)==0){puts("No");return;}
    if(s_1==1&&s_3==1&&(min(x,y)==0||max(x,y)<2)){puts("No");return;}
    if(s_1==1&&max(x,y)==0){puts("No");return;}
    puts("Yes");
    return;
}
int main()
{
    for(int T=rin();T;T--)work();
    return 0;
}