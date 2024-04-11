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

const int N = 5e5 + 10;

int T, n, dp[N];
char s[N];

int get(int x) {
	if (x <= 100) return dp[x];
	return dp[x % 34 + 68];
}

int main() {
	dp[0] = 0;
	for (int i = 2; i <= 200; i++) {
		vector<int> a;
		for (int j = 0; j <= i - 2; j++)
			a.push_back(dp[j] ^ dp[i - j - 2]);
		sort (a.begin(), a.end());
		for (int j = 0; j < a.size(); j++)
			if (dp[i] == a[j]) dp[i]++;
	}
	for (read(T); T; T--) {
		read(n);
		scanf("%s", s + 1);
		int ans = 0, cr = 0, cb = 0;
		for (int i = 1; i <= n; i++) {
			if (s[i] == 'R') cr++;
			else cb++;
		}
		if (cr != cb) {
			puts(cr > cb ? "Alice" : "Bob");
			continue;
		}
		vector<int> a;
		int lst = 1;
		for (int i = 2; i <= n; i++) {
			if (s[i] == s[i - 1]) {
				ans ^= get(i - lst);
				lst = i;
			}
		}
		if (lst < n) ans ^= get(n - lst + 1);
		puts(ans ? "Alice" : "Bob");
	}
	return 0;
}