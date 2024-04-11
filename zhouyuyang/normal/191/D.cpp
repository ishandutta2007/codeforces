#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=(b); i++)
using namespace std;
const int maxn = 100009;
int n, m, u, v, ans;
vector<int> e[maxn];
int main() {
	scanf("%d%d", &n, &m);
	rep (i, 1, m) scanf("%d%d", &u, &v), e[u].push_back(v), e[v].push_back(u);
	rep (i, 1, n) ans += e[i].size() & 1;
	rep (i, 1, n) if (e[i].size() == 2) {
		int x = e[i][0], y = e[i][1];
		if (x == y) e[x].clear(), ans += 2;
		else e[x][e[x][0]!=i] = y, e[y][e[y][0]!=i] = x;
	}
	printf("%d %d\n", ans / 2, m);
}