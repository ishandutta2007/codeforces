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
	int n,k; cin>>n>>k;
	set<int> S;
	for(int i=0;i<n;i++)
	{
		int x; cin>>x; S.insert(x);
	}
	int cur=1;
	while(S.size()<k)
	{
		S.insert(cur);
		cur++;
	}
	if(S.size()>k)
	{
		cout<<-1<<'\n';
	}
	else
	{
		cout<<n*int(S.size())<<'\n';
		vi v;
		for(int x:S) v.pb(x);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<v.size();j++)
			{
				cout<<v[j];
				if(i==n-1&&j==int(v.size())-1) break;
				cout<<' ';
			}
		}
		cout<<'\n';
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t; while(t--) solve();
}