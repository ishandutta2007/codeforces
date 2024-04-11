#include <cstdio>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
#define ll long long
#define x first
#define y second
#define pb push_back
using std::cin;
using std::cout;
using std::pair;
using std::map;
using std::set;
using std::vector;
const int N=1000005;

int typ, n, lfa[N], lfb[N], lf[N];
ll sa[N], sb[N];
map<ll, int> mp;
int q[N][2], cnta[N], cntb[N], rans[N];
ll ans;
vector<int> qr[N];
int mx;
set<pair<int, int> > st, st1;
inline void insa(int l, int r)
{
	int cy=r+1;
	while(!st1.empty()&&st1.begin()->x<l)
	{
		cy=st1.begin()->y;
		st1.erase(st1.begin());
	}
	if(cy<=r&&(st.empty()||prev(st.end())->y>cy)) st.insert({r, cy});
	cy=r+1;
	while(!st.empty()&&st.begin()->x<l)
	{
		cy=st.begin()->y;
		st.erase(st.begin());
	}
	if(cy<=r)
	{
		st1.clear();
		st1.insert({r, cy});
		st1.swap(st);
		++mx;
	}
}
inline void insb(int l, int r)
{
	int cx=r+1;
	while(!st1.empty()&&st1.rbegin()->y<l)
	{
		cx=st1.rbegin()->x;
		st1.erase(prev(st1.end()));
	}
	if(cx<=r&&(st.empty()||st.begin()->x>cx)) st.insert({cx, r});
	cx=r+1;
	while(!st.empty()&&st.rbegin()->y<l)
	{
		cx=st.rbegin()->x;
		st.erase(prev(st.end()));
	}
	if(cx<=r)
	{
		st1.clear();
		st1.insert({cx, r});
		st1.swap(st);
		++mx;
	}
}
inline void insab(int l, int r)
{
	auto it=st.lower_bound({l, 0});
	if(it!=st.begin()&&prev(it)->y<l)
	{
		++mx;
		st1.clear();
		st1.insert({r, r});
		st1.swap(st);
	}
}
int main()
{
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	mp[0]=0;
	for(int i=1; i<=n; ++i)
	{
		cin>>sa[i];
		sa[i]+=sa[i-1];
		int v=mp.count(sa[i])?mp[sa[i]]+1:0;
		lfa[i]=v;
		mp[sa[i]]=i;
	}
	mp.clear();
	mp[0]=0;
	for(int i=1; i<=n; ++i)
	{
		cin>>sb[i];
		sb[i]+=sb[i-1];
		int v=mp.count(sb[i])?mp[sb[i]]+1:0;
		lfb[i]=v;
		mp[sb[i]]=i;
	}
	mp.clear();
	mp[0]=0;
	for(int i=1; i<=n; ++i)
	{
		sa[i]+=sb[i];
		int v=mp.count(sa[i])?mp[sa[i]]+1:0;
		lf[i]=v;
		mp[sa[i]]=i;
	}
	for(int i=1; i<=n; ++i)
	{
		lfa[i]=std::max(lfa[i-1], lfa[i]);
		lfb[i]=std::max(lfb[i-1], lfb[i]);
		lf[i]=std::max(lf[i-1], lf[i]);
	}
	int lim=std::__lg(n);
	st.insert({0, 0});
	for(int i=1; i<=n; ++i)
	{
		if(lfa[i]) insa(lfa[i], i);
		if(lfb[i]) insb(lfb[i], i);
		if(lf[i]) insab(lf[i], i);
	}
	printf("%d\n", mx);
	return 0;
}