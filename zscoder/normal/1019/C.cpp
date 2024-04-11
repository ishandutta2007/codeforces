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

int D[1001111];
vi adj[1001111];
vi radj[1000111];

int marked[1001111];
set<int> S;
void solve()
{
	if(S.empty()) return ;
	int u=(*S.begin());
	for(int v:adj[u])
	{
		marked[v]=2; S.erase(v);
	}
	S.erase(u);
	solve();
	bool pos=1;
	for(int v:radj[u])
	{
		if(marked[v]==1) pos=0;
	}
	marked[u]=pos;
}

int main()
{
	int n,m; scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int u,v; scanf("%d %d",&u,&v); u--; v--;
		adj[u].pb(v); radj[v].pb(u);
	}
	for(int i=0;i<n;i++) S.insert(i);
	solve();
	vi vec;
	for(int i=0;i<n;i++)
	{
		if(marked[i]==1) vec.pb(i);
	}
	printf("%d\n", int(vec.size()));
	for(int i=0;i<vec.size();i++)
	{
		printf("%d",vec[i]+1);
		if(i+1<vec.size()) printf(" ");
	}
	printf("\n");
}