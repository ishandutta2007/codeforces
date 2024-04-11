#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>

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

vvi es;
vb was;
vi vs[2];

void dfs(int v, int cd = 0) {
  if (was[v]) return;
  was[v] = true;
  vs[cd].pb(v);
  for (int i = 0; i < sz(es[v]); i++)
    dfs(es[v][i], !cd);
}

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n, m;
  while (scanf("%d%d", &n, &m) >= 1) {
    es = vvi(n);
    for (int i = 0; i < m; i++) {
      int a, b;
      scanf("%d%d", &a, &b), a--, b--;
      es[a].pb(b);
      es[b].pb(a);
    }

    assert(n % 3 == 0);

    vs[0].clear();
    vs[1].clear();
    was = vb(n, false);
    for (int i = 0; i < n; i++) if (!was[i])
      dfs(i);

    if (sz(vs[0]) % 3 > sz(vs[1]) % 3)
      vs[0].swap(vs[1]);

    sort(vs[0].begin(), vs[0].end());
    sort(vs[1].begin(), vs[1].end());

    vi ans(n, -1);
    int cur = 0;
    if (sz(vs[0]) % 3 != 0) {
      assert(sz(vs[0]) % 3 == 1);
      assert(sz(vs[1]) % 3 == 2);

      int n1 = sz(vs[0]), n2 = sz(vs[1]);
      bool g = false;

      for (int i = 0; i < sz(vs[0]); i++) {
        int b = vs[0][i];
        if (sz(es[b]) <= n2 - 2) {
          eprintf("Good!\n");

          vb was(n, false);
          for (int i2 = 0; i2 < sz(es[b]); i2++)
            was[es[b][i2]] = true;

          vi all;
          all.pb(b);
          for (int i2 = 0; i2 < sz(vs[1]) && sz(all) < 3; i2++)
            if (!was[vs[1][i2]]) all.pb(vs[1][i2]);
          assert(sz(all) == 3);
          for (int i2 = 0; i2 < sz(all); i2++)
            ans[all[i2]] = cur;
          cur++;

          g = true;
          break;
        }
      }

      if (!g) {
        vi nid(n, -1);
        for (int i = 0; i < sz(vs[1]); i++)
          nid[vs[1][i]] = i;

        vvi pairs(n2);
        vb was(n2, false);
        for (int i = 0; i < sz(vs[0]); i++) {
          int b = vs[0][i];

          fill(was.begin(), was.end(), false);
          for (int i2 = 0; i2 < sz(es[b]); i2++) {
            int c = es[b][i2];
            assert(nid[c] >= 0);
            was[nid[c]] = true;
          }
          for (int i2 = 0; i2 < n2; i2++) if (!was[i2])
            pairs[i2].pb(b);
        }

        vi bs;
        for (int i = 0; i < n2 && sz(bs) < 2; i++) if (sz(pairs[i]) >= 2) {
          bs.pb(i);
        }
        if (sz(bs) >= 2) {
          for (int i = 0; i < sz(bs); i++) {
            int b = bs[i];
            vi all;
            all.pb(vs[1][b]);
            for (int i2 = 0; i2 < sz(pairs[b]) && i2 < 2; i2++)
              all.pb(pairs[b][i2]);

            for (int i2 = 0; i2 < sz(all); i2++)
              ans[all[i2]] = cur;
            cur++;
          }
          eprintf("OK\n");
        }
      }
    }

    for (int step = 0; step < 2; step++) {
      vi all;
      for (int i = 0; i < sz(vs[step]); i++) {
        if (ans[vs[step][i]] < 0) {
          all.pb(vs[step][i]);
        }
        if (sz(all) == 3) {
          for (int i = 0; i < sz(all); i++)
            ans[all[i]] = cur;
          cur++;
          all.clear();
        }
      }
    }

    bool g = true;
    for (int i = 0; i < n; i++) g = g && ans[i] >= 0;
    if (!g) printf("NO\n");
    else {
      printf("YES\n");
      for (int i = 0; i < n; i++)
        printf("%d%c", ans[i] + 1, "\n "[i + 1 < n]);
    }
    break;
  }
  return 0;
}