#include <stdio.h>
#include <cmath>
#pragma GCC optimize(2)
#define LL long long
using namespace std;
const int S=1e6+3;
const int N=3e5+3;
inline LL rin()
{
    LL s=0;
    bool bj=false;
    char c=getchar();
    for(;(c>'9'||c<'0')&&c!='-';c=getchar());
    if(c=='-')bj=true,c=getchar();
    for(;c>='0'&&c<='9';c=getchar())s=(s<<1)+(s<<3)+(c^'0');
    if(bj)s=-s;
    return s;
}
inline LL max(LL x,LL y){return x>y?x:y;}

bool pri[S];
int prime[N];
int cutt;
inline void init()
{
    for(int i=2;i<S;i++)
    {
        if(!pri[i])prime[++cutt]=i;
        for(int j=1;j<=cutt;j++)
        {
            int now=i*prime[j];
            if(now>=S)break;
            pri[now]=true;
            if(i%prime[j]==0)break;
        }
    }
    return;
}

int a[N];
int s[S];
bool vit[S];
inline void work()
{
    int n=rin();
    for(int i=1;i<=n;i++)
    {
        a[i]=rin();
        int ed=sqrt(a[i]);
        for(int j=1;j<=cutt&&prime[j]<=ed;j++)
        {
            int cts=0;
            for(;a[i]%prime[j]==0;a[i]/=prime[j])cts++;
            if(cts&1)a[i]*=prime[j];
        }
        s[a[i]]++;
        vit[a[i]]=false;
    }

    LL ans_1,ans_2;
    ans_1=ans_2=0;
    LL sum=0;
    for(int i=1;i<=n;i++)
    {
        if(vit[a[i]])continue;
        vit[a[i]]=true;
        ans_1=max(ans_1,s[a[i]]);
        if(s[a[i]]%2==0||a[i]==1)ans_2+=s[a[i]];
    }
    ans_2=max(ans_2,ans_1);

    for(int q=rin();q;q--)
    {
        LL w=rin();
        if(!w)printf("%lld\n",ans_1);
        else printf("%lld\n",ans_2);
    }
    for(int i=1;i<=n;i++)s[a[i]]=0;
    return;
}
int main()
{
    int i,j;
    init();
    for(int T=rin();T;T--)work();
    return 0;
}