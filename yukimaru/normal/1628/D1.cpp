#include<bits/stdc++.h>
using namespace std;
const int MAXN=2005;
const int Mod=1000000007;
const int Inv2=(Mod+1)/2;
int dp[MAXN][MAXN];
int solve()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    int res=1LL*dp[n][m]*k%Mod;
    return 0*printf("%d\n",res);
}
void build()
{
    for(int i=1;i<MAXN;i++)
        for(int j=0;j<=i;j++)
        {
            if(i==j)dp[i][j]=(dp[i-1][j-1]+1)%Mod;
            else dp[i][j]=1LL*(dp[i-1][j]+(j>0 ? dp[i-1][j-1] : 0))*Inv2%Mod;
        }
}
int main()
{
    build();
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}