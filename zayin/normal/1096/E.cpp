#include<bits/stdc++.h>
#define maxn 10005
#define modu 998244353
using namespace std;
typedef long long LL;

int n,r,s;

LL F[maxn]={1},I[maxn];

LL inv(LL a)
{
    LL ans=1;
    for (int k=modu-2;k;k>>=1)
    {
        if (k&1)
            ans=(ans*a)%modu;
        a=a*a%modu;
    }
    return ans;
}

LL C(int n,int m)
{
    return n<m?0:F[n]*I[m]%modu*I[n-m]%modu;
}

LL calc(int s,int n,int r)
{
    if (!n) return !s&&r>=0;
    LL ans=0;
    for (int i=0;i<=n;++i)
    {
        LL t=C(s-r*i+n-1,n-1)*C(n,i)%modu;
        // cout<<i<<" "<<t<<endl;
        if (i&1)
            ans=(ans+modu-t)%modu;
        else
            ans=(ans+t)%modu;
    }

    // cout<<"calc:"<<s<<" "<<n<<" "<<r<<" "<<ans<<endl;
    return ans;
}

int main()
{
    scanf("%d%d%d",&n,&s,&r);
    for (int i=1;i<maxn;++i)    F[i]=F[i-1]*i%modu;
    I[maxn-1]=inv(F[maxn-1]);
    for (int i=maxn-1;i;--i)
        I[i-1]=I[i]*i%modu;

    LL ans=0;
    for (int i=max((s+n-1)/n,r);i<=s;++i)
        for (int c=1;c<=n&&c*i<=s;++c)
        {
            // cout<<i<<" "<<c<<" "<<calc(s-c*i,n-c,i)<<" "<<C(n-1,c-1)<<endl;
            ans=(ans+calc(s-c*i,n-c,i)*C(n-1,c-1)%modu*inv(c))%modu;
        }
    ans=ans*inv(C(s-r+n-1,n-1))%modu;
    printf("%lld\n",ans);
    return 0;
}