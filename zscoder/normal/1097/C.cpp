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

ii a[111111];
const int C = 500111;
int ma[1111111];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for(int i=0;i<n;i++)
	{
		string s; cin>>s;
		int minpref=0; int sum=0;
		for(int j=0;j<s.length();j++)
		{
			sum+=(s[j]=='('?1:-1);
			minpref=min(minpref,sum);
		}
		a[i]=mp(minpref,sum);
		if(sum>=0)
		{
			if(minpref>=0) ma[sum+C]++;
		}
		else
		{
			if(minpref==sum) ma[sum+C]++;
		}
	}
	int ans=ma[C]/2;
	for(int i=1;i<=500000;i++)
	{
		ans+=min(ma[C+i],ma[C-i]);
	}
	cout<<ans<<'\n';
}