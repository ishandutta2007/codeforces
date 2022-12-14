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

const int N = 4e6 + 10;

int n, P;

namespace MOD {
	inline int add(int x, int y) {return x + y >= P ? x + y - P : x + y;}
	inline int sub(int x, int y) {return x < y ? x - y + P : x - y;}
	inline int mul(int x, int y) {return (long long)x * y % P;}
	inline void inc(int &x, int y) {x = add(x, y);}
	inline void dec(int &x, int y) {x = sub(x, y);}
	inline void upd(int &x, int y) {x = mul(x, y);}
};
using namespace MOD;

struct BIT {
	int a[N];
	void Mdf(int x, int t) {
		for (; x <= n; x += x & (-x))
			inc(a[x], t);
	}
	int Qry(int x) {
		int r = 0;
		for (; x; x -= x & (-x))
			inc(r, a[x]);
		return r;
	}
}	st;

int main() {
	read(n), read(P);
	st.Mdf(n, 1);
	for (int i = n - 1; i >= 1; i--) {
		int tmp = sub(st.Qry(n), st.Qry(i));
		for (int j = i + i, k = 2; j <= n; j += i, k++) {
			int l = j, r = min(j + k - 1, n);
			inc(tmp, sub(st.Qry(r), st.Qry(l - 1)));
		} 
		st.Mdf(i, tmp);
	}
	print(st.Qry(1), '\n');
	return 0;
}