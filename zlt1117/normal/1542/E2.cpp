#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define sz(x) (int)(x.size())
#define rd (rand()<<16^rand())
#define db double
#define gc getchar()
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
const int maxn=505,maxm=maxn*maxn/2;
int n,mod;
int pre[maxn][maxm],fac[maxn],ffac[maxn],dp[maxn][maxm];///to calculate the number of i inversions
int tmp[maxm];
inline void init()
{

}
inline void input()
{
	n=gi(),mod=gi();
	fac[0]=1;
	FOR(i,1,n)fac[i]=1ll*i*fac[i-1]%mod;
	ffac[0]=1;
	FOR(i,1,n)ffac[i]=1ll*ffac[i-1]*(n-i+1)%mod;
	pre[1][0]=pre[1][1]=1;
	FOR(i,2,n)
	{
		//memset(tmp,0,sizeof(tmp));
		pre[i][0]=1;
		FOR(j,1,i*(i+1)/2)
		{
			pre[i][j]=pre[i-1][min(j,i*(i-1)/2)];
			if(j-i>=0)pre[i][j]-=pre[i-1][j-i];
			pre[i][j]+=pre[i][j-1];
			pre[i][j]=(pre[i][j]%mod+mod)%mod;
		}
		//FOR(j,0,i*(i+1)/2)printf("pre[%d][%d]=%d\n",i,j,pre[i][j]);
	}
}
inline void solve()
{
	int ans=0;
	FOR(i,1,n-1)
	{
		int sum=0,sum1=0,sum2=0;
		//FOR(k,1,n-i)
		//{
			int res=n-i;
			FOR(j,1,n-i-1)sum2=(sum2+1ll*pre[res][j]*(n-i-j)%mod)%mod,sum1=(sum1+pre[res][j])%mod;//cnt=n-i-k+1;
			//sum1=(sum1+pre[res][n-i])%mod;
			FOR(j,0,res*(res-1)/2)
			{
				sum1=(sum1+pre[res][j+n-i])%mod;
				sum2=(sum2+sum1)%mod;
				int val=pre[res][j];
				if(j)val-=pre[res][j-1];
				val=(val+mod)%mod;
				sum=(sum+1ll*val*(1ll*res*(res+1)/2%mod*fac[res]%mod\
				-sum2+mod)%mod)%mod;
				sum1=(sum1-pre[res][j+1]+mod)%mod;
				sum2=(sum2-1ll*res*pre[res][j+1]%mod+mod)%mod;
				//cerr<<sum<<endl;
			}
		//}
		//cerr<<sum<<endl;
		ans=(ans+1ll*ffac[i-1]*sum%mod)%mod;
		//cerr<<sum<<endl;
	}
	printf("%d\n",ans);
}
int main()
{
	init();
	input();
	solve();
	return 0;
}