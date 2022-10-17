#include<bits/stdc++.h>
using namespace std;
const int MAXN=1005;
int a[MAXN][MAXN];
int vis[MAXN][MAXN],usd[MAXN][MAXN];
int solve()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    for(int i=1;i<=n;i++)
    {
        memset(vis[i],0,(n+2)*sizeof(int));
        memset(usd[i],0,(n+2)*sizeof(int));
    }
    for(int i=2;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(!vis[i-1][j])
            {
                usd[i][j]=1;
                vis[i][j-1]^=1;
                vis[i][j+1]^=1;
                vis[i-1][j]^=1;
                vis[i+1][j]^=1;
            }
    int res=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(usd[i][j])res^=a[i][j];
    return 0*printf("%d\n",res);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}