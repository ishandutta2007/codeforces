#include <stdio.h>
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

inline void pri(LL ans,LL x,LL y,int n,int m,int xt,int yt)
{
    xt=(xt==-1);yt=(yt==-1);
    // printf("ans:%lld xt:%d yt:%d\n",ans,xt,yt);
    xt^=(((x-1)/n)&1);yt^=(((y-1)/m)&1);
    printf("%d %d\n",xt?0:n,yt?0:m);
    return;
}

inline int Gcd(int a,int b){return (!b)?(a):(Gcd(b,a%b));}
inline void Ex_Gcd(int a,int b,LL &x,LL &y){(!b)?(x=y=1):(Ex_Gcd(b,a%b,y,x),y-=x*(a/b));return;}
int n,m,x,y,xt,yt;
inline int work()
{
    if(!xt&&!yt){puts("-1");return 0;}
    if(!xt)
    {
        if(x==0||x==n)printf("%d %d\n",x,(yt==-1)?0:m);
        else puts("-1");
    }
    else
    {
        if(y==0||y==m)printf("%d %d\n",(xt==-1)?(0):n,y);
        else puts("-1");
    }
    return 0;
}
int main()
{
    n=rin();m=rin();x=rin();y=rin();xt=rin();yt=rin();
    if(xt==0||yt==0)return work();
    if(xt==-1)x=n-x;if(yt==-1)y=m-y;
    LL ans=n-x;
    int z=Gcd(n,m);
    if((-y-ans)%z){puts("-1");return 0;}
    LL X,Y;Ex_Gcd(n/z,m/z,X,Y);X*=((-ans-y)/z);X%=m;
    LL M=1LL*n/z*m;ans+=X*n;ans=(ans%M+M)%M;
    pri(ans,ans+x,ans+y,n,m,xt,yt);
    return 0;
}
/*
*/

//vjudge 