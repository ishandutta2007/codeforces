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
	int n; cin>>n;
	vi a(n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		a[i]--;
	}
	if(a[0]<a[n-1]){cout<<"YES\n";}
	else{cout<<"NO\n";}
	return ;
	int curmn = -1;
	int runmn = a[0];
	for(int i=0;i<n;i++)
	{
		if(i+1<n&&a[i]>a[i+1])
		{
			if(runmn>=int(1e8)){cout<<"NO\n"; return ;}
			if(curmn==-1) curmn=runmn;
			runmn=int(1e9);
			if(a[i+1]>curmn)
			{
				runmn=a[i+1];
			}
		}
		else
		{
			if(a[i]>curmn)
			{
				runmn=min(runmn,a[i]);
			}
		}
	}
	//cerr<<curmn<<' '<<runmn<<'\n';
	if(runmn>=int(1e8)){cout<<"NO\n"; return ;}
	assert(runmn>=curmn);
	cout<<"YES\n";
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
}