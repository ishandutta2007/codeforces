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
typedef vector<ll> vi;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

vi s[300001];
vi adj[300001];
int ans[500001];
bool used[500001];

void dfs(int u, int p)
{
	vi vec;
	for(int i=0;i<s[u].size();i++)
	{
		int v=s[u][i];
		if(ans[v]>0)
		{
			vec.pb(v);
			used[ans[v]]=1;
		}
	}
	int cnt=1;
	for(int i=0;i<s[u].size();i++)
	{
		int v=s[u][i];
		if(ans[v]>0) continue;
		while(used[cnt]) cnt++;
		ans[v]=cnt;
		cnt++;
	}
	for(int i=0;i<vec.size();i++)
	{
		used[ans[vec[i]]]=0;
	}
	for(int i=0;i<adj[u].size();i++)
	{
		int v=adj[u][i];
		if(v==p) continue;
		dfs(v,u);
	}
}

int main()
{
	//ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m; scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		int x; scanf("%d",&x);
		for(int j=0;j<x;j++)
		{
			int c; scanf("%d",&c);
			c--;
			s[i].pb(c);
		}
	}
	for(int i=0;i<n-1;i++)
	{
		int u,v;
		scanf("%d %d",&u,&v);
		u--; v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(0,-1);
	int mx=0;
	for(int i=0;i<m;i++)
	{
		if(ans[i]==0) ans[i]=1;
		mx=max(mx,ans[i]);
	}
	printf("%d\n",mx);
	for(int i=0;i<m;i++)
	{
		printf("%d",ans[i]);
		if(i<m-1) printf(" ");
	}
	printf("\n");
}