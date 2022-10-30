#include <bits/stdc++.h>
using namespace std;

typedef double db;
const int maxn = 1e5, maxk = 100, mod = 1e9 + 7;
int n, m, k, u[maxk + 3], v[maxk + 3], w[maxk + 3], cnt1, cnt2, id1[maxn + 3], id2[maxn + 3];
int f[maxk + 3], g[maxk + 3], c[maxk + 3], cnt[maxk + 3][maxk + 3], num[maxk + 3][maxk + 3], fact[maxn + 3];
bool vis[maxk + 3];
vector<pair<int, int> > G[maxk + 3];
vector<int> S[maxk + 3];
map<int, int> M[maxk + 3][maxk / 2 + 3];

int chk_mod(int x) {
	return x < mod ? x : x - mod;
}

db calc(int f[]) {
	for (int i = 1; i <= m; i++) c[i] = 0;
	for (int i = 1; i <= k; i++) {
		int l = f[u[i]], r = f[v[i]];
		if (l > r) swap(l, r);
		for (int j = l; j < r; j++) c[j]++;
	}
	db ans = 0;
	for (int i = 1; i <= m; i++) ans += pow(2, c[i]);
	return ans;
}

void mod_add(int &x, int y) {
	x += y, x < mod ? 0 : x -= mod;
}

int main() {
	srand(time(0));
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= k; i++) {
		scanf("%d %d %d", &u[i], &v[i], &w[i]);
		w[i] = chk_mod(w[i] + mod - 1);
		if (!id1[u[i]]) id1[u[i]] = ++cnt1;
		if (!id2[v[i]]) id2[v[i]] = ++cnt2;
		u[i] = id1[u[i]], v[i] = id2[v[i]];
	}
	m = cnt1 + cnt2;
	for (int i = 1; i <= k; i++) v[i] += cnt1;
	for (int i = 1; i <= m; i++) f[i] = i;
	db res = 1e100;
	for (int i = 1; i <= 100; i++) {
		random_shuffle(f + 1, f + m + 1);
		db val = calc(f);
		for (int j = 1; j <= 300; j++) {
			int x = rand() % m + 1, y = rand() % m + 1;
			swap(f[x], f[y]);
			if (calc(f) > val) swap(f[x], f[y]);
			else val = calc(f);
		}
		if (val < res) res = val, copy(f + 1, f + m + 1, g + 1);
	}
	for (int i = 1; i <= k; i++) {
		int x = g[u[i]], y = g[v[i]];
		if (x > y) swap(x, y);
		cnt[x][x]++, cnt[y][x]--;
		G[y].push_back(make_pair(x, w[i]));
	}
	M[0][0][0] = 1;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= m; j++) cnt[i][j] += cnt[i - 1][j];
		for (int j = 1; j <= m; j++) if (cnt[i][j]) {
			num[i][j] = 1 << S[i].size(), S[i].push_back(j);
		}
		for (int j = 0; j <= k; j++) {
			for (map<int, int>::iterator it = M[i - 1][j].begin(); it != M[i - 1][j].end(); it++) {
				int msk = it -> first, val = it -> second;
				fill(vis + 1, vis + m + 1, false);
				for (int t = 0; t < S[i - 1].size(); t++) {
					if (msk >> t & 1) vis[S[i - 1][t]] = true;
				}
				int nmsk = 0;
				for (int t = 0; t < S[i].size(); t++) {
					if (vis[S[i][t]]) nmsk |= 1 << t;
				}
				mod_add(M[i][j][nmsk], val);
				for (int t = 0; t < G[i].size(); t++) {
					int x = G[i][t].first, w = G[i][t].second;
					if (!vis[x]) {
						int tmsk = nmsk;
						if (cnt[i][x]) tmsk |= num[i][x];
						if (cnt[i][i]) tmsk |= num[i][i];
						mod_add(M[i][j + 1][tmsk], 1ll * w * val % mod);
					}
				}
			}
		}
	}
	fact[0] = 1;
	for (int i = 1; i <= n; i++) fact[i] = 1ll * fact[i - 1] * i % mod;
	int ans = 0;
	for (int i = 0; i <= k && i <= n; i++) {
		int res = M[m][i][0];
		ans = (ans + 1ll * fact[n - i] * res) % mod;
	}
	printf("%d\n", ans);
	return 0;
}