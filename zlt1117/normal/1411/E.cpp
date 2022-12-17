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
int n;
ll T;
char s[maxn];
int pw[maxn];
int cnt[maxn];
inline void init()
{
	
}
inline void input()
{
	n=gi();scanf("%lld",&T);
	scanf("%s",s+1);
	pw[0]=1;
	FOR(i,1,25)pw[i]=pw[i-1]*2;
}
inline void NO()
{
	printf("No\n");
}
inline void YES()
{
	printf("Yes\n");
}
inline void solve()
{
	T=-T;
	T-=pw[s[n-1]-'a'];
	T+=pw[s[n]-'a'];
	FOR(i,1,n-2)T-=pw[s[i]-'a'];
	if(T>0)return NO();
	T=-T;
	if(T%2==1)return NO();
	T/=2;
	FOR(i,1,n-2)cnt[s[i]-'a']++;
	for(int i=25;i>=0;--i)
	{
		ll now=cnt[i];now*=pw[i];
		if(T-now>=0)T-=now;
		else T=T&((1<<i)-1);
	}
	if(T==0)YES();
	else NO();
}
int main()
{
	init();
	input();
	solve();
	return 0;
}///