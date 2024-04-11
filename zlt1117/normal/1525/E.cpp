//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define PLL pair<ll,ll>
#define fi first
#define se second
#define sz(x) (int)(x.size())
#define rd (rand()<<16^rand())
#define db double
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
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
const int maxn=25,maxm=50005,mod=998244353;
vector<int>a[maxn];
int fac[maxn],inv[maxn],n,m;
inline void init()
{
	fac[0]=fac[1]=inv[0]=inv[1]=1;
	FOR(i,2,maxn-1)fac[i]=1ll*fac[i-1]*i%mod,inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
	FOR(i,2,maxn-1)inv[i]=1ll*inv[i-1]*inv[i]%mod;
}
inline void input()
{
	n=gi(),m=gi();
	FOR(i,1,n)a[i].resize(m+1);
	FOR(i,1,n)FOR(j,1,m)a[i][j]=gi();
}
inline void solve()
{
	int ans=0;
	FOR(i,1,m)
	{
		vector<int>now;
		FOR(j,1,n)now.pb(a[j][i]);
		sort(now.begin(),now.end());
		int sum=0,nows=1;
		FOR(j,0,sz(now)-1)
		{
			if(now[j]==n+1)break;
			int res=n-now[j]+1;
			int temp=n-j;
			sum=(sum+1ll*min(res,temp)*fac[temp-1]%mod*nows%mod)%mod; 
			nows=1ll*nows*(now[j]-j-1)%mod;
//			printf("i=%d j=%d\n",i,j);
//			printf("now[%d]=%d sum=%d res=%d temp=%d\n",j,now[j],sum,res,temp);
		} 
		ans=(ans+1ll*sum*inv[n]%mod)%mod;
	}
	printf("%d\n",ans);
}
int main()
{
	int T=1;
	while(T--)
	{
		init();
		input();
		solve();
	}
	return 0;
}