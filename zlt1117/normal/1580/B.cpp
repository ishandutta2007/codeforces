#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define sz(x) (int)(x.size())
#define gc getchar()
#define mk make_pair
//#define gc (_p1==_p2&&(_p2=(_p1=_buf)+fread(_buf,1,100000,stdin),_p1==_p2)?EOF:*_p1++)
using namespace std;
char _buf[100000],*_p1=_buf,*_p2=_buf;
inline int gi()
{
	int x=0,f=1;
	char ch=gc;
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=gc;
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=gc;
	}
	return (f==1)?x:-x;
}
constexpr int maxn=105;
int n,m,k,p;
int dp[maxn][maxn][maxn],c[maxn][maxn],fac[maxn];
///dp[i][j][k]->length,length(remain),count
inline int DP(int x,int y,int z)
{
	if(dp[x][y][z]!=-1)return dp[x][y][z];
	dp[x][y][z]=0;
	if(x==0)return dp[x][y][z]=z==0;
	if(y==1)return z==1?dp[x][y][z]=fac[x]:0;
	//if(x==1)return dp[x][y][z]=z==0;
	if(z&&y>x)return 0;
	FOR(i,0,x-1)
	{
		unsigned ll res=0;
		FOR(j,0,z)
		{
			res=(res+1ll*DP(i,y-1,j)*DP(x-i-1,y-1,z-j));
			if(j%8==0)res%=p;
		}
		res%=p;
		res=1ll*res*c[x-1][i]%p;
		dp[x][y][z]=(dp[x][y][z]+res)%p;
	}
	return dp[x][y][z];
}
inline void input()
{
	n=gi(),m=gi(),k=gi(),p=gi();
}
inline void solve()
{
	memset(dp,-1,sizeof(dp));
	c[0][0]=1;
	fac[0]=1;
	FOR(i,1,n)
	{
		fac[i]=1ll*fac[i-1]*i%p;
		c[i][0]=1;
		FOR(j,1,n)c[i][j]=(c[i-1][j-1]+c[i-1][j])%p;
	}
	printf("%d\n",DP(n,m,k));
	//FOR(i,0,n)FOR(j,0,n)FOR(k,0,n)printf("dp[%d][%d][%d]=%d\n",i,j,k,dp[i][j][k]);
}
int main()
{
	input();
	solve();
	return 0;
}