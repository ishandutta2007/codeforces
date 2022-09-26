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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

ll a[100001];
int p[100001];
ll ans[100001];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; ll l, r;
	cin>>n>>l>>r;
	for(int i = 0; i < n; i++)
	{
		cin>>a[i];
	}
	vector<ii> vec;
	for(int i = 0; i < n; i++)
	{
		cin>>p[i];
		vec.pb(mp(p[i],i));
	}
	ll curdiff = -ll(1e15);
	sort(vec.begin(),vec.end());
	for(int i = 0; i < n; i++)
	{
		int u = vec[i].se;
		ll v = a[u];
		if(v+curdiff+1>r)
		{
			cout<<-1;
			return 0;
		}
		ans[u] = max(v+curdiff+1,l);
		curdiff = ans[u] - v;
	}
	for(int i = 0; i < n; i++)
	{
		cout<<ans[i]<<' ';
	}
}