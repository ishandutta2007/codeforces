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

const int N = 2e5 + 10;

int T, n, k, a[N], s[N];

int main() {
	for (read(T); T; T--) {
		read(n), read(k);
		for (int i = 1; i <= n; i++)
			s[i] = 0;
		for (int i = 1; i <= n; i++)
			read(a[i]), s[a[i]]++;
		for (int i = 1; i <= n; i++)
			s[i] += s[i - 1];
		int mn = inf, x = 0, y = 0;
		for (int i = 1, j = -1; i <= n; i++) {
			while (s[i] - s[j + 1] >= (n + k + 1) / 2) j++;
			if (j != -1 && i - j < mn) mn = i - j, x = j + 1, y = i;
		}
		int lst = 0, c = 0, v = 0;
		printf("%d %d\n", x, y);
		if (k == 1) {
			printf("%d %d\n", 1, n);
			continue;
		}
		for (int i = 1; i <= n; i++) {
			if (x <= a[i] && a[i] <= y) c++;
			else c--;
			if (c == 1) {
				v++;
				printf("%d %d\n", lst + 1, i);
				lst = i, c = 0;
				if (v == k - 1) break;
			}
		}
		printf("%d %d\n", lst + 1, n);
	}
	return 0;
}