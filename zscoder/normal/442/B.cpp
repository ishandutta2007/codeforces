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

ld p[101];
ld q[101];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for(int i = 0; i < n; i++) cin >> p[i];
	sort(p, p + n);
	for(int i = 0; i < n; i++) q[i] = 1 - p[i];
	ld ans = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = i; j < n; j++)
		{
			//[i, j] is the segment
			ld cur = 1;
			for(int k = i; k <= j; k++) cur *= q[k];
			if(cur == 0)
			{
				ans = 1;
				break;
			}
			ld cur2 = 0;
			for(int k = i; k <= j; k++) cur2 += p[k]/q[k];
			ans = max(ans, cur*cur2);
		}
		if(ans == 1) break;
	}
	cout << fixed << setprecision(15) << ans;
}