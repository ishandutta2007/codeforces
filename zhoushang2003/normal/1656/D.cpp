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
inline void ckmin(T &A, T B) {A = A < B ? A : B;}
template <typename T>
inline void ckmax(T &A, T B) {A = A > B ? A : B;}

inline void read(int &x) {scanf("%d", &x);}
inline void print(int x) {printf("%d", x);}
inline void print(int x, char c) {printf("%d%c", x, c);}
inline void read(long long &x) {scanf("%lld", &x);}
inline void print(long long x) {printf("%lld", x);}
inline void print(long long x, char c) {printf("%lld%c", x, c);}

int T, p[1000010], c, fl[1000010]; ll n;

int main() {
	for (int i = 2; i <= 1000000; i++) {
		if (!fl[i]) p[++c] = i;
		for (int j = 1; j <= c && p[j] * i <= 1000000; j++) {
			fl[p[j] * i] = 1;
			if (i % p[j] == 0) break;
		}
	}
	for (read(T); T; T--) {
		read(n);
		ll k = 0, ans = -1;
		while (n % 2 == 0) n /= 2, k++;
		if (k <= 30 && (1ll << k + 1) * ((1ll << k + 1) + 1) / 2 <= n * (1ll << k))
			ans = (1ll << k + 1);
		if (ans == -1) {
			if (n != 1 && n * (n + 1) / 2 <= n * (1ll << k)) ans = n;
			else {
				for (int j = 1; 1ll * p[j] * p[j] <= n && j <= c; j++)
					if (n % p[j] == 0) {
						if (1ll * p[j] * (p[j] + 1) / 2 <= n * (1ll << k)) ans = p[j];
						if (ans != -1) break;
					}
			}
		}
		print(ans, '\n');
	}
	return 0;
}