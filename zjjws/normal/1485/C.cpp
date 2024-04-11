#include <cmath>
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

const int N=4e4+3;
int n;

int pri[N];
int d[N];
int tail;
inline void init()
{
    for(int i=2;i<N;i++)
    {
        if(!pri[i])d[++tail]=i;
        for(int j=1;j<=tail;j++)
        {
            int now=i*d[j];
            if(now>=N)break;
            pri[now]=true;
            if(i%d[j]==0)break;
        }
    }
    return;
}

inline LL prpr(int x,int y)
{
    LL ans=0;
    for(int l=1,r;l<=x&&l<=y+1;l=r+1)
    {
        r=x/(x/l);r=min(r,min(x,y+1));
        ans+=1LL*(x/l)*(r-l+1);
    }
    return ans-x;
}
inline void work()
{
    int x=rin(),y=rin();
    //a  y 
    // a 
    // a  a/x<=y
    LL ans=0;
    int ed=min(y,100000);
    for(int b=1;b<=ed;b++)ans+=min(x/(b+1),b-1);
    if(y==ed){printf("%lld\n",ans);return;}
    ans+=prpr(x,y)-prpr(x,100000);
    printf("%lld\n",ans);
    return;
}
int main()
{
    for(int T=rin();T;T--)work();
    return 0;
}