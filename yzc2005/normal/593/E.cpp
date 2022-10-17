#include <bits/stdc++.h> 
using namespace std;
#define mem(a, x) memset(a, x, sizeof(a))
#define fu(i, a, b) for(int i = a, I = (b) + 1; i < I; ++i)
#define fd(i, a, b) for(int i = a, I = (b) - 1; i > I; --i)
template <class T> inline void rd(T &x) {
    x = 0; T f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') f = ch == '-' ? -1 : 1, ch = getchar();
    while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    x *= f;
} 

const int N = 21, mod = 1e9 + 7;
const int dir[5][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {0, 0}};
int n, m, sz, q, tp, x, y, t, id[N][N];
bool valid[N][N];

inline void add(int &a, int b) {
	a += b;
	if(a > mod) a -= mod;
}
inline int mul(int a, int b) {
	return 1ll * a * b % mod;
} 

struct mat {
	int n, m, a[N][N];
	mat(int _n = 0, int _m = 0) {
		n = _n, m = _m;
		mem(a, 0);
	}
	inline void operator ~ () {
		fu(i, 1, n) a[i][i] = 1;
	}
	inline mat operator * (const mat &b) const {
		mat ans(n, b.m); 
		fu(i, 1, n) fu(j, 1, b.m) fu(k, 1, m) add(ans.a[i][j], mul(a[i][k], b.a[k][j]));
		return ans; 
	}
	inline mat operator ^ (int b) const {
		mat ans(n, m), base = *this; ~ans;
		while(b) {
			if(b & 1) ans = ans * base;
			base = base * base, b >>= 1;
		}
		return ans;
	} 
};

inline void build(mat &g) {
	mem(g.a, 0); 
	fu(i, 1, n) fu(j, 1, m) {
		if(!valid[i][j]) continue;
		fu(k, 0, 4) {
			int x = i + dir[k][0], y = j + dir[k][1];
			if(x < 1 || x > n || y < 1 || y > m) continue;
			if(!valid[x][y]) continue;
			g.a[id[x][y]][id[i][j]] = 1;
		}
	}
}

int main() {
	rd(n), rd(m), rd(q);
	mem(valid, 1);
	fu(i, 1, n) fu(j, 1, m) id[i][j] = ++sz;
	mat ans(1, sz), g(sz, sz); 
	ans.a[1][1] = 1;	
	for(int lstt = 1; q; --q, lstt = t) {
		rd(tp), rd(x), rd(y), rd(t);
		build(g), ans = ans * (g ^ (t - lstt));
		if(tp == 1) printf("%d\n", ans.a[1][id[x][y]]);
		if(tp == 2) valid[x][y] = 0, ans.a[1][id[x][y]] = 0;
		if(tp == 3) valid[x][y] = 1;
	}
	return 0;
}