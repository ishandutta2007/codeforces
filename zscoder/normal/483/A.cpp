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

ll gcd(ll a, ll b)
{
	if(a > b) swap(a, b);
	if(a == 1) return 1;
	if(a == 0) return b;
	return gcd(a, b%a);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll l, r;
	cin >> l >> r;
	for(ll a = l; a <= r; a++)
	{
		for(ll b = a + 1; b <= r; b++)
		{
			for(ll c = b + 1; c <= r; c++)
			{
				if(gcd(a,b)==1&&gcd(b,c)==1&&gcd(a,c)!=1)
				{
					cout << a << ' ' << b << ' ' << c << '\n';
					return 0;
				}
			}
		}
	}
	cout << -1;
}