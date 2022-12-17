#pragma GCC optimize(4)
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
const int maxn=2e5+5,inf=1e9;
int n[5];
ll a[5][maxn],x[maxn],y[maxn],b[maxn];
struct node
{
	ll id,val;
	inline bool operator < (const node &b)const
	{
		return val<b.val;
	}
}temp[maxn];
inline void init()
{

}
inline void input()
{
	FOR(i,1,4)n[i]=gi();
	FOR(i,1,4)FOR(j,1,n[i])a[i][j]=gi();
}
inline void solve()
{
	FOR(i,2,4)
	{
		vector<vector<int> >vec;vec.resize(n[i]+1);
		FOR(j,1,n[i-1])temp[j].val=a[i-1][j],temp[j].id=j;
		sort(temp+1,temp+n[i-1]+1);
		FOR(j,1,n[i-1])b[temp[j].id]=j;
		int m=gi();FOR(j,1,m)x[j]=gi(),y[j]=gi();
		FOR(j,1,m)x[j]=b[x[j]],vec[y[j]].pb(x[j]);
		FOR(j,1,n[i])
		{
			if(sz(vec[j])==n[i-1]){a[i][j]=inf;continue;}
			set<int>s;for(auto x:vec[j])s.insert(x);
			FOR(k,1,n[i-1])if(!s.count(k)){a[i][j]+=temp[k].val;break;}
		}
	}
	ll ans=1e9;
	FOR(j,1,n[4])ans=min(ans,a[4][j]);
	if(ans>=inf)printf("-1\n");
	else printf("%lld\n",ans);
}
int main()
{
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