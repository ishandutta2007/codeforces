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
const bool deb = 
#ifdef DEB
true;
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define debug2(...) cerr << __VA_ARGS__
#else
false;
#define debug(...)
#define debug2(...)
#endif
const int MN = 1e5 + 44;
VI graf[MN];
int size[MN];
int top[MN];
int in[MN], out[MN];
int parent[MN];
int nr_in_dec[MN];
const int SIZE = deb ? 1 << 4 : 1 << 17;
int tree[SIZE * 2];
int blocked[SIZE * 2];
int n, k;
void add(int l, int r, int val, int wh = 1, int lb = 0, int rb = SIZE - 1) {
  if (wh == 1) debug("l = %d r = %d val = %d\n", l, r, val);
	if (l > rb || r < lb)
		return;
	if (l <= lb && r >= rb) {
		blocked[wh] += val;
	}
	else {
		add(l, r, val, wh * 2, lb, (lb + rb) / 2);
		add(l, r, val, wh * 2 + 1, (lb + rb) / 2 + 1, rb);
	}
	if (blocked[wh])
		tree[wh] = 0;
	else if (wh > SIZE) {
    tree[wh] = wh < SIZE + n;
	}
	else
		tree[wh] = tree[wh * 2] + tree[wh * 2 + 1];
  if (wh == 1 && deb) {
    REP(i, SIZE * 2)
      debug("%d: blocked=%d, tree=%d\n", i, blocked[i], tree[i]);
  }
}
bool under(int a, int b) {
  return in[a] >= in[b] && out[a] <= out[b];
}
void dfs(int x, int y = 0) {
  static int timer = 1;
  in[x] = timer++;
  size[x] = 1;
  parent[x] = y;
  for (auto v : graf[x])
    if (v != y) {
      dfs(v, x);
      size[x] += size[v];
    }
  out[x] = timer++;
}
void dfs2(int x) {
  debug("dfs2(%d)\n", x);
  static int num = 0;
  VI other;
  int wh = x;
  nr_in_dec[x] = num++;
  top[x] = x;
  while (true) {
    PII best = MP(0, 0);
    for (auto v : graf[wh])
      if (v != parent[wh])
        maxi(best, MP(size[v], v));
    if (best.f == 0) break;
    for (auto v : graf[wh])
      if (v != best.s && v != parent[wh])
        other.PB(v);
    nr_in_dec[best.s] = num++;
    top[best.s] = x;
    wh = best.s;
  }
  for (auto c : other)
    dfs2(c);
}
void add_path(int a, int b, int val) {
  debug("add path %d - %d val=%d\n", a, b, val);
  REP(_, 2) {
    while (true) {
      int aa = top[a];
      if (under(b, aa))
        break;
      else {
        add(nr_in_dec[aa], nr_in_dec[a], val);
        a = parent[aa];
      }
    }
    swap(a, b);
  }
  if (nr_in_dec[a] > nr_in_dec[b])
    swap(a, b);
  add(nr_in_dec[a], nr_in_dec[b], val);
}
void padd(int a, int b) {
	add_path(a, b, +1);
}
void prem(int a, int b) {
	add_path(a, b, -1);
}
int ile() {
  debug("ile = %d\n", tree[1]);
	return n - tree[1];
}
int main() {
	scanf("%d%d", &n, &k);
	REP(i, n - 1) {
		int a, b;
		scanf("%d%d", &a, &b);
		graf[a].PB(b);
		graf[b].PB(a);
	}
  REP(i, SIZE)
    tree[i + SIZE] = i < n;
  FORD(i, SIZE - 1, 1)
    tree[i] = tree[i * 2] + tree[i * 2 + 1];
	dfs(1);
	dfs2(1);
  FOR(i, 1, n)
    debug("%d: top=%d; nr_id=%d; parent=%d\n", i, top[i], nr_in_dec[i], parent[i]);
	int res = 0;
	int head = 1, tail = 1;
	//in struct paths on [tail, head] are included
	while (head < n) {
		debug("%d - %d with count = %d\n", tail, head, ile());
		if (ile() <= k) {
			debug("include %d\n", head - tail + 1);
			maxi(res, head - tail + 1);
			padd(head, head + 1);
			head++;
		}
		else {
			prem(tail, tail + 1);
			tail++;
		}
	}
	debug("include %d - %d with %d\n", tail, head, ile());
	if (ile() <= k) {
		maxi(res, head - tail + 1);
	}
	printf("%d\n", res);
}