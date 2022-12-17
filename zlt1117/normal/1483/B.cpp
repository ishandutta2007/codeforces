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
const int maxn=1e5+5;
set<int>s;
int a[maxn],n;
queue<int>q;
bool vis[maxn];
inline void init()
{
	FOR(i,1,n)vis[i]=0;
	s.clear();
	while(!q.empty())q.pop();
}
inline void input()
{
	n=gi();
	FOR(i,1,n)a[i]=gi();
}
inline void solve()
{
	vector<int>answers;
	FOR(i,1,n)q.push(i),s.insert(i);
	while(!q.empty()&&!s.empty())
	{
		int x=q.front();q.pop();
		int cnt=0;
		if(!s.count(x))continue;
		auto it=s.upper_bound(x);
		if(it==s.end())it=s.begin();
		int y=*it;
		if(__gcd(a[x],a[y])==1)
		{
			s.erase(y);
			answers.pb(y);
			cnt++;
			q.push(x);
		}
	}
	printf("%d ",sz(answers));
	for(auto x:answers)printf("%d ",x);
	printf("\n");
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