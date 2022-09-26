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
const int N = 1e6 + 3;

int a[N];
int visited[N];
ll ans;
vector<int> cycles;
ll dp[N];
int cyclecnt;

void dfs2(int u)
{
	cycles[cyclecnt]++;
	visited[u] = 3;
	if(visited[a[u]] == 3) return ;
	dfs2(a[u]);
}

void dfs(int u)
{
	visited[u] = 2;
	if(visited[a[u]] == 0)
	{
		dfs(a[u]);
	}
	else if(visited[a[u]] == 1)
	{
		visited[u] = 1;
		return ;
	}
	else
	{
		cycles.pb(0);
		dfs2(u);
		cyclecnt++;
	}
	visited[u] = 1;
}

int main()
{
	//ios_base::sync_with_stdio(0); cin.tie(0);
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", a + i);
	}
	dp[0] = 1;
	for(int i = 1; i <= n; i++)
	{
		dp[i] = (dp[i-1]*2LL)%MOD;
	}
	ans = 1;
	memset(visited, 0, sizeof(visited));
	for(int i = 1; i <= n; i++)
	{
		if(visited[i] == 0)
		{
			dfs(i);
		}
	}
	ll cnt = n;
	for(int i = 0; i < cycles.size(); i++)
	{
		cnt -= cycles[i];
		ans = (ans*(dp[cycles[i]]-2+MOD))%MOD;
	}
	ans = (ans*dp[cnt])%MOD;
	if(ans < 0) ans += MOD;
	int ans2 = ans;
	printf("%d\n", ans2);
	return 0;
}