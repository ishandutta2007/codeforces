#include<bits/stdc++.h>
#define maxn 10050
using namespace std;

int dp[maxn][maxn];

int n,m;
char s[maxn],t[maxn];

int pre[maxn];
int stk[maxn],tp;

int main()  {
    scanf("%s%s",s+1,t+1);
    n=strlen(s+1),m=strlen(t+1);

    for (int i=1;i<=n;++i) {
        if (s[i]!='.')
            stk[++tp]=i;
        else    {
            if (tp)
                pre[i]=stk[tp--];
        }
    }

    memset(dp,0x3f,sizeof(dp));
    for (int i=0;i<=n;++i) dp[i][0]=i;
    for (int i=1;i<=n;++i)  {
        for (int j=0;j<=m;++j)  {
            //del
            dp[i][j]=min(dp[i][j],dp[i-1][j]+1);

            //not del
            if (j&&s[i]==t[j]) 
                dp[i][j]=min(dp[i][j],dp[i-1][j-1]);
            if (s[i]=='.'&&pre[i])
                // cout<<i<<":"<<pre[i]<<" "<<j<<" "<<dp[pre[i]-1][j]<<endl,
                dp[i][j]=min(dp[i][j],dp[pre[i]-1][j]);
            
        }

        // cout<<i<<":"<<pre[i]<<" "<<(s[i]=='.')<<endl;
        // for (int j=0;j<=m;++j)
        //     cout<<"dp["<<i<<"]["<<j<<"]="<<dp[i][j]<<endl;
        // cout<<endl;
    }

    printf("%d\n",dp[n][m]);
    return 0;
}