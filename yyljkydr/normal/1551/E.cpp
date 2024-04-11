#include<bits/stdc++.h>
using namespace std;

const int N=2e3+1e2+7;

int T,n,f[N][N],a[N],k;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        f[0][0]=0;
        for(int i=1;i<=n;i++)
        {
            f[i][0]=f[i-1][0]+(a[i]==i);
            for(int j=1;j<=i;j++)
            {
                f[i][j]=max(f[i-1][j]+(a[i]==i-j),f[i-1][j-1]);
            }
        }
        int ans=-1;
        for(int i=0;i<=n;i++)
            if(f[n][i]>=k)
            {
                ans=i;
                break;
            }
        printf("%d\n",ans);
    }
}