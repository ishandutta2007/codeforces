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

const int N = 1e6 + 10;

int T, n, m, p[N], ans[N];
char s[N];

int main() {
	for (read(T); T; T--) {
		read(n), read(m);
		scanf("%s", s + 1);
		for (int i = 0; i <= n * m; i++) p[i] = 0;
		for (int i = 1; i <= n * m; i++)
			if (s[i] == '1') {
				p[i] += 1;
				if (i + m <= n * m) p[i + m] -= 1;
			}
		for (int i = 1; i <= n * m; i++)
			p[i] += p[i - 1];
		for (int i = 1; i <= n * m; i++)
			p[i] = p[i] > 0;
		for (int i = m + 1; i <= n * m; i++)
			p[i] += p[i - m];
		for (int i = 1; i <= n * m; i++)
			ans[i] = p[i], p[i] = 0;
		for (int i = 1; i <= n * m; i++)
			if (s[i] == '1') p[i] = 1;
		for (int i = m + 1; i <= n * m; i++)
			p[i] |= p[i - m];
		int s = 0;
		for (int i = 1; i <= n * m; i++) {
			s += p[i];
			if (i - m > 0) s -= p[i - m];
			ans[i] += s;
		}
		for (int i = 1; i <= n * m; i++)
			print(ans[i], ' ');
		puts("");
	}
	return 0;
}