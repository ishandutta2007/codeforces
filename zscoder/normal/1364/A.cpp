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
	int n; cin>>n; int m; cin>>m;
	vi a(n);
	int sum=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]; a[i]%=m;
		sum+=a[i];
	}
	if(sum%m!=0)
	{
		cout<<n<<'\n'; return ;
	}
	int l=0; int r=n-1;
	while(l<n&&a[l]==0) l++;
	while(r>=0&&a[r]==0) r--;
	if(r<0) cout<<-1<<'\n';
	else cout<<n-(1+min(l,n-1-r))<<'\n';
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
}