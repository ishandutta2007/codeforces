#define _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")

#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int n, x, y, hd[N], to[N << 1], nxt[N << 1], cnt, ans[N], f[N], g[N];

void dfs(int u, int fa, int len) {
	f[u] = 0, g[u] = 1; int mx = 1;
	for(int i = hd[u], v = to[i]; i; i = nxt[i], v = to[i]) {
		if(v == fa) continue;
		dfs(v, u, len);
		f[u] += f[v];
		mx = max(mx, g[u] + g[v]);
		g[u] = max(g[u], g[v] + 1);
	}
	if(mx >= len) ++f[u], g[u] = 0;
}

void solve(int l, int r, int lv, int rv) {
	if(l > r) return;
	if(lv == rv) {
		for(int i = l; i <= r; ++i) ans[i] = lv;
		return;
	}
	int mid = l + r >> 1;
	dfs(1, 0, mid), ans[mid] = f[1];
	solve(l, mid - 1, ans[mid], rv);
	solve(mid + 1, r, lv, ans[mid]);
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i < n; ++i) {
		scanf("%d%d", &x, &y);
		to[++cnt] = y, nxt[cnt] = hd[x], hd[x] = cnt;
		to[++cnt] = x, nxt[cnt] = hd[y], hd[y] = cnt;
	}
	solve(1, n, 0, n);
	for(int i = 1; i <= n; ++i) printf("%d\n", ans[i]);
	return 0;
}