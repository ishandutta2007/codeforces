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

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m; cin>>n>>m;
	vector<ii> v[2];
	for(int i=0;i<n;i++)
	{
		int x,y; cin>>x>>y;
		v[0].pb(mp(min(x,y),max(x,y)));
	}
	for(int i=0;i<m;i++)
	{
		int x,y; cin>>x>>y;
		v[1].pb(mp(min(x,y),max(x,y)));
	}
	vi ans;
	for(int i=0;i<n;i++)
	{
		int x = v[0][i].fi; int y = v[0][i].se;
		int bit = 0;
		for(int j=0;j<m;j++)
		{
			if(v[1][j]==v[0][i]) continue;
			if(v[1][j].fi==x||v[1][j].se==x)
			{
				bit|=1;
			}
			if(v[1][j].fi==y||v[1][j].se==y)
			{
				bit|=2;
			}
		}
		if(bit==3)
		{
			cout<<-1<<'\n'; return 0;
		}
	}
	swap(n,m); swap(v[0],v[1]);
	for(int i=0;i<n;i++)
	{
		int x = v[0][i].fi; int y = v[0][i].se;
		int bit = 0;
		for(int j=0;j<m;j++)
		{
			if(v[1][j]==v[0][i]) continue;
			if(v[1][j].fi==x||v[1][j].se==x)
			{
				bit|=1;
			}
			if(v[1][j].fi==y||v[1][j].se==y)
			{
				bit|=2;
			}
		}
		if(bit==3)
		{
			cout<<-1<<'\n'; return 0;
		}
	}
	swap(n,m); swap(v[0],v[1]);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(v[0][i]==v[1][j]) continue;
			if(v[0][i].fi==v[1][j].fi)
			{
				ans.pb(v[0][i].fi); continue;
			}
			if(v[0][i].fi==v[1][j].se)
			{
				ans.pb(v[0][i].fi); continue;
			}
			if(v[0][i].se==v[1][j].fi)
			{
				ans.pb(v[0][i].se); continue;
			}
			if(v[0][i].se==v[1][j].se)
			{
				ans.pb(v[0][i].se); continue;
			}
		}
	}
	sort(ans.begin(),ans.end()); ans.erase(unique(ans.begin(),ans.end()),ans.end());
	if(ans.size()==1)
	{
		cout<<ans[0]<<'\n';
	}
	else
	{
		cout<<0<<'\n';
	}
}