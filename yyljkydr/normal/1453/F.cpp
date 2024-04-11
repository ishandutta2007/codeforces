#include<bits/stdc++.h>
using namespace std;

const int N=3e3+1e1+7;

int T,n;

int f[N][N],mn[N][N],tag[N],a[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n+1;j++)
                f[i][j]=1e9,mn[i][j]=1e9,tag[i]=0;
        f[n][n+1]=0;
        mn[n][n+1]=0;
        for(int i=n-1;i>=1;i--)
        {
            for(int j=i+1;j<=i+a[i];j++)
                f[i][j]=min(f[i][j],mn[j][i+a[i]+1]+tag[j]);
            for(int j=i+1;j<=i+a[i];j++)
                tag[j]++;
            for(int j=n;j>i;j--)
                mn[i][j]=min(mn[i][j+1],f[i][j]);
        }
        printf("%d\n",mn[1][2]);
    }
}