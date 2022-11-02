#include <string>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
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

const int N=2e5+3;


int X[N];
int Y[N];
struct gyq
{
    int x,y;
    int cutt;
    gyq(int x_=0,int y_=0,int cutt_=0){x=x_;y=y_;cutt=cutt_;}
}a[N];
inline bool myru_gyq(gyq x,gyq y){return x.x==y.x?x.y<y.y:x.x<y.x;}
inline bool myru_zjj(gyq x,gyq y){return x.y==y.y?x.x<y.x:x.y<y.y;}
inline void work()
{
    int n,m,k;
    n=rin();m=rin();k=rin();
    for(int i=1;i<=k;i++)X[i]=rin();
    for(int i=1;i<=k;i++)Y[i]=rin(),a[i]=gyq(X[i],Y[i],0);
    sort(a+1,a+k+1,myru_gyq);
    int nam=0;
    for(int i=1,j;i<=k;i=j)
    {
        for(j=i+1;j<=k&&a[j].x==a[i].x&&a[j].y==a[i].y;j++);
        a[++nam]=gyq(a[i].x,a[i].y,j-i);
    }

    LL ans=1LL*k*(k-1)>>1;
    LL sum=0;
    for(int i=1;i<=nam;i++)
    {
        if(a[i].x!=a[i-1].x)sum=0;
        else ans-=sum;
        sum+=a[i].cutt;
    }

    for(int i=1;i<=k;i++)a[i]=gyq(X[i],Y[i],0);
    sort(a+1,a+k+1,myru_zjj);
    nam=0;
    for(int i=1,j;i<=k;i=j)
    {
        for(j=i+1;j<=k&&a[j].x==a[i].x&&a[j].y==a[i].y;j++);
        a[++nam]=gyq(a[i].x,a[i].y,j-i);
        ans-=1LL*(j-i)*(j-i-1)>>1;
    }

    sum=0;
    for(int i=1;i<=nam;i++)
    {
        if(a[i].y!=a[i-1].y)sum=0;
        else ans-=sum;
        sum+=a[i].cutt;
    }
    printf("%lld\n",ans);
    return;
}
int main()
{
    for(int T=rin();T;T--)work();
    return 0;
}