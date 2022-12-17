#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define sz(x) (int)(x.size())
#define rd (rand()<<16^rand())
#define db double
#define mk make_pair
#define iter set<int>::iterator
#define gc getchar()//(_p1==_p2&&(_p2=(_p1=_buf)+fread(_buf,1,100000,stdin),_p1==_p2)?EOF:*_p1++)
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
const int maxn=1e5+5,B=1605,mod=998244353;
int n,a[maxn],dp[2][B];
vector<int>state[2];
inline void init()
{
	memset(dp,0,sizeof(dp));
	FOR(i,1,n)a[i]=0;
}
inline vector<int>count(int x)
{
	int l=1;
	vector<int>ret;
	while(l<=x)
	{
		int r=x/(x/l);
		ret.pb(l);
		ret.pb(r);
		l=r+1;
	}
	return ret;
}
inline void input()
{
	n=gi();
	FOR(i,1,n)a[i]=gi();
}
inline void solve()
{
	int now=0,last=0,ans=0;
	state[0]=count(a[n]);dp[now][0]=1;
	for(int i=n-1;i>=1;--i)
	{
		now=now^1,last=now^1;
		memset(dp[now],0,sizeof(dp[now]));
		state[now]=count(a[i]);
		//FOR(j,1,sz(state[last])-1)dp[last][j]=(dp[last][j-1]+dp[last][j])%mod;
		int p=0,sum=0;
		FOR(j,0,sz(state[now])-1)
		{
			int nows=sum;
			while(p<sz(state[last])&&a[i+1]/state[last][p]>=(a[i]/state[now][j]+(a[i]%state[now][j]!=0)))
			{
				sum=(sum+dp[last][p])%mod;
				p++;
			}
			int t=(sum-nows+mod)%mod;
			ans=(ans+1ll*t*i%mod*(state[now][j]-1+mod))%mod;
			dp[now][j]=(dp[now][j]+t)%mod;
		}
		dp[now][0]=(dp[now][0]+1)%mod;
	}
	printf("%d\n",ans);
}
int main()
{
	int T=1;
	T=gi();
	while(T--)
	{
		init();
		input();
		solve();
	}
	return 0;
}