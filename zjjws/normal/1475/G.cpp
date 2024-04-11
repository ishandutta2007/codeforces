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

bool pri[N];
int prime[N];
int cutt;
inline void init()
{
    for(int i=2;i<N;i++)
    {
        if(!pri[i])prime[++cutt]=i;
        for(int j=1;j<=cutt;j++)
        {
            int now=i*prime[j];
            if(now>=N)break;
            pri[now]=true;
            if(i%prime[j]==0)break;
        }
    }
    return;
}

int a[N];
int b[N];
int f[N];
inline void work()
{
    int n=rin();
    memset(b,0,sizeof(b));
    memset(f,0,sizeof(f));
    int maxs=0;
    int ans=0;
    for(int i=1,x;i<=n;i++)b[(x=rin())]++,maxs=max(maxs,x);
    for(int i=1;i<=maxs;i++)
    {
        f[i]+=b[i];
        ans=max(ans,f[i]);
        if(f[i])
        {
            for(int j=1;j<=cutt;j++)
            {
                int now=i*prime[j];
                if(now>maxs)break;
                f[now]=max(f[now],f[i]);
            }
        }
    }
    printf("%d\n",n-ans);
    return;
}
int main()
{
    init();
    for(int T=rin();T;T--)work();
    return 0;
}