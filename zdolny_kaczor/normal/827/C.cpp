#include<bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define f first
#define s second
#define VI vector<int>
#define LL long long
#define MP make_pair
#define LD long double
#define PB push_back
#define PLL pair <LL, LL>
#define ALL(V) V.begin(),V.end()
#define abs(x) max((x),-(x))
#define PDD pair<LD,LD> 
#define VPII vector< PII > 
#define siz(V) ((int)V.size())
#define FOR(x, b, e)  for(int x=b;x<=(e);x++)
#define FORD(x, b, e) for(int x=b;x>=(e);x--)
#define REP(x, n)     for(int x=0;x<(n);x++)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#ifdef DEB
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#define cerr if(0) cerr
#endif
#define cc(x) x.f, x.s
const int MOD = 10;
const int MN = 1 << 17;
int trees[4][55][MN * 2];
void edit(int tree[MN * 2], int pos, int val) {
	debug("edit tree in %d by %d\n", pos, val);
	pos += MN;
	while (pos > 0) {
		tree[pos] += val;
		pos /= 2;
	}
}
int read(int tree[MN * 2], int l, int r, int wh = 1, int lb = 0, int rb = MN - 1) {
	if (wh == 1)
		debug("read [%d, %d]\n", l, r);
	if (l > rb || r < lb)
		return 0;
	if (l <= lb && r >= rb)
		return tree[wh];
	return read(tree, l, r, wh * 2, lb, (lb + rb) / 2) + read(tree, l, r, wh * 2 + 1, (lb + rb) / 2 + 1, rb);
}
int tree_nr(int mod, int pos) {
	return mod * (mod - 1) / 2 + pos % mod;
}
int nr(char c) {
	if (c == 'A')
		return 0;
	if (c == 'G')
		return 1;
	if (c == 'T')
		return 2;
	if (c == 'C')
		return 3;
	debug("c = %c\n", c);
	assert(false);
}
char in[MN];
void edit_gl(int i, int delta) {
	debug("edit gl %d %d char = %c\n", i, delta, in[i]);
	for (int m = 1; m <= MOD; ++m) {
		debug("edit tree %d %d in %d\n", nr(in[i]), tree_nr(m, i), i);
		edit(trees[nr(in[i])][tree_nr(m, i)], i, delta);
	}
}
int main() {
	scanf("%s", in + 1);
	int n = strlen(in + 1);
	for (int i = 1; i <= n; ++i)
		edit_gl(i, +1);
	debug("parsing starting done\n");
	int q;
	scanf("%d", &q);
	while (q--) {
		int t;
		scanf("%d", &t);
		if (t == 1) {
			char c;
			int i;
			scanf("%d %c", &i, &c);
			edit_gl(i, -1);
			in[i] = c;
			edit_gl(i, +1);
		}
		else {
			int l, r;
			char str[11];
			scanf("%d%d%s", &l, &r, str);
			int m = strlen(str);
			int ans = 0;
			for (int rem = 0; rem < m; ++rem) {
				debug("try tree %d %d\n", nr(str[rem]), tree_nr(m, l + rem));
				int x = read(trees[nr(str[rem])][tree_nr(m, l + rem)], l, r);
				debug("read %d\n", x);
				ans += x;
			}
			printf("%d\n", ans);
		}
	}
}