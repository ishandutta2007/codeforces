#include<bits/stdc++.h>
#define maxn 200050
using namespace std;
typedef long long LL;

int n,m,M,I2;

map<int,int> cnt;
LL inv[maxn];

void divide(int m,int l,int r)
{
    if (m==1||l==r)
        ++cnt[r-l+1];
    else
    {
        int mid=(l+r)>>1;
        divide(m-1,l,mid);
        divide(m-1,mid+1,r);
    }
}

LL pw(LL a,LL k)
{
    LL ans=1;
    for (;k;k>>=1)
    {
        if (k&1)
            ans=ans*a%M;
        a=a*a%M;
    }
    return ans;
}

void init()
{
    scanf("%d%d%d",&n,&m,&M);
    divide(m,1,n);
    I2=(M+1)>>1;
    for (int i=1;i<maxn;++i)
        inv[i]=(inv[i-1]+pw(i,M-2))%M;
}

LL C2(int x)
{
    return 1LL*x*(x-1)/2%M;
}

LL calc(int a,int b)
{
    LL ans=1LL*a*b%M*I2%M;
    for (int i=1;i<=a;++i)
        ans+=M-inv[i+b]+inv[i];
    return ans%M;
}

void solve()
{
    int ans=0;
    for (auto p:cnt)
        ans+=1LL*C2(p.first)*I2%M*p.second%M,ans%=M;
    for (auto p:cnt)
    {
        ans+=calc(p.first,p.first)*C2(p.second)%M,ans%=M;
        for (auto q:cnt)
            if (p.first<q.first)
                ans+=calc(p.first,q.first)*(p.second*q.second%M)%M,ans%=M;
    }
    printf("%d\n",ans);
}
int main()
{
    init();
    solve();
    return 0;
}