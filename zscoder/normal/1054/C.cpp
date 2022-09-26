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
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int a[1111];
int b[1111];
vi vec[11111];
int ans[1111];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++) 
	{
		cin>>b[i]; vec[a[i]+b[i]].pb(i);
	}
	int cur=n;
	for(int i=0;i<n;i++)
	{
		for(int v:vec[i])
		{
			ans[v]=cur;
		}
		cur--;
	}
	for(int i=0;i<n;i++)
	{
		int cnt=0;
		for(int j=0;j<i;j++)
		{
			if(ans[j]>ans[i]) cnt++;
		}
		if(cnt!=a[i]){cout<<"NO\n"; return 0;}
		cnt=0;
		for(int j=i+1;j<n;j++)
		{
			if(ans[j]>ans[i]) cnt++;
		}
		if(cnt!=b[i]){cout<<"NO\n"; return 0;}
	}
	cout<<"YES\n";
	for(int i=0;i<n;i++)
	{
		cout<<ans[i];
		if(i+1<n) cout<<' ';
	}
	cout<<'\n';
}