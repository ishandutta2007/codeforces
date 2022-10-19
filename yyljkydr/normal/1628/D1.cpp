#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=2e3+1e2+7,P=1e9+7,iv2=(P+1)/2;

int T;

int n,m,k;

int f[N][N];

signed main()
{
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld%lld%lld",&n,&m,&k);
        for(int i=1;i<=n;i++)
            for(int j=0;j<=i;j++)
            {
                if(i==j)
                    f[i][j]=(f[i-1][j-1]+k)%P;
                else if(j==0)
                    f[i][j]=f[i-1][j];
                else
                    f[i][j]=(f[i-1][j-1]+f[i-1][j])*iv2%P;
            }
        printf("%lld\n",f[n][m]);
    }
}