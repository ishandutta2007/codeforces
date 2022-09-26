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
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void inc(vector<ii> &vec, int pos, ll x)
{
	for(auto &g:vec)
	{
		if(g.se==pos) g.fi+=x;
	}
	sort(vec.begin(),vec.end());
	for(ii x:vec)
	{
		cerr<<x.fi<<' '<<x.se<<'\n';
	}
}

int main()
{
	vector<ii> vec;
	for(int i=0;i<3;i++)
	{
		ll x; cin>>x;
		vec.pb({x,i});
	}
	sort(vec.begin(),vec.end());
	cout<<"First\n";
	fflush(stdout);
	const ll INF1 = 6e9;
	cout<<INF1<<'\n';
	fflush(stdout);
	int x; cin>>x;
	x--;
	if(x<0) return 0;
	inc(vec,x,INF1);
	ll d = vec[2].fi - vec[0].fi + 1;
	cout<<d<<'\n';
	fflush(stdout);
	cin>>x;
	x--;
	if(x<0) return 0;
	inc(vec,x,d);
	/*
	while(vec[1].fi-vec[0].fi!=vec[2].fi-vec[1].fi)
	{
		assert(vec[1].fi-vec[0].fi>vec[2].fi-vec[1].fi);
		ll dist = (vec[1].fi-vec[0].fi)-(vec[2].fi-vec[1].fi);
		cout<<dist<<'\n';
		fflush(stdout);
		
	}
	*/
	ll d1 = vec[1].fi-vec[0].fi;
	ll d2 = vec[2].fi-vec[1].fi;
	cout<<d1+2*d2<<'\n';
	ll newd = d1+2*d2;
	cin>>x;
	x--;
	if(x<0) return 0;
	inc(vec,x,newd);
	assert(vec[1].fi-vec[0].fi==vec[2].fi-vec[1].fi);
	cout<<vec[1].fi-vec[0].fi<<'\n';
	fflush(stdout);
	cin>>x;
	assert(x==0);
}