#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
const int Max_Num=1500+100;
const ll inf=1LL<<60;
int n,m;
ll A[Max_Num][Max_Num];
ll Dp[Max_Num][Max_Num];
int main()
{
    //freopen("in","r",stdin);
    scanf("%d%d",&n,&m);int x;
    rep(i,n)rep(j,m)scanf("%d",&x),A[i][j]=x;
    rep(i,n)rep(j,m-1)A[i][j+1]+=A[i][j];
    rep(j,m)Dp[0][j]=A[0][j];
    for(int i=1;i<n;i++)
    {
        if(i%2==1)
        {
            Dp[i][m-1]=-inf;
            for(int j=m-2;j>=0;j--)
                Dp[i][j]=max(Dp[i-1][j+1],Dp[i][j+1]-A[i][j+1])+A[i][j];
        }
        else
        {
            Dp[i][0]=-inf;
            for(int j=1;j<m;j++)
                Dp[i][j]=max(Dp[i-1][j-1],Dp[i][j-1]-A[i][j-1])+A[i][j];
        }
    }
    ll ans=-inf;
    rep(j,m)ans=max(ans,Dp[n-1][j]);
    cout<<ans<<endl;
}