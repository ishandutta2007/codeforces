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

int apple[1000001];
int inv[1000001];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll n, m, dx, dy;
	cin >> n >> m >> dx >> dy;
	for(int i = 0; i < n; i++)
	{
		inv[(dx*i)%n] = i;
	}
	for(int i = 0; i < m; i++)
	{
		int x, y; cin >> x >> y;
		ll iv = inv[x];
		iv *= dy;
		iv %= n;
		iv = (y+n-iv)%n;
		apple[iv]++;
	}
	int maxappl = 0; int maxidx = 0;
	for(int i = 0; i < n; i++)
	{
		if(apple[i] > maxappl)
		{
			maxappl = apple[i]; maxidx = i;
		}
	}
	cout << 0 << ' ' << maxidx << '\n';
}