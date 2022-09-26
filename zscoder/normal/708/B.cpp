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

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

void no(){cout << "Impossible" << endl;}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll a, b, c, d; cin >> a >> b >> c >> d;
	ll z = -1; ll o = -1;
	for(ll i = 1; i <= 100000; i++)
	{
		if((i*(i-1))/2 == a) z = i;
		if((i*(i-1))/2 == d) o = i;
	}
	if(z == -1 || o == -1) 
	{
		no(); return 0;
	}
	if(a == 0)
	{
		if(b == 0 && c == 0)
		{
			for(int j = 0; j < o; j++)
			{
				cout << 1;
			}
			return 0;
		}
		int pos = c + 1; int n = o + 1;
		if(b == n - pos)
		{
			if(1 <= pos && pos <= n)
			{
				for(int i = 1; i <= n; i++)
				{
					if(i == pos) cout << 0;
					else cout << 1;
				}
				return 0;
			}
			else
			{
				no(); return 0;
			}
		}
		else
		{
			no();
			return 0;
		}
		return 0;
	}
	if(d == 0)
	{
		if(b == 0 && c == 0)
		{
			for(int j = 0; j < z; j++)
			{
				cout << 0;
			}
			return 0;
		}
		int pos = b + 1; int n = z + 1;
		if(c == n - pos)
		{
			if(1 <= pos && pos <= n)
			{
				for(int i = 1; i <= n; i++)
				{
					if(i == pos) cout << 1;
					else cout << 0;
				}
				return 0;
			}
			else
			{
				no(); return 0;
			}
		}
		else
		{
			no();
			return 0;
		}
		return 0;
	}
	//Now, we are in the main case
	vi vec;
	int n = z + o;
	if(b + c != ll(z)*ll(o))
	{
		no(); return 0;
	}
	//We analyze c
	for(int i = z; i >= 1; i--)
	{
		int now = min(c, n - z);
		c -= now;
		vec.pb(now + i - 1);
	}
	if(c > 0)
	{
		no(); return 0;
	}
	string s = "";
	for(int i = 0; i < n; i++)
	{
		s += "1";
	}
	for(int i = 0; i < vec.size(); i++)
	{
		s[vec[i]] = '0';
	}
	cout << s;
}