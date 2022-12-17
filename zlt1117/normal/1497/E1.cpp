#pragma GCC optimize("Ofast")
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
#define gc (_p1==_p2&&(_p2=(_p1=_buf)+fread(_buf,1,100000,stdin),_p1==_p2)?EOF:*_p1++)
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
const int maxn=2e5+5,inf=0x3f3f3f3f;
int n,k;
map<int,int>mp;
int a[maxn],pre[maxn],now1[maxn],cnt[maxn];
vector<int>p;
int tot;
bool vis[maxn];
int dp[maxn][21];
inline void init()
{
	mp.clear();
	FOR(i,0,n)a[i]=pre[i]=now1[i]=0;
	FOR(i,0,n)FOR(j,0,k)dp[i][j]=inf;
	tot=0;
}
inline void input()
{
	n=gi(),k=gi();
	FOR(i,1,n)a[i]=gi();
	FOR(i,1,n)
	{
		int now=a[i],temp=1;
		for(auto x:p)
		{
			if(1ll*x*x>now)break;
			int cnt=0;
			while(now%x==0)now/=x,cnt++;
			if(cnt&1)temp*=x;
		}
		temp*=now;
		if(!mp.count(temp))mp[temp]=++tot;
		a[i]=mp[temp];
		pre[i]=now1[a[i]];
		now1[a[i]]=i;
	}
}
inline void solve()
{
	FOR(i,0,k)dp[0][i]=0;
	FOR(j,0,k)
	{
		for(int nowc=j;nowc>=0;--nowc)
		{
			///dp[j-nowc]
			int counter=0,now=0;
			FOR(i,0,tot)cnt[i]=0;
			FOR(i,1,n)
			{
				cnt[a[i]]++;
				if(cnt[a[i]]>=2)counter++;
				while(counter>nowc)
				{
					if(cnt[a[now+1]]>=2)counter--;
					cnt[a[now+1]]--;now++;
				}
				dp[i][j]=min(dp[now][j-nowc]+1,dp[i][j]);
			}
		}
	}
	printf("%d\n",dp[n][k]);
}
int main()
{
	memset(dp,0x3f,sizeof(dp));
	FOR(i,2,4000)
	{
		if(!vis[i])p.pb(i);
		for(auto x:p)
		{
			if(1ll*i*x>4000)break;
			if(i%x==0)
			{
				vis[i*x]=1;
				break;
			}
			else vis[i*x]=1;
		}
	}
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