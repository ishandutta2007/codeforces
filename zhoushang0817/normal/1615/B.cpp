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

int T;

int calc(int a, int k) {
	int ret = 0;
	for (int i = 20; i >= 0; i--) {
		if (i > k && (a >> i & 1))
			ret += (1 << i - 1);
		else if (i == k) {
			if (!(a >> i & 1)) break;
			ret++;
		}
		else if (a >> i & 1) ret += (1 << i);
	}
	return ret;
}

int get(int k, int l, int r) {
	return calc(r, k) - calc(l - 1, k);
}

int main() {
	for (read(T); T; T--) {
		int l, r; read(l), read(r);
		int ans = inf;
		for (int i = 0; i <= 20; i++) {
			ans = min(ans, r - l + 1 - get(i, l, r));
			//cout << get(i, l, r) << endl;
		}
		print(ans, '\n');
	}
	return 0;
}