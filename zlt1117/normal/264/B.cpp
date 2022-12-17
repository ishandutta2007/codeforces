//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define sz(x) (int)(x.size())
#define rd (rand()<<16^rand())
#define db double
#define gc getchar()
#define mk make_pair
#define iter set<int>::iterator
//#define gc (_p1==_p2&&(_p2=(_p1=_buf)+fread(_buf,1,100000,stdin),_p1==_p2)?EOF:*_p1++)
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
const int maxn=1e5+5;
int dp[maxn],n,a[maxn],M;
vector<int>factors[maxn];
inline void init()
{
	
}
inline void input()
{
	n=gi();
	FOR(i,1,n)a[i]=gi(),M=max(M,a[i]);
	FOR(i,2,M)
	{
		for(int j=i;j<=M;j+=i)
		{
			factors[j].pb(i);
		}
	}
}
inline void solve()
{
	if(n==1)return puts("1"),void();
	FOR(i,1,n)
	{
		int maxv=0;
		for(int x:factors[a[i]])maxv=max(maxv,dp[x]);
		maxv++;
		for(int x:factors[a[i]])dp[x]=max(dp[x],maxv);
	}
	printf("%d\n",*max_element(dp+1,dp+M+1));
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