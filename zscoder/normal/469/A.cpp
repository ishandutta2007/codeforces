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

bool used[10001];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int l;
	cin >> l;
	int n; cin >> n;
	for(int i = 0; i < n; i++) 
	{
		int x; cin >> x;
		used[x] = 1;
	}
	int m; cin >> m;
	for(int i = 0; i < m; i++) 
	{
		int x; cin >> x;
		used[x] = 1;
	}
	for(int i = 1; i <= l; i++)
	{
		if(!used[i]){cout << "Oh, my keyboard!"; return 0;}
	}
	cout << "I become the guy.";
}