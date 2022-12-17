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
const int maxn=2e5+5,mod=998244353;
int fac[maxn],inv[maxn],n;
int cnt[2][2];
inline void init()
{

}
inline void input()
{
	n=gi();
	fac[0]=inv[0]=fac[1]=inv[1]=1;
	FOR(i,2,n*2)fac[i]=1ll*fac[i-1]*i%mod;
	FOR(i,2,n*2)inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
	FOR(i,2,n*2)inv[i]=1ll*inv[i-1]*inv[i]%mod;
}
inline int C(int n,int m)
{
	if(n<0||m<0||n<m)return 0;
	return 1ll*fac[n]*inv[m]%mod*inv[n-m]%mod;
}
char s[2];
inline void solve()
{
	int now=1,c1=0,c2=0,c=0;
	FOR(i,1,n)
	{
		scanf("%s",s);
		if(s[0]=='W')cnt[0][0]++;
		if(s[1]=='W')cnt[1][0]++;
		if(s[0]=='B')cnt[0][1]++;
		if(s[1]=='B')cnt[1][1]++;
		if(s[0]=='?'&&s[1]=='?')c++;
		if(s[0]=='W'&&s[1]=='W')now=0;
		if(s[0]=='B'&&s[1]=='B')now=0;
		if(s[0]=='W'||s[1]=='B')c1++;
		if(s[0]=='B'||s[1]=='W')c2++;
	}
//	if(n==1)
//	{
//		if(s[0]=='?'&&s[1]=='?')puts("2");
//		else if(s[0]=='W'&&s[1]!='W')puts("1");
//		else if(s[0]=='B'&&s[2]!='B')puts("1");
//		else if(s[1]=='W'&&s[0]!='W')puts("1");
//		else if(s[1]=='B'&&s[0]!='B')puts("1");
//		return ;  
//	}
//	else if(n%2)puts("0"),void();
//	int p=max(cnt[1],cnt[0]),q=cnt[1]+cnt[0];
//	FOR(i,p,n*2-q+p)
//	ans1=1ll*ans1*C(n*2-q,i-p);
	int ans=0;
	FOR(i,0,n)
	{
//		if(i-cnt[0][0]>1&&i-cnt[1][1]>1)
//		{
			ans=(ans+1ll*C(n-cnt[0][0]-cnt[0][1],i-cnt[0][0])%mod*\
			C(n-cnt[1][0]-cnt[1][1],i-cnt[1][1])%mod)%mod;
//		}
	}
	if(now)
	{
		FOR(i,1,c)now=1ll*now*2%mod;
		ans=(ans-now+mod)%mod;
		if(!c1)ans=(ans+1)%mod;
		if(!c2)ans=(ans+1)%mod;
	}
	printf("%d\n",ans);
}
int main()
{
	int T=1;
	//T=gi();
	while(T--)
	{
		init();
		input();
		solve();
	}
	return 0;
}