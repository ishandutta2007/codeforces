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

const int N=1e3+3;
const int M=1e9+7;
inline int prpr(int x,int y){return 1LL*x*y%M;}
inline int ksm(int x,int y){int ans=1;for(;y;y>>=1){if(y&1)ans=prpr(ans,x);x=prpr(x,x);}return ans;}

int sl[N];
int sr[N];
inline void init()
{
    sl[0]=sr[0]=1;
    for(int i=1;i<N;i++)sl[i]=prpr(sl[i-1],i);
    sr[N-1]=ksm(sl[N-1],M-2);
    for(int i=N-2;i>=1;i--)sr[i]=prpr(sr[i+1],i+1);
    return;
}
inline int C(int a,int b){return (b>a)?(0):(prpr(prpr(sl[a],sr[b]),sr[a-b]));}
int a[N];
inline bool myru(int x,int y){return x>y;}
inline void work()
{
    int n,m;
    n=rin();m=rin();
    for(int i=1;i<=n;i++)a[i]=rin();
    sort(a+1,a+n+1,myru);
    int cutt=0;
    for(int i=1;i<=m;i++)if(a[i]!=a[i-1])cutt=1;else cutt++;
    int sum=cutt;
    for(int i=m+1;i<=n&&a[i]==a[m];i++)sum++;
    printf("%d\n",C(sum,cutt));
    return;
}
int main()
{
    init();
    for(int T=rin();T;T--)work();
    return 0;
}