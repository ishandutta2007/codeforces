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
typedef vector<ll> vi;
typedef long double ld; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;

int a[111111];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,k; cin>>n>>k;
	int ans=0;
	int cur = 0;
	for(int i=0;i<n;i++) 
	{
		cin>>a[i];
		cur+=a[i];
		int give = min(cur,8);
		cur-=give;
		ans+=give;
		if(ans>=k)
		{
			cout<<i+1<<'\n'; return 0;
		}
	}
	cout<<-1<<'\n';
}