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

int a[10001];
vi adj[10001];
set<int> s;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for(int i = 0; i < n; i++)
	{
		s.insert(i);
		cin>>a[i];
		a[i]--;
		adj[a[i]].pb(i);
	}
	int ans = 0;
	while(!s.empty())
	{
		int u = (*s.begin());
		int x1 = a[u];
		if(x1==u)
		{
			ans++;
			s.erase(u);
			continue;
		}
		int x2 = a[x1];
		if(x2==u)
		{
			ans++;
			s.erase(x1);
			s.erase(u);
			for(int j = 0; j < adj[u].size(); j++)
			{
				s.erase(adj[u][j]);
			}
			for(int j = 0; j < adj[x1].size(); j++)
			{
				s.erase(adj[x1][j]);
			}
			continue;
		}
		s.erase(x1);
		s.erase(x2);
		s.erase(u);
		for(int j = 0; j < adj[u].size(); j++)
		{
			s.erase(adj[u][j]);
		}
		for(int j = 0; j < adj[x1].size(); j++)
		{
			s.erase(adj[x1][j]);
		}
		for(int j = 0; j < adj[x2].size(); j++)
		{
			s.erase(adj[x2][j]);
		}
		ans++;
	}
	cout<<ans;
}