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

int l[100001];
int r[100001];
int a[100001];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	l[1] = 1;
	for(int i = 1; i < n; i++)
	{
		if(a[i] > a[i-1]) l[i+1] = l[i] + 1;
		else l[i+1] = 1;
	}
	r[n-1] = 1; r[n] = 0;
	for(int i = n - 2; i >= 0; i--)
	{
		if(a[i] < a[i + 1]) r[i] = r[i+1] + 1;
		else r[i] = 1;
	}
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		bool t = true;
		if(i > 0 && i < n - 1 && a[i-1]+1>=a[i+1]) t = false;
		//cerr << i << ' ' << l[i] << ' ' << r[i+1] << '\n';
		if(t) ans = max(ans, 1 + l[i] + r[i+1]);
		else ans = max(ans, max(l[i]+1, r[i+1]+1));
	}
	cout << ans;
}