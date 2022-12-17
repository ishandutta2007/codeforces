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
const int maxn=1e5+5;
char s[maxn];
ll x,y,n;
ll pre[maxn],suf[maxn],pre2[maxn],suf2[maxn];
ll ans=1e18,sum;
inline void init()
{

}
inline void input()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	x=gi(),y=gi();
	FOR(i,1,n)pre[i]=pre[i-1]+(s[i]=='0');
	FOR(i,1,n)pre2[i]=pre2[i-1]+(s[i]=='1');
	for(int i=n;i>=1;--i)suf[i]=suf[i+1]+(s[i]=='0');
	for(int i=n;i>=1;--i)suf2[i]=suf2[i+1]+(s[i]=='1');
}
inline void solve()
{
	int tt=0;
	FOR(i,1,n)
	{
		if(s[i]!='0')
		{
			sum+=x*pre[i-1];
			sum+=y*suf[i+1];
		}
		if(s[i]=='?')tt++;
	}
	ll temp=sum;
	ans=sum;
	int cnt=0;
	FOR(i,1,n)
	{
		if(s[i]=='?')
		{
			sum-=(pre[i-1]+cnt)*x+suf[i+1]*y;
			cnt++;
			sum+=pre2[i-1]*y+(tt-cnt+suf2[i+1])*x;
		}
		ans=min(ans,sum);
	}
	cnt=0;
	sum=temp;
	for(int i=n;i>=1;--i)
	{
		if(s[i]=='?')
		{
			sum-=(pre[i-1])*x+(suf[i+1]+cnt)*y;
			cnt++;
			sum+=(tt-cnt+pre2[i-1])*y+(suf2[i+1])*x;
		}
		ans=min(ans,sum);
	}
	printf("%lld\n",ans);
}
int main()
{
	init();
	input();
	solve();
	return 0;
}///