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

const ld eps = 1e-10;

ll a[1001]; int n;

bool valid(ld mid, ll l)
{
	if(a[0] > mid) return false;
	if(l - a[n-1] > mid) return false;
	for(int i = 1; i < n; i++)
	{
		if(a[i] - a[i-1] > ld(2)*mid) return false;
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ld lo = 0; ld hi = 1e9;
	int l; cin >> n >> l;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);
	for(int i = 0; i <= 100; i++)
	{
		ld mid = (lo+hi)/2;
		if(valid(mid, l))
		{
			hi = mid;
		}
		else
		{
			lo = mid;
		}
	}
	cout << fixed << setprecision(15) << lo;
}