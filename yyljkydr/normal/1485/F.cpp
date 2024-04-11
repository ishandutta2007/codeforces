#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=2e5+1e3+7,P=1e9+7;

int T,n,b[N];

map<ll,ll>f;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&b[i]);
        f.clear();
        // f[0][0]=1;
        // for(int i=0;i<n;i++)
        //     for(auto [x,y]:f[i])
        //     {
        //         f[i+1][b[i+1]]+=y;
        //         if(x)
        //             f[i+1][b[i+1]+x]+=y;
        //     }
        // ll ans=0;
        // for(auto [x,y]:f[n])
        //     ans+=y;
        ll sum=1,dlt=0,f0=1;
        // f[i+1][b[i+1]] = sum;//j==b[i+1]
        // f[i+1][j] = f[i][j-b[i+1]];//
        f[0]=1;
        for(int i=1;i<=n;i++)
        {
            ll s=sum;
            sum=(sum*2%P-f0+P)%P;
            dlt+=b[i];
            f[b[i]-dlt]=s;
            f0=f[-dlt];
        }
        printf("%lld\n",sum);
    }
}