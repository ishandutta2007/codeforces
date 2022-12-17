#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define sz(x) (int)(x.size())
#define PII pair<int,int>
#define ll long long
#define pb push_back
//#define gc ((p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2))?EOF:*p1++)
#define gc getchar()
#define iter set<int>::iterator
using namespace std;
char buf[100000],*p1=buf,*p2=buf;
inline int gi()
{
	int x=0,f=1;char ch=gc;
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=gc;}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48),ch=gc;}
	return (f==1)?x:-x;
}
const int maxn=2e5+5;
int n,a[maxn];
inline void input()
{
	n=gi();
	FOR(i,1,n)a[i]=gi();
}
priority_queue<int>pq;
inline void solve()
{
	ll ans=0;
	pq.push(a[1]);
	FOR(i,2,n)
	{
		a[i]-=i-1;
		if(a[i]>=pq.top())pq.push(a[i]);
		else
		{
			ans+=pq.top()-a[i];
			pq.pop(),pq.push(a[i]),pq.push(a[i]);
		}
		//printf("%d %lld\n",i,ans);
		//printf("%d\n",pq.top());
	}
	printf("%lld\n",ans);
}
int main()
{
	input();
	solve();
	return 0;
}