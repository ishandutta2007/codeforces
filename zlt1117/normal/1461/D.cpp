#pragma GCC optimize(4)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define PII pair<int,int>
#define ll long long
#define int ll
#define pb push_back
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
ll n,q,a[maxn],x;
set<ll>s;
inline void init()
{
	s.clear();
}
inline void input()
{
	n=gi(),q=gi();
	FOR(i,1,n)a[i]=gi();
}
inline void merge_sort(int l,int r)
{
	if(l>r)return ;
	if(l==r)return s.insert(a[l]),void();
	ll minv=1e9,maxv=-1;
	FOR(i,l,r)minv=min(minv,a[i]),maxv=max(maxv,a[i]);
	ll mid=(minv+maxv)>>1;
	if(minv==maxv)return ;
	vector<int>v1,v2;
	ll suml=0,sumr=0;
	FOR(i,l,r)
	{
		if(a[i]<=mid)v1.pb(a[i]);
		else v2.pb(a[i]);
	}
	int now=l-1;
	for(auto x:v1)a[++now]=x,suml+=x;
	int temp=now;
	for(auto x:v2)a[++now]=x,sumr+=x;
	s.insert(suml),s.insert(sumr);
	merge_sort(l,temp);
	merge_sort(temp+1,r);
}
inline void solve()
{
	ll sum=0;
	merge_sort(1,n);
	FOR(i,1,n)sum+=a[i];
	s.insert(sum);
	while(q--)
	{
		x=gi();
		if(s.count(x))printf("Yes\n");
		else printf("No\n");
	}
}
signed main()
{
	int T=gi();
	while(T--)
	{
		init();
		input();
		solve();
	}
	return 0;
}