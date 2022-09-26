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

int a[222222];
int ans[222222];
vector<ii> qpos[222222];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	vector<ii> vec;
	for(int i=0;i<n;i++) 
	{
		int x; cin>>x; vec.pb({x,-i}); a[i]=x;
	}
	sort(vec.rbegin(),vec.rend());
	int q; cin>>q;
	for(int i=0;i<q;i++)
	{
		int u,v;cin>>u>>v; v--;
		qpos[u].pb({v,i});
	}
	pbds T;
	for(int i=0;i<n;i++)
	{
		T.insert(-vec[i].se);
		for(ii x:qpos[i+1])
		{
			int pos=x.fi; int lab=x.se;
			ans[lab] = a[(*T.find_by_order(pos))];
		}
	}
	for(int i=0;i<q;i++)
	{
		cout<<ans[i]<<'\n';
	}
}