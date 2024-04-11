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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

const int N = 1e5 + 3;
ll a[N];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, c; cin >> n >> c;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int cnt = 0;
	for(int i = 0; i < n; i++)
	{
		if(i == 0) cnt++;
		else
		{
			if(a[i] - a[i - 1] <= c) cnt++;
			else cnt = 1;
		}
	}
	cout << cnt;
	return 0;
}