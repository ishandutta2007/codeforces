#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define sz(x) (int)(x.size())
#define gc getchar()
#define mk make_pair
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
const int maxn=1e5+5,inf=1e9;
int n,L,a[maxn];
inline bool check(int x,int y)
{
	int l=max(x,a[1]),r=min(y,a[2]);
	FOR(i,2,n)
	{
		if(l>r)return false;
		l=max(l+x,a[i]),r=min(a[i+1],r+y);
	}
	if(l>r||l>L||r<L)return false;
	return true;
}
inline void ways(int x,int y)
{
	int l=max(x,a[1]),r=min(y,a[2]);
	vector<pair<int,int>>limits={{l,r}};
	FOR(i,2,n)
	{
		l=max(l+x,a[i]),r=min(a[i+1],r+y);
		limits.pb({l,r});
	}
	vector<int>answer;int now=r;
	answer.pb(now);
	for(int i=sz(limits)-2;i>=0;--i)
	{
		int nowl=limits[i].first,nowr=limits[i].second;
		now=min(nowr,now-x);
		answer.pb(now);
	}
	reverse(answer.begin(),answer.end());
	int lst=0;
	for(int x:answer)printf("%d %d\n",lst,x),lst=x;
}
inline void input()
{
	L=gi(),n=gi();
	FOR(i,1,n)a[i]=gi();
	a[n+1]=L;a[n+2]=L;
}
inline void solve()
{
	int l=1,r=1e9,mind=1e9;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid,inf))mind=mid,l=mid+1;
		else r=mid-1;
	}
	l=mind,r=1e9;int maxd=1e9;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mind,mid))maxd=mid,r=mid-1;
		else l=mid+1;
	}
	ways(mind,maxd);
}
int main()
{
	input();
	solve();
	return 0;
}