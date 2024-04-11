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

int T, n, m;

int main() {
	for (read(T); T; T--) {
		read(n), read(m);
		vector<int> a, b;
		for (int i = 0, x; i < m; i++)
			scanf("%d", &x), a.pb(x);
		sort(a.begin(), a.end());
		for (int i = 0; i < m - 1; i++)
			if (a[i + 1] > a[i] + 1)
				b.pb(a[i + 1] - a[i] - 1);
		if (m > 1 && a[0] - 1 + n - a[m - 1] > 0)
			b.pb(a[0] - 1 + n - a[m - 1]);
		if (m == 1)
			b.pb(n - 1);
		sort (b.begin(), b.end());
		reverse (b.begin(), b.end());
		int ans = 0, d = 0;
		for (int i = 0; i < b.size(); i++) {
			int nw = b[i] - d * 2;
			if (nw >= 3) {
				ans += nw - 1;
				d += 2;
			}
			else if (nw == 2 || nw == 1)
				ans += 1, d += 1;
		}
		printf("%d\n", n - ans);
	}
	return 0;
}