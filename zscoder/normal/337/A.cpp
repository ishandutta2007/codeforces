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

int a[1001];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		cin >> a[i];
	}
	sort(a,a+m);
	swap(n, m);
	int ans = 100000;
	for(int i = 0; i <= n - m; i++)
	{
		int maxi = -1; int mini = 100000;
		for(int j = i; j < i + m; j++)
		{
			maxi = max(maxi, a[j]);
			mini = min(mini, a[j]);
		} 
		ans = min(maxi - mini, ans);
	}
	cout<<ans;
}