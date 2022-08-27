#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;

typedef std::pair <int, int> pr;
typedef long long ll;
const int N = 1000054;

int n;

namespace odd {
	struct edge {
		int u, v, U, V;
		edge () {}
		edge (int u0, int v0, int U0, int V0) : u(u0), v(v0), U(U0), V(V0) {}
	} e[N];

	int E = 0;
	int first[N], next[N];
	bool used[N], ans[N];
	int fin[N];
	pr g[N];

	inline void addedge(int U, int V) {
		int u = U % n, v = V % n;
		e[++E] = edge(u, v, U, V), next[E] = first[u], first[u] = E;
		e[++E] = edge(v, u, V, U), next[E] = first[v], first[v] = E;
	}

	void dfs(int x, int pe, int st) {
		int i;
		if (used[x]) return;
		used[x] = true;
		for (i = first[x]; i; i = next[i]) {
			if ((i - 1) ^ (pe - 1) ^ 1) {
				ans[e[i].U] = true, dfs(e[i].v, i, st);
				return;
			}
		}
	}

	int main() {
		int i, j, x, s = 0; ll S = 0; bool flag;
		cout << "Second" << endl;
		for (i = 1; i <= 2 * n; ++i) cin >> x, --x, (g[x].first ? g[x].second : g[x].first) = i;
		for (i = 0; i < n; ++i) addedge(g[i].first, g[i].second);
		for (i = 0; i < n; ++i) if (!used[i]) {
			j = first[i], assert(j);
			if (e[j].u == e[j].v) ans[e[j].U] = true, used[i] = true;
			else dfs(i, -1, i);
		}
		for (i = 1; i <= 2 * n; ++i) if (ans[i]) ++s, S += i;
		assert(s == n && S % n == 0), flag = S % (2 * n) == 0;
		for (s = 0, i = 1; i <= 2 * n; ++i) if (ans[i] == flag) fin[++s] = i;
		for (i = 1; i < s; ++i) cout << fin[i] << ' ';
		cout << fin[s] << endl;
		return 0;
	}
}

namespace even {
	int main() {
		int i;
		cout << "First" << endl;
		for (i = 1; i <= n; ++i) cout << i << ' ';
		for (i = 1; i < n; ++i) cout << i << ' ';
		cout << n << endl;
		return 0;
	}
}

int main() {
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> n;
	return n & 1 ? odd::main() : even::main();
}