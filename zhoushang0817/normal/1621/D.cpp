#include <stdio.h>
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define puu pair<ull,ull>
#define fi first
#define se second
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define mset(a, b) memset(a, b, sizeof a)
#define lep(i, j, k) for (int i = (j); i <= (k); i++)
#define rep(i, j, k) for (int i = (j); i >= (k); i--)
#define Lep(i, j, k) for (int i = (j); i < (k); i++)
#define Rep(i, j, k) for (int i = (j); i > (k); i--)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

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

int T, n; ll a[510][510];

int main() {
	for (read(T); T; T--) {
		read(n);
		for (int i = 1; i <= 2 * n; i++)
			for (int j = 1; j <= 2 * n; j++)
				read(a[i][j]);
		ll s = 0, mn = 2e9;
		for (int i = n + 1; i <= 2 * n; i++)
			for (int j = n + 1; j <= 2 * n; j++)
				s += a[i][j];
		mn = min(mn, a[1][n + 1]);
		mn = min(mn, a[n][n + 1]);
		mn = min(mn, a[n + 1][1]);
		mn = min(mn, a[n + 1][n]);
		mn = min(mn, a[2 * n][1]);
		mn = min(mn, a[2 * n][n]);
		mn = min(mn, a[1][2 * n]);
		mn = min(mn, a[n][2 * n]);
		print(s + mn, '\n');
	}
	return 0;
}