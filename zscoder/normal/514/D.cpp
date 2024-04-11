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

const int LG = 18;
int a[100001][6];
int st[100001][LG][5];
int n, m, k; 

int rmq(int l, int r, int mode)
{
	if(l > r) return 0;
	int k = 31 - __builtin_clz(r-l);
	return max(st[l][k][mode], st[r - (1<<k) + 1][k][mode]);
}

void initst(int mode)
{
	for(int j = 0; j < LG; j++)
	{
		for(int i = 0; i < n; i++)
		{
			st[i][j][mode] = 0;
			if(i + (1<<j) - 1 < n)
			{
				if(j == 0) st[i][j][mode] = a[i][mode];
				else st[i][j][mode] = max(st[i][j-1][mode], st[i + (1<<(j-1))][j-1][mode]);
			}
		}
	}
}

bool check(int l, int r)
{
	int sum = 0;
	for(int i = 0; i < m; i++)
	{
		sum += rmq(l, r, i);
	}
	if(sum > k) return false;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			 cin >> a[i][j];
		}
	}
	for(int i = 0; i < m; i++) initst(i);
	int maxl = 0; int maxidx = 0;
	for(int i = 0; i < n; i++)
	{
		int lo = i; int hi = n - 1;
		int ans = i - 1;
		while(lo <= hi)
		{
			int mid = (lo + hi)>>1;
			if(check(i, mid))
			{
				lo = mid + 1;
				ans = mid;
			}
			else
			{
				hi = mid - 1;
			}
		}
		if(ans - i + 1 > maxl)
		{
			maxidx = i;
			maxl = ans - i + 1;
		}
	}
	for(int i = 0; i < m; i++)
	{
		cout << rmq(maxidx, maxidx + maxl - 1, i) << ' ';
	}
}