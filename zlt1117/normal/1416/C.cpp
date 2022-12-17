#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define ll long long
#define ull unsigned long long
#define PII pair<int,int>
#define rd (rand()<<16^rand())
#define pb push_back
using namespace std;
inline int gi()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return (f==1)?x:-x;
}
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
const int maxn=3e5+5;
int n,a[maxn],x;
ll ans;
ll cnt[32][2];///cnt0/1 
vector<int>v;
inline void solve(int step,vector<int>vec)
{
	if(step==-1||vec.size()==0)return ;
	/// 
	vector<int>ls,rs;
	ll l0=0,r0=0;
	for(auto x:vec)
	{
		if((x>>step)&1)rs.push_back(x),r0++,cnt[step][1]+=l0;
		else ls.push_back(x),l0++,cnt[step][0]+=r0;
	} 
	solve(step-1,ls);solve(step-1,rs);
}
int main()
{
	n=gi();
	FOR(i,1,n)a[i]=gi();
	FOR(i,1,n)v.pb(a[i]);
	solve(30,v);
	/// 
	FOR(i,0,30)
	{
		if(cnt[i][0]<=cnt[i][1])ans+=cnt[i][0];
		else ans+=cnt[i][1],x^=1<<i;
	}
	printf("%lld %d\n",ans,x);
	return 0;
}
///