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

int ans[111];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	vector<ii> vec;
	int n,w; cin>>n>>w;
	for(int i=0;i<n;i++)
	{
		int x; cin>>x;
		vec.pb({x,i});
	}
	sort(vec.begin(),vec.end());
	for(int i=0;i<n;i++)
	{
		ans[vec[i].se]+=(vec[i].fi+1)/2;
		w-=ans[vec[i].se];
	}
	if(w<0){cout<<-1<<'\n'; return 0;}
	int ptr=n-1;
	while(w>0)
	{
		while(ans[vec[ptr].se]>=vec[ptr].fi) ptr--;
		ans[vec[ptr].se]++; w--;
	}
	for(int i=0;i<n;i++)
	{
		cout<<ans[i];
		if(i+1<n) cout<<' ';
	}
	cout<<'\n';
}