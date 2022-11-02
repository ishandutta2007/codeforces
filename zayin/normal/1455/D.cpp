#include<bits/stdc++.h>
#define maxn 550
using namespace std;

int n,m,a[maxn];
int dp[2][maxn][maxn];

void upd(int &a,int b)  {
    a=min(a,b);
}

int main()  {
    int T;
    scanf("%d",&T);
    while (T--) {
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;++i)
            scanf("%d",a+i);
        
        int now=0;
        memset(dp,0x3f,sizeof(dp));
        dp[now][0][m]=0;
        for (int i=1;i<=n;++i)  {
            now^=1;
            memset(dp[now],0x3f,sizeof(dp[now]));
            for (int x=0;x<maxn;++x)
                for (int y=0;y<maxn;++y)    {
                    if (dp[now^1][x][y]>n) continue;
                    // cout<<x<<" "<<y<<":"<<dp[now^1][x][y]<<endl;
                    if (a[i]>=x)
                        upd(dp[now][a[i]][y],dp[now^1][x][y]);
                    if (y>=x&&a[i]>y)
                        upd(dp[now][y][a[i]],dp[now^1][x][y]+1);
                }
            // for (int x=0;x<maxn;++x)
            //     for (int y=0;y<maxn;++y)
            //         if (dp[now][x][y]<=n)
            //             cout<<"dp["<<i<<"]["<<x<<"]["<<y<<"]="<<dp[now][x][y]<<endl;
        }
        int ans=1e9;
        for (int x=0;x<maxn;++x)
            for (int y=0;y<maxn;++y)
                ans=min(ans,dp[now][x][y]);
        
        if (ans>n) ans=-1;
        printf("%d\n",ans);
    }
    return 0;
}