#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5 + 10, mod = 998244353;

int n, T, a[N], b[N], c[N], d[N], ans, f[N], g[N];

vector <int> e[N], p[N];

int fpow_(int a, int b, int res = 1) {
	for (; b; b >>= 1, a = 1ll*a*a%mod) {
		if (b&1) {
			res = 1ll*res*a%mod;
		}
	}
	
	return res;
}

int gcd_(int a, int b) {
	while (b) {
		a %= b;
		swap(a, b);
	}
	
	return a;
}

void calc_(int x, int op) {
	for (int y : p[x]) {
		int cnt = 0, tmp = x;
		
		while (tmp%y == 0) {
			tmp /= y;
			cnt++;
		}
		
		g[y] += op*cnt;
		f[y] = max(g[y], f[y]);
	}
}

void dfs_(int u, int fa, int val) {
	ans = (ans + val)%mod;
	
	for (int i : e[u]) {
		int v, x, y;
		
		if (u == a[i]) {
			v = b[i];
			x = c[i], y = d[i];
		} else {
			v = a[i];
			x = d[i], y = c[i];
		}
		
		if (v == fa) {
			continue;
		}
		
		int z = gcd_(x, y);
		x /= z, y /= z;
		calc_(y, -1);
		calc_(x, 1);
		dfs_(v, u, 1ll*val*y%mod*fpow_(x, mod - 2)%mod);
		calc_(x, -1);
		calc_(y, 1);
	}
}

int main() {
	scanf("%d", &T);
	
	while (T--) {
		scanf("%d", &n);
		ans = 0;
		
		for (int i = 1; i <= n; i++) {
			e[i].clear();
		}
		
		for (int i = 1; i < n; i++) {
			scanf("%d%d%d%d", &a[i], &b[i], &c[i], &d[i]);
			e[a[i]].push_back(i);
			e[b[i]].push_back(i);
		}
		
		for (int i = 2; i <= n; i++) {
			p[i].clear();
			f[i] = g[i] = 0;
		}
		
		for (int i = 2; i <= n; i++) {
			if (p[i].size()) {
				continue;
			}
			
			for (int j = 1; i*j <= n; j++) {
				p[i*j].push_back(i);
			}
		}
		
		dfs_(1, 0, 1);
		
		for (int i = 2; i <= n; i++) {
			if (f[i]) {
				ans = 1ll*ans*fpow_(i, f[i])%mod;
			}
		}
		
		printf("%d\n", (ans%mod + mod)%mod);
	}
}