#include<cstdio>
#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<cstring>
#define rep(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define All(x) x.begin(),x.end()
using namespace std;
const int maxn=100+10;
int a[maxn],n,m;
double C[maxn][maxn],P[maxn],all;
double c=0;
int L[maxn];
double Dp[maxn];
void PreCal()
{
    C[0][0]=1;
    for(int i=1;i<maxn;i++)
    {
        C[i][0]=C[i][i]=1;
        for(int j=1;j<i;j++)
            C[i][j]=C[i-1][j-1]+C[i-1][j];
    }
}
double F(int x)
{
    rep(i,m)
        L[i]=a[i]*x;
    memset(Dp,0,sizeof Dp);
    Dp[0]=1;
    rep(i,m)
    {
        for(int j=n;j>=0;j--)
        {
            for(int ch=1;ch<=j&&ch<=L[i];ch++)
                Dp[j]+=Dp[j-ch]*C[n-j+ch][ch];
        }
    }
    return Dp[n]/all;
}
double f[maxn];
int main()
{
    //freopen("in","r",stdin);
    cin>>n>>m;all=1;
    rep(i,m)cin>>a[i];
    rep(i,n)all*=m;
    PreCal();
    for(int i=0;i<=n;i++)
        f[i]=F(i);
    double ans=0;
    for(int i=1;i<=n;i++)
    {
        double p=f[i]-f[i-1];
        ans+=p*i;
    }
    printf("%0.15lf\n",ans);
}