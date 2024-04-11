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
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;

int a[111111];

void solve()
{
	int n; cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i+1<n;i++)
	{
		//[0,i] and [i+1,n-1]
		if(a[i]==0&&a[i+1]==1)
		{
			for(int j=0;j<=i;j++)
			{
				cout<<j+1<<' ';
			}
			cout<<n+1<<' ';
			for(int j=i+1;j<n;j++)
			{
				cout<<j+1<<' ';
			}
			cout<<'\n'; return ;
		}
	}
	if(a[0]==1) //can go to end
	{
		cout<<n+1<<' ';
		for(int i=1;i<=n;i++)
		{
			cout<<i<<' ';
		}
		cout<<'\n';
		return ;
	}
	if(a[n-1]==0) //can go to end
	{
		for(int i=1;i<=n+1;i++)
		{
			cout<<i<<' ';
		}
		cout<<'\n';
		return ;
	}
	cout<<-1<<'\n';
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
}