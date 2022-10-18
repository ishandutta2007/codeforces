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

int T, n, m;
ll a[N];

int main() {
	for (read(T); T; T--) {
		read(n), read(m); ll mx = 0, mn = 1e18;
		int wh = 0;
		for (int i = 0; i < n; i++) {
			a[i] = 0;
			for (int j = 0, x; j < m; j++)
				read(x), a[i] += 1ll * x * j;
			if (a[i] > mx) wh = i + 1;
			mx = max(mx, a[i]);
			mn = min(mn, a[i]);
		}
		printf("%d %lld\n", wh, mx - mn);

	}
	return 0;
}