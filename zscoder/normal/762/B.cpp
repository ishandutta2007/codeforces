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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

vector<ll> x;
vector<ll> y;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int a,b,c; cin>>a>>b>>c;
	int n; cin>>n;
	for(int i = 0; i <n; i++)
	{
		ll z; cin>>z;
		string s; cin>>s;
		if(s[0]=='U')
		{
			x.pb(z);
		}
		else
		{
			y.pb(z);
		}
	}
	sort(x.begin(),x.end());
	sort(y.begin(),y.end());
	int cnt = 0;
	ll cost = 0;
	vector<ii> vec;
	for(int i = 0; i < x.size(); i++) vec.pb(mp(x[i],0));
	for(int i = 0; i < y.size(); i++) vec.pb(mp(y[i],1));
	sort(vec.begin(),vec.end());
	for(int i = 0; i < n; i++)
	{
		int t = vec[i].se;
		ll val  =vec[i].fi;
		if(t==0&&a>0)
		{
			a--;
			cnt++;
			cost+=val;
		}
		else if(t==1&&b>0)
		{
			b--;
			cnt++;
			cost+=val;
		}
		else if(t==0&&c>0)
		{
			c--;
			cnt++;
			cost+=val;
		}
		else if(t==1&&c>0)
		{
			c--;
			cnt++;
			cost+=val;
		}
	}
	cout<<cnt<<' '<<cost;
}