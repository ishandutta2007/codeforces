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

const int N = 1e5 + 10;

int T, n, p[N], vis[N];

int main() {
	for (read(T); T; T--) {
		read(n);
		vector<pair<int,int> > v(n + 1);
		for (int i = 1; i <= n; i++)
			read(v[i].fi);
		for (int i = 1; i <= n; i++)
			read(v[i].se);
		sort (v.begin() + 1, v.end());
		for (int i = 1; i <= n; i++)
			p[i] = v[i].se, vis[i] = 0;
		int l = 0;
		for (int i = 1; i <= n; i++) {
			if (vis[i]) continue;
			int t = p[i], ct = 1;
			vis[i] = 1;
			while (t != i)
				vis[t] = 1, ct++, t = p[t];
			l += (ct - (ct & 1)) / 2;
		}
		ll ans = 0;
		for (int i = 1; i <= l; i++)
			ans += 2 * ((n - i + 1) - i);
		print(ans, '\n');
	}
	return 0;
}