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
int n;
int a[N];
inline void ask(int l,int r){printf("? %d %d\n",l,r);fflush(stdout);return;}
inline void find(int x){printf("! %d\n",x);fflush(stdout);return;}
inline void work()
{
    n=rin();
    if(n==1){find(1);return;}
    int l=1,r=n;
    ask(1,n);
    int x=rin(),y,z;
    for(;l<r;)
    {
        if(l==r-1){find(l==x?r:l);return;}
        y=-1,z=-1;
        int mid=l+r>>1;
        if(x<=mid){ask(l,mid);y=rin();if(y!=x){l=mid+1;if(l!=r)ask(l,r),x=rin();}else {r=mid;x=y;}}
        else {ask(mid,r);y=rin();if(y!=x){r=mid-1;if(l!=r)ask(l,r),x=rin();}else {l=mid;x=y;}}
    }
    find(l);
    return;
}
int main()
{
    work();
    return 0;
}

//vjudge 