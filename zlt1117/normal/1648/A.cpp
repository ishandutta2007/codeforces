#pragma GCC optimize("Ofast")
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
ll ans;
int n,m;
vector<int>c[maxn];
vector<int>a[maxn],b[maxn];
inline void input()
{
	n=gi(),m=gi();
	FOR(i,1,n)
	{
		c[i].resize(m+1);
		FOR(j,1,m)c[i][j]=gi(),a[c[i][j]].pb(i),b[c[i][j]].pb(j);
	}
}
inline void solve()
{
	int M=1e5;
	FOR(i,1,M)
	{
		ll cnt=0,sum=0;
		sort(a[i].begin(),a[i].end());
		sort(b[i].begin(),b[i].end());
		for(int x:a[i])
		{
			ans+=x*cnt-sum;
			sum+=x,cnt++;
		}
		cnt=0,sum=0;
		for(int x:b[i])
		{
			ans+=x*cnt-sum;
			sum+=x,cnt++;
		}
	}
	printf("%lld\n",ans);
}
int main()
{
	input();
	solve();
	return 0;
}