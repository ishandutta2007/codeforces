#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=1e6+1e3+7;

int T,n,m;

int a[N];

vector<int>v;

int f[N][2];

signed main()
{
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld%lld",&n,&m);
        int ans=0,sum=0;
        for(int i=1;i<=n;i++)
            scanf("%lld",&a[i]),sum+=a[i];
        ans=sum;
        int g=0;
        for(int i=1;i<=m;i++)
        {
            int x;
            scanf("%lld",&x);
            g=__gcd(g,x);
        }
        f[0][0]=f[0][1]=0;
        for(int i=1;i<=g;i++)
        {
            v.clear();
            for(int j=i;j<=n;j+=g)
                v.push_back(a[j]);
            f[i][0]=0;
            f[i][1]=-1e18;
            for(auto x:v)
            {
                int f0=max(f[i][0]+x,f[i][1]-x);
                int f1=max(f[i][1]+x,f[i][0]-x);
                f[i][0]=f0;
                f[i][1]=f1;
            }
            f[0][0]+=f[i][0];
            f[0][1]+=f[i][1];
        }
        printf("%lld\n",max(f[0][0],f[0][1]));
    }
}