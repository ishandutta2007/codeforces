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

const int N = 1e4 + 10;

int T, n, m, lst[N], nxt[N];
char s[N];

int main() {
	ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		cin >> n >> m >> s + 1; int p = 0;
		for (int i = 1; i <= n; i++) {
			if (s[i] == '1') p = i;
			lst[i] = p;
		}
		p = 0;
		for (int i = n; i >= 1; i--) {
			if (s[i] == '1') p = i;
			nxt[i] = p;
		}
		for (int i = 1; i <= n; i++) {
			if (s[i] == '1') continue;
			if (lst[i] == 0 && nxt[i] == 0) continue;
			int x = abs(nxt[i] - i), y = abs(lst[i] - i);
			if (nxt[i] == 0) x = 0;
			if (lst[i] == 0) y = 0;
			if (lst[i] == 0 || nxt[i] == 0) {
				if (max(x, y) <= m)
					s[i] = '1';
			}
			else if (x != y && min(x, y) <= m) s[i] = '1';
		}
		cout << s + 1 << endl;
	}
	return 0;
}