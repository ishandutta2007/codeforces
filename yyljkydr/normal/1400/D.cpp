#include<bits/stdc++.h>
using namespace std;

const int N=3e3+1e2+7;

int T,n,p[N][N],a[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
                p[i][j]=p[i-1][j];
            p[i][a[i]]++;
        }
        long long ans=0;
        for(int i=2;i<=n-2;i++)
            for(int j=i+1;j<=n-1;j++)
            {
                ans+=1ll*p[i-1][a[j]]*(p[n][a[i]]-p[j][a[i]]);
            }
        printf("%lld\n",ans);
    }
}