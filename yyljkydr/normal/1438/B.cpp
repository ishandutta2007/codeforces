#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=1e3+1e1+7;

int T,n,s[N][N],t[N][N],a[N];

ll qpow(ll a,ll b,int P)
{
    ll ret=1;
    while(b&1)
    {
        ret=ret*a%P;
        b>>=1;
        a=a*a%P;
    }
    return ret;
}

set<pair<int,int> >S    ;

#define mp make_pair

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        bool ok=0;
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
            {
                ok|=a[i]==a[j];
            }
        puts(ok?"YES":"NO");
    }
}