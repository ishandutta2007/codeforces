#include <bits/stdc++.h>
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
 
const int N = (int)3e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;
 
int n, ans[N];
vector< int > v[N];
void solve(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		ans[i] = inf;
		v[i].clear();
	}
	for(int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);
		v[x].pb(i);
	}
	for(int i = 1; i <= n; i++){
		if(v[i].empty())
			continue;
		int k = max(v[i][0] + 1, n - v[i].back());
		for(int j = 1; j < v[i].size(); j++)
			k = max(k, v[i][j] - v[i][j - 1]);	
		ans[k] = min(ans[k], i);
	}
	for(int i = 2; i <= n; i++)
		ans[i] = min(ans[i], ans[i - 1]);
	for(int i = 1; i <= n; i++){
		if(ans[i] != inf)
			printf("%d ", ans[i]);
		else
			printf("-1 ");
	} 
	printf("\n");
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		solve();
}