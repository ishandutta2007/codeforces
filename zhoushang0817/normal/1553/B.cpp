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

const int N = 1010;

int T;
char s[N], t[N], tmp[N];

int main() {
	for (scanf("%d", &T); T; T--) {
		scanf("%s%s", s + 1, t + 1);
		int n = strlen(s + 1), m = strlen(t + 1);
		int flag = 0;
		for (int i = 1; i <= n; i++) {
			for (int R = 0; i + R <= n; R++) {
				if (R + 1 > m) continue;
				int left = m - (R + 1);
				if (i + R - left < 1) continue;
				int ct = 0;
				for (int k = i; k <= i + R; k++)
					tmp[++ct] = s[k];
				for (int k = i + R - 1; k >= i + R - left; k--)
					tmp[++ct] = s[k];
				int f = 1;
				for (int k = 1; k <= m; k++)
					if (tmp[k] != t[k]) f = 0;
				if (f == 1) flag = 1;
				if (flag) break;
			}
			if (flag) break;
		}
		if (flag) puts("YES");
		else puts("NO");
	}
	return 0;
}