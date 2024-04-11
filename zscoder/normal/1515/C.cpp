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

ll a[111111];
ll s[111111];
int ans[222222];

void solve()
{
	int n,m; ll x; cin>>n>>m>>x;
	vector<ii> vec;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		vec.pb({a[i],i});
		s[i]=0;
	}
	set<ii> S;
	for(int i=0;i<m;i++) S.insert({0,i});
	sort(vec.rbegin(),vec.rend());
	for(auto X:vec)
	{
		ll val=X.fi; int id=X.se;
		auto tmp = (*S.begin());
		ans[id]=tmp.se;
		S.erase(tmp);
		s[tmp.se]+=val;
		S.insert({s[tmp.se],tmp.se});
	}
	cout<<"YES\n";
	for(int i=0;i<n;i++)
	{
		cout<<ans[i]+1;
		if(i+1<n) cout<<' ';
	}
	cout<<'\n';
}
	
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
}