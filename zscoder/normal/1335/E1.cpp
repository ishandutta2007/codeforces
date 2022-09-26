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
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int mx(vi &x)
{
	int ans=0;
	for(int v:x) ans=max(ans,v);
	return ans;
}
void solve()
{
	int n; cin>>n;
	vi a;
	for(int i=0;i<n;i++)
	{
		int x; cin>>x; a.pb(x);
	}
	int ans=0;
	vector<ii> runs;
	for(int i=0;i<n;i++)
	{
		vi c(30,0);
		vi p(30,0);
		vi s(30,0);
		for(int j=0;j<i;j++) p[a[j]]++;
		for(int j=i;j<n;j++) s[a[j]]++;
		for(int j=0;j<30;j++) c[j]=min(p[j],s[j]);
		vi cur(30,0);
		for(int j=i;j<n;j++)
		{
			cur[a[j]]++;
			s[a[j]]--;
			c[a[j]]=min(p[a[j]],s[a[j]]);
			ans=max(ans,mx(c)*2+mx(cur));
		}
	}
	cout<<ans<<'\n';
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t; while(t--) solve();
}