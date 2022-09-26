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
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

int dp[(1<<22)+1];
ii par[(1<<22)+1];
int adj[23];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m; cin>>n>>m;
	
	for(int i=0;i<m;i++)
	{
		int u,v; cin>>u>>v; u--; v--;
		adj[u]|=(1<<v); adj[v]|=(1<<u);
	}
	
	if(m==(n*(n-1))/2)
	{
		cout<<0<<'\n';
		return 0;
	}
	vi vec;
	int ans = 3000;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<(1<<n);j++)
		{
			if((j&(1<<i))) continue;
			if((j&adj[i])==adj[i])
			{
				dp[j]=int(1e9);
			}
		}
		dp[adj[i]]=1;
		par[adj[i]]=mp(i,-1);
		queue<int> q; q.push(adj[i]);
		while(!q.empty())
		{
			int j = q.front(); q.pop();
			for(int k=0;k<n;k++)
			{
				if(j&(1<<k))
				{
					int newbit = (adj[k]|j);
					if(newbit&(1<<i)) newbit^=(1<<i);
					if(dp[newbit]>=int(1e9))
					{
						dp[newbit]=dp[j]+1;
						par[newbit]=mp(k,j);
						q.push(newbit);
					}
				}
			}
		}
		int allbit=(1<<n)-1;
		allbit^=(1<<i);
		int res = dp[allbit];
		//cerr<<i<<' '<<res<<'\n';
		if(res<ans)
		{
			vec.clear();
			int cur=allbit;
			while(cur!=-1)
			{
				vec.pb(par[cur].fi);
				cur=par[cur].se;
			}
			vec.pop_back();
			reverse(vec.begin(),vec.end());
			vec.pb(i);
			ans=res;
		}
	}
	cout<<ans<<'\n';
	for(int i=0;i<vec.size();i++)
	{
		cout<<vec[i]+1;
		if(i+1<vec.size()) cout<<' ';
	}
	cout<<'\n';
}