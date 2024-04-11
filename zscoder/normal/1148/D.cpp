#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ll> vi;
typedef unsigned long long ull;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

vector<int> best;

bool cmp(const pair<ii,int> &a, const pair<ii,int> &b)
{
	if(a.fi.se!=b.fi.se) return a.fi.se<b.fi.se;
	return a.fi.fi<b.fi.fi;
}

void solve(vector<pair<ii,int> > V)
{
	sort(V.rbegin(),V.rend(),cmp);
	vector<int> vnew;
	int cur=int(1e9);
	for(int i=0;i<V.size();i++)
	{
		if(cur<=V[i].fi.fi) continue;
		cur=V[i].fi.se; vnew.pb(V[i].se);
	}
	if(vnew.size()>best.size()) best=vnew;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); 
	int n; cin>>n;
	vector<pair<ii,int> > up,down;
	for(int i=0;i<n;i++)
	{
		int x,y; cin>>x>>y;
		if(x<y) up.pb({{x,y},i+1});
		else down.pb({{-x,-y},i+1});
	}
	solve(up); solve(down);
	cout<<best.size()<<'\n';
	for(int i=0;i<best.size();i++)
	{
		cout<<best[i];
		if(i+1<best.size()) cout<<' ';
	}
	cout<<'\n';
}