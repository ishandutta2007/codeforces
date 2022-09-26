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

ll dist(ii a, ii b)
{
	return (a.fi-b.fi)*(a.fi-b.fi)+(a.se-b.se)*(a.se-b.se);
}

bool used[5555];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	vector<ii> vec;
	vi ans;
	for(int i=0;i<n;i++)
	{
		int x,y; cin>>x>>y;
		vec.pb({x,y});
	}
	ans.pb(0); used[0]=1;
	while(ans.size()<n)
	{
		int cur=ans.back();
		int best = -1;
		ll lul = -ll(6e18);
		for(int i=0;i<n;i++)
		{
			if(used[i]) continue;
			if(i==cur) continue;
			ll d = dist(vec[i],vec[cur]);
			if(d>lul)
			{
				lul=d; best=i;
			}
		}
		ans.pb(best); used[best]=1;
	}
	for(int v:ans)
	{
		cout<<v+1<<' ';
	}
	cout<<'\n';
}