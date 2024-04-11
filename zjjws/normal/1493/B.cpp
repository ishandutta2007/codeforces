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
int h,m;
int a,b;
inline int ps(int x)
{
    if(x<=1)return x;
    if(x==2)return 5;
    if(x==5)return 2;
    if(x==8)return 8;
    return -1;
}
inline int cl(int x)
{
    int s_1=x/10,s_2=x%10;if(ps(s_1)>=0&&ps(s_2)>=0)return ps(s_2)*10+ps(s_1);
    return -1;
}
inline int ct(int x,int y)
{
    int dis=0;dis+=(x-a)*m+(y-b);
    if(dis<0)dis+=h*m;
    return dis;
}
inline void work()
{
    h=rin();m=rin();a=rin();b=rin();
    int dis=0x3f3f3f3f;
    int X,Y;
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<m;j++)
        {
            int x=cl(j),y=cl(i);
            if(x<0||y<0||x>=h||y>=m)continue;
            int nows=ct(x,y);
            if(nows<dis)dis=nows,X=x,Y=y;
        }
    }
    if(X<10)printf("0");printf("%d:",X);
    if(Y<10)printf("0");printf("%d\n",Y);
    return;
}
int main()
{
    for(int T=rin();T;T--)work();
    return 0;
}

//vjudge 