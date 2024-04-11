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

vector<ll> hits;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll n, x, y; cin >> n >> x >> y;
	for(int i = 1; i <= y; i++) hits.pb(x*i);
	for(int i = 1; i <= x; i++) hits.pb(y*i);
	sort(hits.begin(), hits.end());
	while(n--)
	{
		ll z; cin >> z; z--;
		z %= (x+y);
		ll cur = hits[z];
		if(cur%x==0 && cur%y==0)
		{
			cout << "Both\n";
		}
		else if(cur%y==0)
		{
			cout << "Vanya\n";
		}
		else
		{
			cout << "Vova\n";
		}
	}
}