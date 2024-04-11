#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define N
#define M
using namespace std;

ll a,b,n;
vector<ll>ah,bh;

inline bool judge(ll u)
{
	ll i,j,ta=a,tb=b;
	for(i=u; i>=1&&ta>=i; i--)
	{
		ta-=i;
	}
	for(; i>=1; i--)
	{
		if(i==ta) continue;
		tb-=i;
	}
	return tb>=0;
}

inline void get(ll u)
{
	ll i,j,ta=a,tb=b;
	for(i=u; i>=1&&ta>=i; i--)
	{
		ah.push_back(i);
		ta-=i;
	}
	if(ta&&ta<i) ah.push_back(ta);
	for(; i>=1; i--)
	{
		if(i==ta) continue;
		bh.push_back(i);
	}
	return;
}

int main()
{
	ll i,j,l,r,mid;
	cin>>a>>b;
	for(l=1,r=100000; l<r;)
	{
		mid=((l+r)>>1);
		if(judge(mid)) l=mid+1;
		else r=mid;
	}
	get(l-1);
	cout<<ah.size()<<endl;
	for(i=0; i<ah.size(); i++)
	{
		printf("%lld ",ah[i]);
	}
	cout<<endl<<bh.size()<<endl;
	for(i=0; i<bh.size(); i++)
	{
		printf("%lld ",bh[i]);
	}
}