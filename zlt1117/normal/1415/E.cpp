#pragma GCC optimize(4)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define rd (rand()<<16^rand())
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
const int maxn=5e5+5;
int n,a[maxn],k;
ll ans,now;
priority_queue<ll>pq; 
inline void init()
{

}
inline void input()
{
	n=gi();k=gi();
	FOR(i,1,n)a[i]=gi();
	sort(a+1,a+n+1,greater<int>());
}
inline void solve()
{
	///every time we add an element to one set (there is at most k+1 sets),and the next element the value of it is the sum of the set
	///we must choose the bigger ones first
	FOR(i,1,k+1)pq.push(0);///(k+1)sets(set maybe empty)
	FOR(i,1,n)
	{
		ll x=pq.top();
		pq.pop();
		ans+=x;
		pq.push(x+a[i]);
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