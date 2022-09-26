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

bool check(vector<ll> &v, ll n)
{
	ll cur=1; ll siz=1;
	for(int i=0;i<v.size();i++)
	{
		assert(v[i]>=0);
		assert(v[i]<=siz);
		siz+=v[i];
		cur+=siz;
	}
	return (cur==n);
}

void solve()
{
	ll n; cin>>n;
	ll diff = n-1;
	if(diff==1)
	{
		cout<<1<<'\n'<<0<<'\n'; return ;
	}
	else if(diff==2)
	{
		cout<<1<<'\n'<<1<<'\n'; return ;
	}
	vector<ll> ans;
	ll curd = 1;
	while(diff>0)
	{
		//diff>2*curd ([curd,2*curd])
		//at least 2 moves are needed
		if(diff>6*curd)
		{
			diff-=2*curd;
			ans.pb(curd); //2*curd-curd
			curd*=2;
			continue;
		}
		//can settle here
		if(diff>=4*curd)
		{
			ans.pb(curd);
			diff-=2*curd;
			curd*=2;
			ans.pb(diff-curd);
			break;
		}
		int L = diff/2;
		int R = (diff+1)/2;
		ans.pb(L-curd);
		ans.pb(R-L);
		break;
	}	
	assert(check(ans,n));
	cout<<ans.size()<<'\n';
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i];
		if(i+1<ans.size()) cout<<' ';
	}
	cout<<'\n';
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
}