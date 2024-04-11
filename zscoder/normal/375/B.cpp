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

char a[5001][5001];
int r[5001][5001];
int x[5001];
int c[5001];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m; cin>>n>>m;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		//getchar();
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = m - 1; j >= 0; j--)
		{
			if(a[i][j] == '0') r[j][i] = 0;
			else r[j][i] = r[j+1][i] + 1;
		}
	}
	int ans = 0;
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j <= m; j++) c[j]=0;
		for(int j = 0; j < n; j++)
		{
			c[r[i][j]]++;
		}
		for(int j = m - 1; j >= 0; j--)
		{
			c[j] += c[j+1];
		}
		for(int j = 1; j <= m; j++)
		{
			ans = max(j*c[j],ans);
		}
	}
	cout<<ans;
}