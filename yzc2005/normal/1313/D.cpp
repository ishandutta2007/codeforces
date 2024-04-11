#include <bits/stdc++.h>
using namespace std;
#define fu(i, a, b) for(int i = a; i <= b; ++i)
#define mem(a, x) memset(a, x, sizeof(a));
inline void rd(int &x) {
    x = 0; char ch = getchar();
    while(!isdigit(ch)) ch = getchar();
    while(isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
}

const int N = 100005, K = 8;
int n, m, k, l[N], r[N], tmp[N << 1];
int f[N << 1][1 << K], par[1 << K], mx[1 << K], pos[N], t, cur, bel[N << 1][K], sz[N << 1];

void dfs(int p, int m1, int m2) {
	if(p == sz[cur]) {
		mx[m2] = max(mx[m2], f[cur][m1]);
		return;
	}
	if(pos[bel[cur][p]] != -1) {
		t |= 1 << pos[bel[cur][p]];
		dfs(p + 1, m1 | 1 << p, m2 | 1 << pos[bel[cur][p]]);
	} else {
		dfs(p + 1, m1 | 1 << p, m2);
	}
	dfs(p + 1, m1, m2);
}

int main() {
    rd(n), rd(m), rd(k);
    fu(i, 1, n) rd(l[i]), rd(r[i]), tmp[(i << 1) - 1] = l[i], tmp[i << 1] = ++r[i];
    sort(tmp + 1, tmp + (n << 1) + 1), m = unique(tmp + 1, tmp + (n << 1) + 1) - tmp - 1;
    fu(i, 1, n) l[i] = lower_bound(tmp + 1, tmp + m + 1, l[i]) - tmp, r[i] = lower_bound(tmp + 1, tmp + m + 1, r[i]) - tmp;
    fu(i, 1, n) fu(j, l[i], r[i] - 1) bel[j][sz[j]++] = i;
    fu(i, 0, (1 << k) - 1) par[i] = __builtin_parity(i); 
    mem(pos, -1); 
    f[0][0] = 0;
    fu(i, 1, m - 1) {
    	fu(j, 0, sz[i] - 1) pos[bel[i][j]] = j;
    	mem(mx, -0x3f); t = 0, cur = i - 1, dfs(0, 0, 0);
    	fu(s, 0, (1 << sz[i]) - 1) f[i][s] = mx[s & t] + par[s] * (tmp[i + 1] - tmp[i]);
    	fu(j, 0, sz[i] - 1) pos[bel[i][j]] = -1;
	}
	printf("%d\n", *max_element(f[m - 1], f[m - 1] + (1 << k)));
	return 0;
}