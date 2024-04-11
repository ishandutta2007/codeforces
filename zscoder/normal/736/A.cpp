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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

const ll INF = ll(2e18);
ll f[100001];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll n; cin>>n;
	int ans = 0;
	f[1] = 2;
	f[2] = 3;
	ll sum = f[1];
	for(int i = 3; i <= 1000; i++)
	{
		f[i] = sum+3;
		if(f[i]>=INF) break;
		sum += f[i-1];
	}
	for(int i = 1; i <= 1000; i++)
	{
		//cerr<<i<<' '<<f[i]<<'\n';
		if(n>=f[i])
		{
			ans=i;
		}
		else
		{
			cout<<ans;
			return 0;
		}
	}
}