#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <cstdarg>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <vector>
#include <deque>
#include <string>

using namespace std;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

int n;
vi val;
vi l, r;

vi ls, lvals, lh;
vi lb, mb, rb;

void dfs(int v, int h) {
  if (l[v] < 0 || r[v] < 0) { lvals.pb(val[v]); lh.pb(h); return; }

  lb[v] = sz(ls) - 1;
  dfs(l[v], h + 1);

  mb[v] = sz(ls);
  ls.pb(val[v]);
  
  dfs(r[v], h + 1);
  rb[v] = sz(ls);
}

vector<pii> evs;
void dfs2(int v) {
  if (l[v] < 0 || r[v] < 0) return;
  evs.pb(mp(lb[v], lvals[mb[v]]));
  evs.pb(mp(mb[v], -lvals[mb[v]]));
  evs.pb(mp(mb[v], lvals[mb[v] - 1]));
  evs.pb(mp(rb[v], -lvals[mb[v] - 1]));
  eprintf("add(%d..%d; %d)\n", lb[v], mb[v] - 1, lvals[mb[v]]);
  eprintf("add(%d..%d; %d)\n", mb[v], rb[v] - 1, lvals[mb[v] - 1]);

  dfs2(l[v]);
  dfs2(r[v]);
}

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif
  
  while (scanf("%d", &n) >= 1) {
    val = vi(n);
    int root = 0;

    {
      vi p(n);
      for (int i = 0; i < n; i++) {
        scanf("%d%d", &p[i], &val[i]), p[i]--;
        if (p[i] < 0)
          root = i;
      }

      l = vi(n, -1);
      r = vi(n, -1);
      for (int i = 0; i < n; i++) if (p[i] >= 0) {
        if (val[i] < val[p[i]]) l[p[i]] = i;
        else r[p[i]] = i;
      }
    }

    ls = vi(1, 0);
    lvals.clear();
    lh.clear();
    lb = vi(n, -1);
    mb = vi(n, -1);
    rb = vi(n, -1);
    dfs(root, 0);
    evs.clear();
    dfs2(root);

    vector<ll> sums(sz(ls), 0);
    sort(evs.begin(), evs.end());
    int p = 0;
    ll csum = 0;
    for (int i = 0; i < sz(ls); i++) {
      while (p < sz(evs) && evs[p].first <= i)
        csum += (ll)evs[p++].second;
      sums[i] = csum;
    }

    for (int i = 0; i < sz(ls); i++)
      eprintf("%d%c", ls[i], "\n\t"[i + 1 < sz(ls)]);
    for (int i = 0; i < sz(ls); i++)
      eprintf("%I64d%c", sums[i], "\n\t"[i + 1 < sz(ls)]);

    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
      int cur;
      scanf("%d", &cur);
      int id = lower_bound(ls.begin(), ls.end(), cur) - ls.begin() - 1;
      printf("%.18lf\n", (double)sums[id] / lh[id]);
    }
  
    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}