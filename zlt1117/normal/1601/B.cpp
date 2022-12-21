//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define sz(x) (int)(x.size())
#define pb push_back
#define PII pair<int,int>
#define ll long long
#define gc getchar()
//#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
using namespace std;
char buf[100000],*p1=buf,*p2=buf;
inline int gi()
{
	int x=0,f=1;char ch=gc;
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=gc;}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=gc;}
	return (f==1)?x:-x;
}
const int maxn=3e5+5,inf=0x3f3f3f3f;
set<pair<int,int>>S;
int dp[maxn],lst[maxn];
vector<int> del[maxn];
int n,a[maxn],b[maxn];
inline void init()
{
	
}
inline void input()
{
	n=gi();
	FOR(i,1,n)a[i]=gi();
	FOR(i,1,n)b[i]=gi();
}
inline void solve()
{
	memset(dp,0x3f,sizeof(dp));
	dp[n]=0;S.insert({dp[n],n});if(n!=a[n])del[n-a[n]-1].pb(n);
	for(int i=n-1;i>=0;--i)
	{
		for(auto x:del[i])S.erase({dp[x],x});
		if(S.empty())break;
		auto x=*S.begin();
		dp[i]=x.first+1;lst[i]=x.second;
		int now=i+b[i],nowv=now-a[now]-1;
		if(nowv>=0&&nowv<i)del[nowv].pb(i);
		if(nowv<i)S.insert({dp[i],i});
	}
	if(dp[0]==inf)puts("-1");
	else
	{
		vector<int>v;
		int x=0;
		while(x!=n)v.pb(x),x=lst[x];
		reverse(v.begin(),v.end());
		printf("%d\n",sz(v));
		for(int x:v)printf("%d ",x);
		puts("");
	}
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