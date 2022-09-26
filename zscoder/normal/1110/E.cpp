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
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

ll a[111111];
ll b[111111];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	vi D1;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]; 
		if(i>0) D1.pb(a[i]-a[i-1]);
	}
	vi D2;
	for(int i=0;i<n;i++) 
	{
		cin>>b[i];
		if(i>0) D2.pb(b[i]-b[i-1]);
	}
	sort(D1.begin(),D1.end());
	sort(D2.begin(),D2.end());
	int pos=1;
	for(int i=0;i<D1.size();i++)
	{
		if(D1[i]!=D2[i]) pos=0;
	}
	if(a[0]!=b[0]) pos=0;
	if(a[n-1]!=b[n-1]) pos=0;
	if(pos) cout<<"Yes\n";
	else cout<<"No\n";
}