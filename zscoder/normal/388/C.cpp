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

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vi vec;
	int a[2] = {0,0};
	for(int i = 0; i < n; i++)
	{
		int k; cin >> k;
		for(int j = 0; j < k/2; j++)
		{
			int x; cin >> x; a[0]+=x;
		}
		if(k&1)
		{
			int x; cin >> x; vec.pb(x);
		}
		for(int j = 0; j < k/2; j++)
		{
			int x; cin >> x; a[1]+=x;
		}
	}
	if(!vec.empty()) {sort(vec.begin(), vec.end()); reverse(vec.begin(),vec.end());}
	for(int i = 0; i < vec.size(); i++)
	{
		a[(i&1)] += vec[i];
	}
	cout<<a[0]<<' '<<a[1];
}