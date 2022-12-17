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
int cnt[105][105];
int n,pw[maxn];
char s[maxn];
int dp[1<<23];
inline void FWT(int *a,int n)
{
	for(int l=1;l<(1<<n);l<<=1)
	{
		for(int i=0;i<(1<<n);i+=l<<1)
		{
			for(int j=0;j<l;++j)
			{
				a[i+j+l]=(a[i+j+l]+a[i+j])%mod;
			}
		}
	}
}
inline void input()
{
	n=gi();
	FOR(i,1,n)
	{
		scanf("%s",s+1);
		int l=strlen(s+1);
		FOR(j,1,l)cnt[i][s[j]-'a']++;
	}
	pw[0]=1;
	FOR(i,1,200000)pw[i]=2*pw[i-1]%mod;
}
int t[26];
inline void solve()
{
	FOR(i,1,(1<<n)-1)
	{
		memset(t,0x3f,sizeof(t));
		for(int j=0;j<n;++j)
		{
			if(i>>j&1)
			{
				FOR(k,0,25)t[k]=min(t[k],cnt[j+1][k]);
			}
		}
		int ans=1;
		FOR(j,0,25)ans=1ll*ans*(t[j]+1)%mod;
		if(__builtin_popcount(i)&1)dp[i]=ans;
		else dp[i]=(mod-ans)%mod;
	}
	FWT(dp,n);
	ll ans=0;
	FOR(i,1,(1<<n)-1)
	{
		ll sum=0,cnt=0;
		for(int j=1;j<=n;++j)if(i>>(j-1)&1)sum+=j,cnt++;
		sum*=cnt*dp[i];
		ans^=sum;
		//cerr<<sum<<endl;
	}
	printf("%lld\n",ans);
}
int main()
{
	input();
	solve();
	return 0;
}