//#pragma GCC optimize(4)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define PII pair<int,int>
#define ll long long
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
const int maxn=1e5;
int T;
ll p,q;
bool prime[maxn+5];
inline void init()
{

}
inline void input()
{
	scanf("%lld%lld",&p,&q);
}
inline ll qpow(ll x,ll k)
{
	ll ret=1;
	while(k)
	{
		if(k&1)ret*=x;
		k>>=1,x=(x*x);
	}
	return ret;
}
inline void solve()
{
	if(p<q){printf("%lld\n",p);return ;}
	if(p%q!=0){printf("%lld\n",p);return ;}
	ll now=q;
	vector<int>vec;
	for(ll i=2;i*i<=q;++i)
	{
		if(prime[i])continue;
		while(now%i==0)now/=i;
		if(q%i==0)vec.push_back(i);
	}
	if(now!=1){vec.push_back(now);}
	ll ans=1e18;now=p;
	for(auto x:vec)
	{
		int cnt1=0,cnt2=0;
		while(p%x==0)
		{
			p/=x;
			cnt1++;
		}
		while(q%x==0)
		{
			q/=x;
			cnt2++;
		}
		ans=min(ans,qpow(x,cnt1-cnt2+1));
	}
	printf("%lld\n",now/ans);
}
int main()
{
	FOR(i,2,maxn)
	{
		if(!prime[i])
		{
			for(ll x=i+i;x<=maxn;x+=i)prime[x]=true;
		}
	}
	T=gi();
	while(T--)
	{
		init();
		input();
		solve();
	}
	return 0;
}///