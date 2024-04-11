#include<bits/stdc++.h>
using namespace std;

const int N=1e3+7,P=1e9+7;

int T,n,k,f[N][N];

signed main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++)
            f[i][1]=1;
        f[0][1]=1;
        for(int t=2;t<=k;t++)
        {
            f[0][t]=1;
            for(int i=1;i<=n;i++)
                f[i][t]=(f[i-1][t]+f[n-i][t-1])%P;
        }
        printf("%d\n",f[n][k]);
    }
}
/*
f[i][k] = f[i-1][k] + f[n-i][k-1]
*/