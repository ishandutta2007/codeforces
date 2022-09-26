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
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	if(x1 == x2)
	{
		int t = abs(y1 - y2);
		cout << x1+t << ' ' << y1 << ' ' << x1+t << ' ' << y2 << '\n';
	}
	else if(y1 == y2)
	{
		int t = abs(x1 - x2);
		cout << x1 << ' ' << y1+t << ' ' << x2 << ' ' << y1+t << '\n';
	}
	else
	{
		if(abs(x1-x2)==abs(y1-y2))
		{
			cout << x1 << ' ' << y2 << ' ' << x2 << ' ' << y1 << '\n';
		}
		else
		{
			cout << -1;
		}
	}
}