#include <cmath>
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

const int N=2e5+3;
const int P=1.8e4+3;
const int M=1e9+7;
inline int prpr(int x,int y){return 1LL*x*y%M;}
inline int ksm(int x,int y){int ans=1;for(;y;y>>=1){if(y&1)ans=prpr(ans,x);x=prpr(x,x);}return ans;}
int n,q;
int a[N];
int ans;

bool pri[N];
int prime[N];
int tail;
int tail2;
int qy[N];

int st[P];
int ls[N<<5];
int rs[N<<5];
int f[N<<5];
int nam;
inline int new_node(){f[++nam]=0;return nam;}
inline void bing(int i){f[i]=min(f[ls[i]],f[rs[i]]);return;}
inline void add(int l,int r,int i,int x,int y)
{
    if(l==r){f[i]+=y;return;}
    int mid=l+r>>1;
    if(x<=mid){if(!ls[i])ls[i]=new_node();add(l,mid,ls[i],x,y);}
    else {if(!rs[i])rs[i]=new_node();add(mid+1,r,rs[i],x,y);}
    bing(i);
    return;
}
inline void add_(int l,int r,int i,int x,int y){int lst=f[i];add(l,r,i,x,y);if(f[i]>lst)ans=prpr(ans,ksm(prime[i],f[i]-lst));return;}
inline void init()
{
    int L=sqrt(N-1);
    for(int i=2;i<=L;i++)
    {
        if(!pri[i])prime[++tail]=i,qy[i]=tail;
        for(int j=1;j<=tail;j++)
        {
            int now=i*prime[j];
            if(now>=N)break;
            pri[now]=true;
            if(i%prime[j]==0)break;
        }
    }
    tail2=tail;
    for(int i=L+1;i<N;i++)
    {
        if(!pri[i])prime[++tail2]=i,qy[i]=tail2;
        for(int j=1;j<=tail2;j++)
        {
            int now=i*prime[j];
            if(now>=N)break;
            pri[now]=true;
            if(i%prime[j]==0)break;
        }
    }
    ans=1;for(int i=1;i<=tail2;i++)st[i]=new_node();
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=tail;j++)
        {
            if(a[i]%prime[j])continue;
            int cts=0;
            for(;a[i]%prime[j]==0;a[i]/=prime[j])cts++;
            add(1,n,st[j],i,cts);
        }
        if(a[i]!=1)add(1,n,st[qy[a[i]]],i,1);
    }
    for(int i=1;i<=tail2;i++)ans=prpr(ans,ksm(prime[i],f[i]));
    return;
}

inline void work()
{
    //
    int i=rin(),x=rin();a[i]=x;
    for(int j=1;j<=tail;j++)
    {
        if(x%prime[j])continue;
        int cts=0;
        for(;x%prime[j]==0;x/=prime[j])cts++;
        add_(1,n,j,i,cts);
    }
    if(x!=1)add_(1,n,st[qy[x]],i,1);
    printf("%d\n",ans);
    return;
}
int main()
{
    n=rin();q=rin();for(int i=1;i<=n;i++)a[i]=rin();init();
    for(;q;q--)work();
    return 0;
}

//vjudge 

/*
5 5
26 52 52 104 78
1 2
2 2
3 4
4 2
5 2
*/