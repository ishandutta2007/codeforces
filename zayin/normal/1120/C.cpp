#include<bits/stdc++.h>
#define maxn 5050
using namespace std;

int n,a,b;
char s[maxn];

int len[maxn][maxn];

int nxt[maxn];

int dp[maxn];

int main()  {
    scanf("%d%d%d%s",&n,&a,&b,s+1);

    for (int i=n;i;--i)  
        for (int j=i;j<=n;++j)
            if (s[i]==s[j])
                len[i][j]=len[i+1][j+1]+1;
    
    // for (int i=1;i<=n;++i)
    //     for (int j=i;j<=n;++j)
    //         cout<<i<<" "<<j<<" "<<len[i][j]<<endl;
    // cout<<endl;
    for (int i=1;i<=n;++i)  {
        for (int j=1;j<=i;++j)  {
            int l=min(i-j,len[j][i]);
            nxt[i]=max(nxt[i],l);
        }
    }

    memset(dp,0x3f,sizeof(dp));
    dp[0]=0;
    for (int i=0;i<n;++i)  {
        dp[i+1]=min(dp[i+1],dp[i]+a);
        dp[i+nxt[i+1]]=min(dp[i+nxt[i+1]],dp[i]+b);
    }
    // for (int i=0;i<=n;++i)
    //     cout<<i<<" "<<dp[i]<<" "<<nxt[i]<<endl;
    printf("%d\n",dp[n]);
    return 0;
}