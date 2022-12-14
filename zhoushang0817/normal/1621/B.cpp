#include <stdio.h>
#include <bits/stdc++.h>
#define pb push_back
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

const int N = 1e5 + 10;

int T, n, l[N], r[N], c[N];
map <pair<int,int>, int> mp;

int main() {
	for (read(T); T; T--) {
		read(n);
		for (int i = 1; i <= n; i++)
			read(l[i]), read(r[i]), read(c[i]);
		mp.clear(); int mn = 1e9 + 10, mx = -1, c1 = inf, c2 = inf;
		for (int i = 1; i <= n; i++) {
			if (!mp[make_pair(l[i], r[i])]) mp[make_pair(l[i], r[i])] = c[i];
			else mp[make_pair(l[i], r[i])] = min(mp[make_pair(l[i], r[i])], c[i]);
			if (l[i] < mn) mn = l[i], c1 = c[i];
			else if (l[i] == mn) c1 = min(c1, c[i]);
			if (r[i] > mx) mx = r[i], c2 = c[i];
			else if (r[i] == mx) c2 = min(c2, c[i]);
			int ans = c1 + c2;
			if (mp[make_pair(mn, mx)] != 0) ans = min(ans, mp[make_pair(mn, mx)]);
			print(ans, '\n');
		}
	}
	return 0;
}