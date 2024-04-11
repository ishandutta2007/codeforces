#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key
 
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef pair<ld,ld> state;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

set<int> bad;
set<int> pos;
int a[111111];

int getnxt(int x)
{
	if(pos.empty()) return -1;
	auto it = pos.upper_bound(x);
	if(it==pos.end())
	{
		return (*pos.begin());
	}
	return (*it);
}

int getpre(int x)
{
	if(pos.empty()) return -1;
	auto it = pos.lower_bound(x);
	if(it==pos.begin())
	{
		return (*prev(pos.end()));
	}
	it--;
	return (*it);
}

void upd(int x)
{
	bad.erase(x);
	//check if x is bad
	int l = getpre(x);
	//cerr<<"L = "<<l<<'\n';
	if(__gcd(a[x],a[l])==1) 
	{
		bad.insert(x);
	}
}

int getnxtbad(int x)
{
	if(bad.empty()) return -1;
	auto it = bad.upper_bound(x);
	if(it==bad.end()) return (*bad.begin());
	return (*it);
}

void solve()
{
	bad.clear(); pos.clear();
	int n; cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++)
	{
		pos.insert(i);
	}
	for(int i=0;i<n;i++)
	{
		upd(i);
	}
	int cur=0;
	vi ans;
	while(!bad.empty())
	{
		int u = getnxtbad(cur);
		if(u==-1) break;
		ans.pb(u);
		int nt = getnxt(u);
		//cerr<<"U NT = "<<u<<' '<<nt<<'\n';
		bad.erase(u); pos.erase(u);
		if(nt!=-1&&nt!=u) upd(nt);
		cur=nt;
	}
	cout<<ans.size()<<' ';
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i]+1;
		if(i+1<ans.size()) cout<<' ';
	}
	cout<<'\n';
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
}