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

int n, a, b, c;

bool dp[4001][4001];
bool visited[4001][4001];

bool solve(int n, int k)
{
	if(k == 0 && n != 0) return 0;
	if(visited[n][k]) return dp[n][k];
	if(n >= a) dp[n][k]|=solve(n-a,k-1);
	if(n >= b) dp[n][k]|=solve(n-b,k-1);
	if(n >= c) dp[n][k]|=solve(n-c,k-1);
	visited[n][k] = 1;
	return dp[n][k];
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> a >> b >> c;
	dp[0][0] = 1; visited[0][0] = 1;
	for(int i = n; i >= 0; i--)
	{
		if(solve(n, i))
		{
			cout << i; return 0;
		}
	}
}