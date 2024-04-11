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

bool a[101][101];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m, k; 
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}
	int ans = 100;
	if(n <= k)
	{
		for(int i = 0; i < (1<<n); i++)
		{
			int sum = 0;
			for(int j = 0; j < m; j++)
			{
				int cur = 0;
				for(int k = 0; k < n; k++)
				{
					if(a[k][j] != ((i&(1<<k))>0)) cur++;
				}
				cur = min(cur, n - cur);
				sum += cur;
			}
			ans = min(ans, sum);
		}
	}
	else
	{
		for(int i = 0; i < n; i++)
		{
			int sum = 0;
			for(int j = 0; j < m; j++)
			{
				int cur = 0;
				for(int k = 0; k < n; k++)
				{
					if(a[k][j] != a[k][i]) cur++;
				}
				cur = min(cur, n - cur);
				//cerr << i << ' ' << j << ' ' << cur << '\n';
				sum += cur;
			}
			//cerr << i << ' ' << sum << '\n';
			ans = min(ans, sum);
		}
		//cout << ans << '\n';
	}
	if(ans > k) ans = -1;
	cout<<ans;
}