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

void solve()
{
	int a[3]; cin>>a[0]>>a[1]>>a[2];
	vector<int> runs;
	for(int i=0;i<a[1]+1;i++) runs.pb(1);
	int n=a[0]+a[1]+a[2]+1;
	if(a[1]==0)
	{
		if(a[0]>a[2])
		{
			for(int i=0;i<a[0]+1;i++) cout<<0;
		}
		else
		{
			for(int i=0;i<a[2]+1;i++) cout<<1;
		}
		cout<<'\n';
	}
	else
	{
		runs[0]+=a[0];
		runs[1]+=a[2];
		for(int i=0;i<runs.size();i++)
		{
			for(int j=0;j<runs[i];j++)
			{
				cout<<(i&1);
			}
		}
		cout<<'\n';
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
}