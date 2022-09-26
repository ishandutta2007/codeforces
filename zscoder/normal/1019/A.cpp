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
typedef vector<ll> vi;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

vi vec[3441];
vi sum[3441];
int idx[3441];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m; cin>>n>>m;
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		ll x,y; cin>>x>>y;
		x--;
		if(x==0) cnt++;
		else vec[x].pb(y);
	}
	for(int i=1;i<m;i++) sort(vec[i].begin(),vec[i].end());
	for(int i=1;i<m;i++)
	{
		for(int j=0;j<vec[i].size();j++) 
		{
			sum[i].pb(vec[i][j]);
			if(j>0) sum[i][j]+=sum[i][j-1];
		}
	}
	ll ans=ll(1e18);
	for(int x=max(1,cnt);x<=n;x++)
	{
		//we need at least x voters
		ll s=0; int tot=cnt;
		for(int i=1;i<m;i++)
		{
			idx[i]=0;
			if(vec[i].size()>=x)
			{
				idx[i]=int(vec[i].size())-x+1;
				tot+=idx[i];
				s+=sum[i][idx[i]-1];
			}
			//cerr<<"ID : "<<i<<' '<<idx[i]<<'\n';
		}
		if(tot<x)
		{
			vector<int> V;
			for(int i=1;i<m;i++)
			{
				for(int j=idx[i];j<vec[i].size();j++) V.pb(vec[i][j]);
			}
			sort(V.begin(),V.end());
			for(int i=0;i<x-tot;i++) s+=V[i];
		}
		//cerr<<x<<' '<<ans<<'\n';
		ans=min(ans,s);
	}
	cout<<ans<<'\n';
}