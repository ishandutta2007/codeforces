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

int T, n, a[N];

int main() {
	for (read(T); T; T--) {
		read(n);
		lep (i, 1, n) read(a[i]);
		int ct = 0, m = n;
		for (int j = 1; j < n; j++) {
			vector<int> b;
			if (ct > 0 && m > 0) {
				b.push_back(a[1]);
				ct--;
			}
			for (int i = 1; i < m; i++) {
				a[i] = a[i + 1] - a[i];
				if (a[i] > 0) b.pb(a[i]);
				else ct++;
			}
			sort(b.begin(), b.end());
			m = b.size();
			for (int i = 1; i <= m; i++)
				a[i] = b[i - 1];
		}
		if (m > 0) printf("%d\n", a[1]);
		else puts("0");
	}
	return 0;
}