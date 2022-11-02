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
    int l=1,r=n;
    int x,y;
    ask(1,n);x=rin();if(x==1)l=x+1;if(x==n)r=x-1;
    if(x!=1&&x!=n){ask(1,x);y=rin();if(x==y)r=x-1;else l=x+1;}
    int lst;
    if(x==l-1)
    {
        for(;l<=r;)
        {
            int mid=l+r>>1;ask(x,mid);
            if(rin()==x)lst=mid,r=mid-1;
            else l=mid+1;
        }
    }
    else
    {
        for(;l<=r;)
        {
            int mid=l+r>>1;ask(mid,x);
            if(rin()==x)lst=mid,l=mid+1;
            else r=mid-1;
        }
    }
    find(lst);
    return;
}
int main()
{
    work();
    return 0;
}