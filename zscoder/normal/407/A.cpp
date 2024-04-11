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

int hyper(int x, int y)
{
	int f = x*x - y*y;
	if(int(sqrt(f)) == double(sqrt(f)))
	{
		return int(sqrt(f));
	}
	else
	{
		return -1;
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll a, b; cin >> a >> b;
	for(int i = 1; i < a; i++)
	{
		for(int j = 1; j < b; j++)
		{
			int z1 = hyper(a, i);
			int z2 = hyper(b, j);
			if(z1 != -1 && z2 != -1)
			{
				if(z1*z2==i*j)
				{
					cout << "YES\n0 0\n";
					if(i != j)
					{
						cout << z1 << ' ' << i << '\n';
						cout << -z2 << ' ' << j << '\n';
					}
					else
					{
						cout << z1 << ' ' << i << '\n';
						cout << z2 << ' ' << -j << '\n';
					}
					return 0;
				}
			}
		}
	}
	cout << "NO";
}