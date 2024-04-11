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

int a[333333];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for(int i=0;i<n;i++)
	{
		ll x; cin>>x;
		a[i]=__builtin_popcountll(x);
	}
	int cnt[2] = {1,0};
	int sum=0; ll ans = 0;
	for(int i=0;i<n;i++)
	{
		sum+=a[i];
		sum%=2;
		ans += cnt[sum];
		cnt[sum]++;
	}
	const int C = 130;
	for(int i=0;i<n;i++)
	{
		int s=0; int mx=0;
		for(int j=i;j<min(i+C,n);j++)
		{
			s+=a[j]; mx=max(mx,a[j]);
			if(s%2==0&&mx>s/2) ans--;
		}
	}
	cout<<ans<<'\n';
}