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
const ll INFLL = ll(1e18);
const int MOD = 1e9 + 7;
const ld eps = 1e-7;

void yes(){cout << "YES" << '\n';}
void no(){cout << "NO" << '\n';}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for(int i = 1; i <= n; i++)
	{
		if(i == n)
		{
			if(i&1)
			{
				cout << "I hate it";
			}
			else
			{
				cout << "I love it";
			}
		}
		else
		{
			if(i&1)
			{
				cout << "I hate that ";
			}
			else
			{
				cout << "I love that ";
			}
		}
	}
	return 0;
}