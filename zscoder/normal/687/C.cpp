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

bool dp[501][501][501];
int a[501];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, k; cin >> n >> k;
	for(int i = 0; i < n; i++) cin>>a[i];
	dp[0][a[0]][a[0]] = true;
	dp[0][0][0] = true;
	dp[0][a[0]][0] = true;
	for(int i = 1; i < n; i++)
	{
		for(int j = 0; j <= k; j++)
		{
			for(int z = 0; z <= j; z++)
			{
				dp[i][j][z] = dp[i-1][j][z];
				if(j>=a[i]) dp[i][j][z] |= dp[i-1][j-a[i]][z];
				if(z>=a[i]) dp[i][j][z] |= dp[i-1][j-a[i]][z-a[i]];
			}
		}
	}
	vi vec;
	for(int i = 0; i <= k; i++)
	{
		if(dp[n-1][k][i])
		{
			vec.pb(i);
		}
	}
	cout<<vec.size()<<'\n';
	for(int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << ' ';
	}
}