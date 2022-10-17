#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
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
template <class T> inline void ckmax(T &a, T b) {if(a < b) a = b;}
template <class T> inline void ckmin(T &a, T b) {if(a > b) a = b;}

const int N = 300005;
int n, m, f[N];
map <int, int> g;

struct edge {
	int u, v, w;
	inline bool operator < (const edge &e1) const {
		return w < e1.w;
	}
} e[N];

int main() {
	rd(n), rd(m);
	fu(i, 1, m) rd(e[i].u), rd(e[i].v), rd(e[i].w);
	sort(e + 1, e + m + 1);
	fu(i, 1, m) {
		if(e[i].w != e[i - 1].w) g.clear();
		if(!g.count(e[i].v)) g[e[i].v] = f[e[i].v];
		if(g.count(e[i].u)) ckmax(f[e[i].v], g[e[i].u] + 1);
		else ckmax(f[e[i].v], f[e[i].u] + 1);
	}
	cout << *max_element(f + 1, f + n + 1);
}