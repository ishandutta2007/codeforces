#include <stdio.h>
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(X) (X).begin(), (X).end()
#define lep(i, j, k) for (int i = (j); i <= (k); i++)
#define rep(i, j, k) for (int i = (j); i >= (k); i--)
#define Lep(i, j, k) for (int i = (j); i < (k); i++)
#define Rep(i, j, k) for (int i = (j); i > (k); i--)

using namespace std;

using ll = long long;
using ull = unsigned long long;
template <class T> using V = vector<T>;
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;

template <typename T>
void ckmin(T &A, T B) {A = A < B ? A : B;}
template <typename T>
void ckmax(T &A, T B) {A = A > B ? A : B;}

inline void read(int &x) {scanf("%d", &x);}
inline void print(int x) {printf("%d", x);}
inline void print(int x, char c) {printf("%d%c", x, c);}
inline void read(long long &x) {scanf("%lld", &x);}
inline void print(long long x) {printf("%lld", x);}
inline void print(long long x, char c) {printf("%lld%c", x, c);}

namespace MOD {
	const int P = 998244353;
	inline int add(int x, int y) {return x + y >= P ? x + y - P : x + y;}
	inline int sub(int x, int y) {return x < y ? x - y + P : x - y;}
	inline int mul(int x, int y) {return (long long)x * y % P;}
	inline void inc(int &x, int y) {x = add(x, y);}
	inline void dec(int &x, int y) {x = sub(x, y);}
	inline void upd(int &x, int y) {x = mul(x, y);}
	inline int Pow(int x, int y) {int r = 1; for (; y; y >>= 1, x = mul(x, x)) if (y & 1) r = mul(r, x); return r;}
};
using namespace MOD;

const int N = 1010;

int T, n, m, in[N], a[N], f[N];
vector<int> G[N];

int main() {
	for (read(T); T; T--) {
		read(n), read(m);
		for (int i = 1; i <= n; i++)
			in[i] = 0, G[i].clear(), read(a[i]);
		for (int i = 1, x, y; i <= m; i++) {
			read(x), read(y);
			G[x].push_back(y), in[y]++;
		}
		int ans = -1;
		for (int i = 1; i <= n; i++) {
			int flag = 0;
			for (int j = 1; j <= n; j++) {
				f[j] = a[j] > 0;
				if (a[j] > 0) flag = 1;
			}
			if (flag == 0) {
				ans = i - 1;
				break;
			}
			for (int j = 1; j <= n; j++)
				if (f[j]) {
					a[j]--;
					for (int k : G[j])
						a[k]++;
				}
		}
		if (ans != -1) {
			printf("%d\n", ans);
			continue;
		}
		for (int i = 1; i <= n; i++)
			a[i] %= P;
		queue<int> q;
		for (int i = 1; i <= n; i++)
			if (!in[i]) q.push(i);
		while (q.size()) {
			int u = q.front(); q.pop();
			ans = a[u];
			for (int v : G[u]) {
				inc(a[v], a[u]);
				if (!(--in[v])) q.push(v);
			}
		}
		printf("%d\n", add(ans, n));
	}
	return 0;
}