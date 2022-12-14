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

const int N = 2e5 + 10;

ll gcd(ll x, ll y) {
	if (y == 0) return abs(x);
	return gcd(y, x % y);
}

ll o[N << 2];

ll a[N];

void Build(int x, int l, int r) {
	if (l == r) return o[x] = abs(a[l]), void();
	int mid = (l + r) >> 1;
	Build(x << 1, l, mid);
	Build(x << 1 | 1, mid + 1, r);
	o[x] = gcd(o[x << 1], o[x << 1 | 1]);
}

ll Qry(int x, int l, int r, int tl, int tr) {
	if (tl <= l && r <= tr) return o[x];
	int mid = (l + r) >> 1;
	if (tr <= mid) return Qry(x << 1, l, mid, tl, tr);
	if (tl > mid) return Qry(x << 1 | 1, mid + 1, r, tl, tr);
	return gcd(Qry(x << 1, l, mid, tl, tr), Qry(x << 1 | 1, mid + 1, r, tl, tr));
}

int T, n;

int main() {
	for (read(T); T; T--) {
		read(n);
		for (int i = 1; i <= n; i++)
			read(a[i]);
		for (int i = n; i >= 2; i--)
			a[i] = a[i] - a[i - 1];
		Build(1, 1, n); int ans = 0;
		for (int i = 2, j = 2; i <= n; i++) {
			j = max(j, i);
			while (j < n) {
				ll t = Qry(1, 1, n, i, j + 1);
				if (t > 1 || t == 0) j++;
				else break;
			}
			if (abs(a[i]) == 1) continue;
			ans = max(j - i + 1, ans);
		}
		print(ans + 1, '\n');
	}
	return 0;
}