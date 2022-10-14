#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
#include <deque>
#include <map>
#include <set>

using namespace std;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

const ll INFLL = 9e18;

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n, m;
  while (scanf("%d%d", &n, &m) >= 1) {
    vvi es(n); vector<vll> esw(n + m);
    for (int i = 0; i < m; i++) {
      int a, b, w;
      scanf("%d%d%d", &a, &b, &w), a--, b--;
      es[a].pb(b); esw[a].pb(w);
      es[b].pb(a); esw[b].pb(w);
    }

    int k;
    scanf("%d", &k);

    vb isss(n, false);
    for (int i = 0; i < k; i++) {
      int x;
      scanf("%d", &x), x--, isss[x] = true;
    }

    int start0 = -1;
    ll ans0 = -1;
    {
      priority_queue<pair<ll, int> > q;
      q.push(mp(0LL, 0));
      vll ds(n, INFLL);
      ds[0] = 0;

      while (!q.empty()) {
        ll cd = -q.top().first;
        int v = q.top().second; q.pop();
        assert(ds[v] <= cd);
        if (ds[v] != cd) continue;
        if (isss[v]) { start0 = v; ans0 = ds[v]; break; }

        for (int i = 0; i < sz(es[v]); i++) {
          int b = es[v][i]; ll nd = cd + esw[v][i];
          if (nd < ds[b]) {
            ds[b] = nd;
            q.push(mp(-nd, b));
          }
        }
      }
    }

    vll ds(n, INFLL);
    vector<set<int> > ks(n);
    {
      priority_queue<pair<ll, int> > q;
      for (int i = 0; i < n; i++) if (isss[i]) {
        ds[i] = 0;
        ks[i].insert(i);
        q.push(mp(0LL, i));
      }

      while (!q.empty()) {
        ll cd = -q.top().first;
        int v = q.top().second; q.pop();
        assert(ds[v] <= cd);
        if (ds[v] != cd) continue;
        if (sz(ks[v]) > 1) continue;

        for (int i = 0; i < sz(es[v]); i++) {
          int b = es[v][i]; ll nd = cd + esw[v][i];
          if (nd < ds[b]) {
            ds[b] = nd;
            ks[b] = ks[v];
            q.push(mp(-nd, b));
          } else if (nd == ds[b]) {
            ks[b].insert(*ks[v].begin());
          }
        }
      }
    }

    vvi allNear(n);
    for (int i = 0; i < n; i++)
      for (set<int>::iterator it = ks[i].begin(); it != ks[i].end(); it++)
        allNear[*it].pb(i);

    priority_queue<pair<ll, int> > q;

    bool first = true;
    ll ans = 0;
    vb was(n, false);
    while (!q.empty() || first) {
      pair<ll, int> cadd(1, -1);
      if (first) cadd = mp(-ans0, start0);
      else {
        cadd = q.top();
        q.pop();
      }
      first = false;
      assert(cadd.second >= 0);
      int start = cadd.second;
      if (was[start]) continue;

      was[start] = true;
      ans += -cadd.first;

      for (int i = 0; i < sz(allNear[start]); i++) {
        int v = allNear[start][i];
        assert(ks[v].count(start));
        ks[v].erase(start);
      }

      for (int i = 0; i < sz(allNear[start]); i++) {
        int v = allNear[start][i];
        if (!ks[v].empty()) {
          q.push(mp(-2 * ds[v], *ks[v].begin()));
        }
        for (int i2 = 0; i2 < sz(es[v]); i2++) {
          int b = es[v][i2];
          if (ks[b].empty()) continue;

          ll nd = ds[v] + ds[b] + esw[v][i2];
          q.push(mp(-nd, *ks[b].begin()));
        }
      }
    }
    printf("%I64d\n", ans);
  }
  return 0;
}