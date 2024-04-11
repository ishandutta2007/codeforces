#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>

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

const int INF = 1e9;
class Solver {
  int n;
  vvi es;

  public:
  Solver(int _n) : n(_n), es(n) {}
  void adde(int a, int b) {
    es[a].pb(b);
    es[b].pb(a);
  }
  int solve(int st, int en) {
    vi d(n, INF);
    deque<int> q;

    d[st] = 0;
    q.pb(st);
    while (!q.empty()) {
      int v = q.front();
      q.pop_front();
      for (int i = 0; i < sz(es[v]); i++) {
        int b = es[v][i];
        if (d[b] <= d[v] + 1) continue;
        d[b] = d[v] + 1;
        q.pb(b);
      }
    }
    return d[en];
  }
};

char buf[1011];

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int h, w;
  while (scanf("%d%d", &h, &w) >= 1) {
    Solver s(w + h);
    for (int y = 0; y < h; y++) {
      scanf("%s", buf);
      for (int x = 0; x < w; x++) if (buf[x] == '#') {
        s.adde(x, w + y);
      }
    }
    int ans = s.solve(w, w + h - 1);
    printf("%d\n", ans == INF ? -1 : ans);
  }
  return 0;
}