//#pragma GCC optimize(4)
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
const int maxn=2e6+5;
int x,y,a[maxn],n;
ll ans=1e18;
bool vis[maxn];
vector<int>prime;
inline void init()
{
	vis[0]=vis[1]=1;
	FOR(i,2,(int)(1e6))
	{
		if(!vis[i])prime.pb(i);
		for(auto x:prime)
		{
			if(1ll*i*x>(int)(1e6))break;
			if(i%x)vis[i*x]=1;
			else
			{
				vis[i*x]=1;
				break;
			}
		}
	}
}
int cnt[maxn];
ll sum[maxn];
inline void input()
{
	n=gi(),x=gi(),y=gi();
	FOR(i,1,n)
	{
		a[i]=gi();
		sum[a[i]]+=a[i];
		cnt[a[i]]++;
	}
	FOR(i,1,maxn-1)cnt[i]=cnt[i-1]+cnt[i],sum[i]+=sum[i-1];
}
inline void solve()
{
	bool ok=1;
	int maxv=0;FOR(i,1,n)maxv=max(maxv,a[i]);
	FOR(i,1,n)if(a[i]!=1){ok=0;break;}
	if(ok)return printf("%lld\n",1ll*min(x,y)*n),void();
	FOR(i,2,maxv)///gcd
	{
		ll sum1=0;
		for(int j=1;j<=maxv;j+=i)
		{
			double temp=1.0*x/y;
			int ed=j+i-1-(int)(ceil(temp)+0.5);
			if(ed>=j)sum1+=1ll*x*(cnt[ed]-cnt[j-1]);
			else ed=j-1;
			sum1+=1ll*y*(1ll*(i+j-1)*(cnt[i+j-1]-cnt[ed])-(sum[i+j-1]-sum[ed]));
		}
		ans=min(ans,sum1);
	}
	printf("%lld\n",ans);
}	
int main()
{
	//freopen("1.in","r",stdin);
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