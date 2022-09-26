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

const int LG = 31;
int dp[LG][100001];
bool ans[LG][100001];
int dp2[LG][100001];
int L[100001];
int R[100001];
int V[100001];

int cnt(int j, int l, int r)
{
	if(l == 0) return dp2[j][r];
	else return dp2[j][r] - dp2[j][l-1];
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, q; cin >> n >> q;
	for(int i = 0; i < q; i++)
	{
		int l, r, v;
		cin >> l >> r >> v;
		l--; r--;
		L[i] = l; R[i] = r; V[i] = v;
		for(int j = 0; j < LG; j++)
		{
			if(v&(1<<j))
			{
				dp[j][l]++;
				dp[j][r+1]--;
			}
		}	
	}
	for(int j = 0; j < LG; j++)
	{
		int cur = 0;
		for(int i = 0; i < n; i++)
		{
			cur += dp[j][i];
			if(cur > 0)
			{
				//cout << j << ' ' << i << ' ' << cur << '\n';
				ans[j][i] = 1;
			}
			dp2[j][i] = ans[j][i];
			if(i > 0) dp2[j][i] += dp2[j][i-1];
		}
	}
	for(int i = 0; i < q; i++)
	{
		int l = L[i];
		int r = R[i];
		int v = V[i];
		for(int j = 0; j < LG; j++)
		{
			if(!(v&(1<<j)))
			{
				//cerr << i << ' ' << j << ' ' << cnt(j, l, r) << '\n';
				if(cnt(j, l, r) == r - l + 1)
				{
					cout << "NO";
					return 0;
				}
			}
		}
	}
	cout << "YES\n";
	for(int i = 0; i < n; i++)
	{
		int val = 0;
		for(int j = 0; j < LG; j++)
		{
			if(ans[j][i]) val += (1<<j);
		}
		cout << val << ' ';
	}
}