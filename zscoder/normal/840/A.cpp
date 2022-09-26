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

ll a[200001];
ll b[200001];
ll ans[200001];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	vector<ii> A;
	for(int i=0;i<n;i++) 
	{
		cin>>a[i];
		A.pb(mp(a[i],i));
	}
	vector<ii> vec;
	for(int i=0;i<n;i++) 
	{
		cin>>b[i];
		vec.pb(mp(b[i],i));
	}
	sort(A.begin(),A.end());
	sort(vec.rbegin(),vec.rend());
	for(int i = 0; i < n; i++)
	{
		ans[vec[i].se] = A[i].fi;
	}
	for(int i=0;i<n;i++)
	{
		cout<<ans[i];
		if(i+1<n) cout<<' ';
	}
	cout<<'\n';
}