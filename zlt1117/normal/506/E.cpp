//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define sz(x) (int)(x.size())
#define rd (rand()<<16^rand())
#define db double
#define gc getchar()
#define mk make_pair
#define iter set<int>::iterator
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
const int maxn=205,mod=1e4+7;
char s[maxn];
int dp[maxn][maxn][maxn];///how many red points passed 
///from [1,n] to now
int len,n;
inline void input()
{
	scanf("%s",s+1);len=strlen(s+1);
	n=gi();
}
struct Matrix
{
	int a[305][305],n;
	Matrix(){clear();}
	inline void clear(){memset(a,0,sizeof(a));n=0;}
	inline Matrix operator * (const Matrix &b)
	{
		Matrix c;c.clear();c.n=n;
		FOR(k,0,n)FOR(i,0,k)FOR(j,k,n)c.a[i][j]=(c.a[i][j]+a[i][k]*b.a[k][j])%mod;
		//FOR(k,0,n)FOR(i,0,n)FOR(j,0,n)c.a[i][j]=(c.a[i][j]+a[i][k]*b.a[k][j])%mod;
		return c;
	}
};
inline Matrix qpow(Matrix a,int k)
{
	Matrix ans;ans.n=a.n;
	FOR(i,0,ans.n)ans.a[i][i]=1;
	while(k)
	{
		if(k&1)ans=ans*a;
		k>>=1,a=a*a;
	}
	return ans;
}
bool vis[maxn][maxn][maxn];
inline void dfs(int l,int r,int x)
{
	if(vis[l][r][x])return ;
	vis[l][r][x]=1;
	if(l==1&&r==len)return dp[l][r][x]=!x,void();
	if(l!=1&&s[l-1]!=s[r]&&x-1>=0)dfs(l-1,r,x-1),dp[l][r][x]=(dp[l][r][x]+dp[l-1][r][x-1])%mod;
	if(r!=len&&s[r+1]!=s[l]&&x-1>=0)dfs(l,r+1,x-1),dp[l][r][x]=(dp[l][r][x]+dp[l][r+1][x-1])%mod;
	if(l!=1&&r!=len&&s[l-1]==s[r+1]&&x>=0)dfs(l-1,r+1,x),dp[l][r][x]=(dp[l][r][x]+dp[l-1][r+1][x])%mod;
}
Matrix G,F;
int lim;
inline void solve()
{
	G.n=lim=len+(len+1)/2;F.n=lim;
	FOR(i,0,len-1)
	{
		int cnt=0;
		FOR(j,1,len)
		{///all green in the end
			dfs(j,j,i);cnt=(cnt+dp[j][j][i])%mod;
			if(j!=len&&s[j]==s[j+1])dfs(j,j+1,i),cnt=(cnt+dp[j][j+1][i])%mod;
		}
		if(i==0)F.a[1][len]=cnt;
		else G.a[i][i]=24;
		if(i!=0)
		{
			G.a[i][lim-(len-i+1)/2]=cnt;
			G.a[i-1][i]=1;
		}
	}
	F.a[1][1]=1;
	FOR(i,len,lim-1)G.a[i][i+1]=1,G.a[i][i]=25;///green
	G.a[lim][lim]=26;
	if((len+n)%2==0)
	{
		Matrix ans=F*qpow(G,(n+len)/2);
		printf("%d\n",ans.a[1][lim]);
	} 
	else
	{
		Matrix ans=F*qpow(G,(n+len+1)/2);
		int answer=ans.a[1][lim];
		G.a[lim][lim]=0;
		FOR(i,0,len-1)
		{
			int cnt=0;
			FOR(j,1,len)
			{///all green in the end
				if(j!=len&&s[j]==s[j+1])dfs(j,j+1,i),cnt=(cnt+dp[j][j+1][i])%mod;
			}
			if(i==0)F.a[1][len]=cnt;
			else G.a[i][i]=24;
			if(i!=0)
			{
				G.a[i][lim-(len-i+1)/2]=cnt;
				G.a[i-1][i]=1;
			}
		}
		FOR(i,len,lim-1)G.a[i][i+1]=1,G.a[i][i]=25;///green
		G.a[lim][lim]=0;
		ans=F*qpow(G,(n+len+1)/2);
		answer=(answer-ans.a[1][lim]+mod)%mod;
		printf("%d\n",answer);
	}
}
int main()
{
	input();
	solve();
	return 0;
}
/*
abcdedcba
10000000
*/