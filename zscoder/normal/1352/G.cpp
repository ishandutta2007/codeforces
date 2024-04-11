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

void solve()
{
	int n; cin>>n;
	if(n<=3)
	{
		cout<<-1<<'\n';
	}
	else
	{
		deque<int> dq = {3,1,4,2};
		for(int i=5;i<=n;i++)
		{
			if(i%2==1) dq.pb(i);
			else dq.push_front(i);
		}
		for(int x:dq)
		{
			cout<<x<<' ';
		}
		cout<<'\n';
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
}