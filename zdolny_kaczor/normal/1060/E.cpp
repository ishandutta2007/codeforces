# include <bits/stdc++.h>
using namespace std;
const int MN = 2e5 + 44;
vector <int> graf[MN];
long long ans;
int n;
int black = 0;
int dfs(int x, int y = -1, int col = 1) {
	int ret = 1;
	if (col)
		black++;
	for (int v : graf[x])
		if (v != y) {
			ret += dfs(v, x, 1 - col);
		}
	ans += ret * 1ll * (n - ret);
	return ret;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	dfs(1);
	ans += black * 1ll * (n - black);
	assert(ans % 2 == 0);
	ans /= 2;
	printf("%lld\n", ans);
}