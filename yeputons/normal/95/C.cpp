#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>
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

const ll INF = 4e18;
int n;
vvi es, esw;

void dijkstra(int st, vector<ll> &d) {
  d = vector<ll>(n, INF);
  d[st] = 0;
  set<pair<ll, int> > ds;
  for (int i = 0; i < n; i++)
    ds.insert(mp(d[i], i));

  while (!ds.empty()) {
    ll mind = ds.begin()->first;
    int mini = ds.begin()->second;
    ds.erase(ds.begin());

    for (int i = 0; i < sz(es[mini]); i++) {
      int b = es[mini][i];
      ll w = esw[mini][i];
      if (d[b] > mind + w) {
        ds.erase(mp(d[b], b));
        d[b] = mind + w;
        ds.insert(mp(d[b], b));
      }
    }
  }
}

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int m, st, en;
  while (scanf("%d%d%d%d", &n, &m, &st, &en) >= 1) {
    st--, en--;

    es = vvi(n); esw = vvi(n);
    for (int i = 0; i < m; i++) {
      int a, b, w;
      scanf("%d%d%d", &a, &b, &w), a--, b--;
      es[a].pb(b); esw[a].pb(w);
      es[b].pb(a); esw[b].pb(w);
    }
    vector<ll> t(n), c(n);
    for (int i = 0; i < n; i++)
      scanf("%I64d%I64d", &t[i], &c[i]);

    vector<vector<ll> > mind(n);
    for (int i = 0; i < n; i++)
      dijkstra(i, mind[i]);

    vector<ll> pr(n, INF);
    pr[st] = 0;
    vb red(n, false);

    for (;;) {
      ll minpr = INF; int mini = -1;
      for (int i = 0; i < n; i++)
        if (!red[i] && pr[i] < minpr) {
          minpr = pr[i];
          mini = i;
        }
      if (mini < 0) break;

      red[mini] = true;
      for (int b = 0; b < n; b++) if (mind[mini][b] <= t[mini] && pr[b] > minpr + c[mini]) {
        pr[b] = minpr + c[mini];
      }
    }
    printf("%I64d\n", pr[en] < INF ? pr[en] : -1);

    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}