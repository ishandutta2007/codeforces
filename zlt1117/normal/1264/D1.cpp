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
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
const int maxn=2005,mod=998244353;
int n,pre[maxn][maxn],suf[maxn][maxn];
char s[maxn];
inline void input()
{
	scanf("%s",s+1);
	n=strlen(s+1);
}
inline void solve()
{
	pre[0][0]=1,suf[n+1][0]=1;
	FOR(i,1,n)
	{
		FOR(j,0,n)
		{
			if(s[i]=='(')pre[i][j]=j==0?0:pre[i-1][j-1];
			else if(s[i]==')')pre[i][j]=pre[i-1][j];
			else pre[i][j]=(pre[i-1][j]+(j==0?0:pre[i-1][j-1]))%mod;
			//printf("pre[%d][%d]=%d\n",i,j,pre[i][j]);
		}
		//if(s[i]!='(')pre[i][0]=1;
	}
	for(int i=n;i>=1;--i)
	{
		for(int j=0;j<=n;++j)
		{
			if(s[i]==')')suf[i][j]=j==0?0:suf[i+1][j-1];
			else if(s[i]=='(')suf[i][j]=suf[i+1][j];
			else suf[i][j]=(suf[i+1][j]+(j==0?0:suf[i+1][j-1]))%mod;
			//printf("suf[%d][%d]=%d\n",i,j,suf[i][j]);
		}
		//if(s[i]!=')')suf[i][0]=1;
	}
	int ans=0;
	FOR(i,1,n)
	{
		FOR(j,1,n)
		{
			int sum=0;
			sum=1ll*pre[i][j]*suf[i+1][j]%mod;
			//if(s[i]=='?')sum=(sum+2ll*pre[i-1][j]*suf[i+1][j])%mod;
			ans=(ans+1ll*sum*j)%mod; 
			//if(sum>0)printf("i=%d j=%d sum=%d val=%d\n",i,j,sum,j); 
		}
	}
	printf("%d\n",ans);
}
int main()
{
	input();
	solve();
	return 0;
}