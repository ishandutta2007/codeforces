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

const int N = 4e5 + 10;

namespace MOD {
	const int P = 998244353;
	inline int add(int x, int y) {return x + y >= P ? x + y - P : x + y;}
	inline int sub(int x, int y) {return x < y ? x - y + P : x - y;}
	inline int mul(int x, int y) {return (long long)x * y % P;}
	inline void inc(int &x, int y) {x = add(x, y);}
	inline void dec(int &x, int y) {x = sub(x, y);}
	inline void upd(int &x, int y) {x = mul(x, y);}
};
using namespace MOD;

int Pow(int x, int y) {
	int r = 1;
	while (y) {
		if (y & 1) upd(r, x);
		upd(x, x), y >>= 1;
	}
	return r;
}

int pw[N], iv[N];

void init(int n) {
	pw[0] = iv[0] = 1;
	for (int i = 1; i <= n; i++)
		pw[i] = mul(pw[i - 1], i);
	int Inv = Pow(pw[n], P - 2);
	for (int i = n; i >= 1; i--)
		iv[i] = Inv, upd(Inv, i);
}

int C(int x, int y) {
	if (y < 0 || x < y) return 0;
	return mul(pw[x], mul(iv[y], iv[x - y]));
}

struct Node {
	int x, lz, lch, rch, s;
}	o[N];
int cnt = 0;

int ne_node(int x) {
	o[++cnt] = (Node){x, 0, 0, 0, 1};
	return cnt;
}

void PushUp(int x) {
	o[x].s = 1 + o[o[x].lch].s + o[o[x].rch].s;
}

void Update(int x, int t) {
	if (!x) return;
	o[x].x += t, o[x].lz += t;
}

void PushDown(int x) {
	if (o[x].lz) {
		Update(o[x].lch, o[x].lz);
		Update(o[x].rch, o[x].lz);
		o[x].lz = 0;
	}
}

int merge(int x, int y) {
	if (!x || !y) return x + y;
	PushDown(x), PushDown(y);
	if (rand() % (o[x].s + o[y].s) < o[x].s)
		return o[x].rch = merge(o[x].rch, y), PushUp(x), x;
	else return o[y].lch = merge(x, o[y].lch), PushUp(y), y;
}

void split(int now, int k, int &x, int &y) {
	if (!now) return x = y = 0, void();
	PushDown(now);
	if (k >= o[now].x) x = now, split(o[now].rch, k, o[x].rch, y);
	else y = now, split(o[now].lch, k, x, o[y].lch);
	PushUp(now);
}

void output(int x) {
	if (!x) return;
	PushDown(x);
	output(o[x].lch);
	cout << o[x].x << " ";
	output(o[x].rch);
}

int T, n, m, rt = 0;

int main() {
	init(400000);
	for (read(T); T; T--) {
		read(n), read(m), cnt = rt = 0;
		for (int i = 1; i <= m; i++) {
			int x, y; read(x), read(y);
			int t1, t2, t3;
			split(rt, y - 2, t1, t2);
			split(t2, y - 1, t2, t3);
			if (!t2) t2 = ne_node(y);
			else Update(t2, 1);
			Update(t3, 1);
			rt = merge(t1, merge(t2, t3));
		}
		printf("%d\n", C(n + n - 1 - cnt, n));
	}
	return 0;
}