#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
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

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif
  
  int n, m;
  while (scanf("%d%d", &n, &m) >= 1) {
    vi tys(n);
    for (int i = 0; i < n; i++)
      scanf("%d", &tys[i]);

    vvi es(n), rves(n);
    for (int i = 0; i < m; i++) {
      int a, b;
      scanf("%d%d", &a, &b), a--, b--;
      es[a].pb(b);
      rves[b].pb(a);
    }

    vb was1(n);
    deque<int> q;
    for (int i = 0; i < n; i++) if (tys[i] == 1) {
      was1[i] = true;
      q.pb(i);
    }
    while (!q.empty()) {
      int v = q.front();
      q.pop_front();

      for (int i = 0; i < sz(es[v]); i++) {
        int b = es[v][i];
        if (tys[b] == 1) continue;
        if (was1[b]) continue;
        was1[b] = true;
        q.pb(b);
      }
    }

    vb was2(n);
    for (int i = 0; i < n; i++) if (tys[i] == 2) {
      was2[i] = true;
      q.pb(i);
    }
    while (!q.empty()) {
      int v = q.front();
      q.pop_front();

      for (int i = 0; i < sz(rves[v]); i++) {
        int b = rves[v][i];
        if (tys[b] == 1) continue;
        if (was2[b]) continue;
        was2[b] = true;
        q.pb(b);
      }
    }

    vb res(n);
    for (int i = 0; i < n; i++) if (was1[i]) {
      bool g = was2[i];
      for (int i2 = 0; i2 < sz(es[i]); i2++) {
        int b = es[i][i2];
        if (was2[b]) g = true;
      }
      res[i] = g;
    }
    for (int i = 0; i < n; i++)
      printf("%d\n", !!res[i]);
    #ifdef DEBUG
    printf("\n");
    #endif
  }
  return 0;
}