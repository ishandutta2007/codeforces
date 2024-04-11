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
const int LG = 20;

ll a[1001][1001];
ll r[1001]; //row sum
ll c[1001]; //column sum
int n;

void no()
{
	cout << -1 << '\n';
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	int x, y; ll diagonal1 = 0; ll diagonal2 = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cin >> a[i][j];
			if(a[i][j] == 0)
			{
				x = i; y = j;
			}
			else
			{
				r[i] += a[i][j];
				c[j] += a[i][j];
				if(i == j)
				{
					diagonal1 += a[i][j];
				}
				if(i + j == n - 1)
				{
					diagonal2 += a[i][j];
				}
			}
		}
	}
	if(n == 1)
	{
		cout << 1 << '\n';
		return 0;
	}
	ll commonsum = r[0];
	if(x == 0) commonsum = r[1];
	//cout << commonsum << '\n';
	ll rowsum = -1; ll colsum = -1; ll d1sum = -1; ll d2sum = -1;
	for(int i = 0; i < n; i++)
	{
		if(i != x)
		{
			if(r[i] != commonsum)
			{
				no();
				return 0;
			}
		}
		else
		{
			rowsum = r[i];
		}
	}
	for(int i = 0; i < n; i++)
	{
		if(i != y)
		{
			if(c[i] != commonsum)
			{
				no(); return 0;
			}
		}
		else
		{
			colsum = c[i];
		}
	}
	bool isdiagonal1 = false; bool isdiagonal2 = false;
	if(x == y) isdiagonal1 = true;
	if(x + y == n - 1) isdiagonal2 = true;
	if(!isdiagonal1)
	{
		if(diagonal1 != commonsum)
		{
			no();
			return 0;
		}
	}
	else
	{
		d1sum = diagonal1;
	}
	if(!isdiagonal2)
	{
		if(diagonal2 != commonsum)
		{
			no();
			return 0;
		}
	}
	else
	{
		d2sum = diagonal2;
	}
	if(rowsum == colsum)
	{
		if(isdiagonal1 && d1sum != rowsum)
		{
			no();
			return 0;
		}
		if(isdiagonal2 && d2sum != rowsum)
		{
			no();
			return 0;
		}
		ll value = commonsum - rowsum;
		if(value > 0)
		{
			cout << value << '\n';
			return 0;
		}
		else
		{
			no();
			return 0;
		}
	}
	else
	{
		no();
		return 0;
	}
}