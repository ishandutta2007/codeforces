#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define ll long long
#define N 200100
#define M 1001000
using namespace std;

ll n,m,num[N],s,l,r,cnt[M],ans,an[N];
struct Que
{
	ll l,r,id;
	bool operator < (const Que &u) const
	{
		return l/s<u.l/s || l/s==u.l/s&&r<u.r;
	}
}que[N];

inline void add(ll u)
{
	ans+=(2*cnt[u]+1)*u;
	cnt[u]++;
}

inline void del(ll u)
{
	cnt[u]--;
	ans-=(2*cnt[u]+1)*u;
}

int main()
{
//	freopen("2.txt","r",stdin);
	ll i,j;
	cin>>n>>m;
	s=sqrt(n);
	for(i=1;i<=n;i++)
		scanf("%lld",&num[i]);
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld",&que[i].l,&que[i].r);
		que[i].id=i;
	}
	sort(que+1,que+m+1);
	for(i=l=1,r=0;i<=m;i++)
	{
		for(;r<que[i].r;r++) add(num[r+1]);
		for(;l>que[i].l;l--) add(num[l-1]);
		for(;l<que[i].l;l++) del(num[l]);
		for(;r>que[i].r;r--) del(num[r]);
		an[que[i].id]=ans;
	}
	for(i=1;i<=m;i++) printf("%lld\n",an[i]);
}