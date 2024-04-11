#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int cnt[111111];
vi adj[111111];

void dfs(int u)
{
	if(adj[u].empty()) cnt[u]=1;
	for(int v:adj[u])
	{
		dfs(v);
		cnt[u]+=cnt[v];
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for(int i=1;i<n;i++)
	{
		int x; cin>>x; x--; adj[x].pb(i);
	}
	dfs(0);
	sort(cnt,cnt+n);
	for(int i=0;i<n;i++)
	{
		cout<<cnt[i];
		if(i+1<n) cout<<' ';
	}
	cout<<'\n';
}