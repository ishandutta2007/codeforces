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

int T, n, m, k, a[N];

int check() {
	ll mor = 0, ans = 0;
	for (int i = k; i >= 1; i--) {
		if (a[i] >= 2 * n) {
			if (ans + 2 > m)
				break;
			ans += 2;
			mor += a[i] / n - 2;
		}
		else break;
	}
	return ans + mor >= m;
}

int main() {
	for (scanf("%d", &T); T; T--) {
		scanf("%d%d%d", &n, &m, &k);
		for (int i = 1; i <= k; i++)
			scanf("%d", &a[i]);
		sort (a + 1, a + k + 1);
		int ok = check();
		swap(n, m);
		ok |= check();
		puts(ok ? "Yes" : "No");
	}
	return 0;
}