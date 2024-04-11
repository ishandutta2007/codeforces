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
inline void work()
{
    int n,a,b;n=rin();a=rin();b=rin();
    int s_1=0,s_2=0,x=rin(),y=rin();
    s_1=(a>>1)+(b>>1);
    if((a&1)&&(b&1))s_1++;
    s_2=(n-a>>1)+(n-b>>1);
    if(((n-a)&1)&&((n-b)&1))s_2++;
    if(s_1>=x&&s_2>=y)puts("YES");else puts("NO");
    return;
}
int main()
{
    for(int T=rin();T;T--)work();
    return 0;
}

//vjudge 