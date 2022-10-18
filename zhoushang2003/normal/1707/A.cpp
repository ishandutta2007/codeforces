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

int n, q, a[N], s[N], fl[N];

int check(int mid) {
	for (int i = 1; i <= n; i++) {
		fl[i] = 0;
		if (a[i] <= q) fl[i] = 1, mid--;
	}
	if (mid <= 0) return 1;
	for (int i = n; i >= 1; i--)
		if (a[i] > q && mid) fl[i] = 1, mid--;
	int tmp = q;
	for (int i = 1; i <= n; i++) {
		if (fl[i]) {
			if (a[i] > tmp) tmp--;
			if (tmp < 0) return 0;
		}
	}
	return 1;
}

int main() {
	int T;
	for (read(T); T; T--) {
		read(n), read(q);
		for (int i = 1; i <= n; i++)
			read(a[i]);
		int l = 0, r = n;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (!check(mid)) r = mid - 1;
			else l = mid + 1;
		}
		check(r);
		for (int i = 1; i <= n; i++)
			printf("%d", fl[i]);
		puts("");
	}
	return 0;
}