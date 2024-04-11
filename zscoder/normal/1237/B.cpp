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
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef unsigned long long ull;
typedef double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int a[333333];
int b[333333];
int ma[333333];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]; a[i]--;
		ma[a[i]]=i;
	}
	for(int i=0;i<n;i++)
	{
		cin>>b[i]; b[i]--;
		b[i]=ma[b[i]];
	}
	int ans=0;
	int mn=int(1e9);
	for(int i=n-1;i>=0;i--)
	{
		if(mn<b[i])
		{
			ans++;
		}
		mn=min(mn,b[i]);
	}
	cout<<ans<<'\n';
	
}