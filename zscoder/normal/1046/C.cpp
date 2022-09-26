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

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m; cin>>n>>m;
	vi a(n); vi b(n);
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++) cin>>b[i];
	m--;
	int l=1; int r=n-1;
	int sc = a[m]+b[0];
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		if(i==m) continue;
		//cerr<<i<<' '<<l<<' '<<r<<' '<<sc<<' '<<cnt<<' '<<a[i]+b[r]<<'\n';
		if(sc>=a[i]+b[r])
		{
			 r--;
		}
		else
		{
			l++;cnt++;
		}
	}
	cout<<cnt+1<<'\n';
}