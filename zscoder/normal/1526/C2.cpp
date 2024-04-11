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

void solve()
{
	int n; cin>>n;
	int ans=0;
	ll sum=0;
	priority_queue<int> pq;
	for(int i=0;i<n;i++)
	{
		ll x; cin>>x;
		if(x>=0)
		{
			ans++; sum+=x;
		}
		else
		{
			if(sum+x>=0)
			{
				sum+=x; ans++;
				pq.push(-x);
			}
			else
			{
				if((!pq.empty())&&sum+pq.top()+x>=0&&abs(x)<pq.top())
				{
					sum+=pq.top()+x;
					pq.pop(); pq.push(abs(x)); 
				}
				
			}
		}
	}
	cout<<ans<<'\n';
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t=1;
	while(t--) solve();
}