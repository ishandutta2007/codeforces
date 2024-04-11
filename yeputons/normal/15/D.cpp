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

const int INF = 1e9 + 1e3;

class MyQueue {
  deque<int> q;
  public:
  MyQueue() {}
  void insert(int x) {
    while (!q.empty() && q.back() > x)
      q.pop_back();
    q.pb(x);
  }
  void erase(int x) {
    assert(!q.empty());
    if (q.front() == x) q.pop_front();
  }
  int getMin() { assert(!q.empty()); return q.front(); }
};

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int h, w, h1, w1;
  while (scanf("%d%d%d%d", &h, &w, &h1, &w1) >= 1) {
    vvi f(h, vi(w));
    for (int y = 0; y < h; y++)
    for (int x = 0; x < w; x++)
      scanf("%d", &f[y][x]);

    vector<vll> sums(h + 1, vll(w + 1));
    for (int y = 0; y < h; y++)
    for (int x = 0; x < w; x++)
      sums[y + 1][x + 1] = sums[y + 1][x] + sums[y][x + 1] - sums[y][x] + f[y][x];

    vector<MyQueue> vs(w);
    for (int y = 0; y < h1; y++)
    for (int x = 0; x < w; x++)
      vs[x].insert(f[y][x]);

    vector<pair<ll, pii> > gs;
    for (int y = 0; y + h1 <= h; y++) {
			MyQueue cur;
      for (int x = 0; x < w1; x++)
        cur.insert(vs[x].getMin());

      for (int x = 0; x + w1 <= w; x++) {
        ll cans = sums[y + h1][x + w1] - sums[y][x + w1] - sums[y + h1][x] + sums[y][x];
        cans -= ll(cur.getMin()) * h1 * w1;
        gs.pb(mp(cans, mp(y, x)));

        cur.erase(vs[x].getMin());
        if (x + w1 < w)
          cur.insert(vs[x + w1].getMin());
      }

      for (int x = 0; x < w; x++)
        vs[x].erase(f[y][x]);
      if (y + h1 < h)
        for (int x = 0; x < w; x++)
          vs[x].insert(f[y + h1][x]);
    }
    sort(gs.begin(), gs.end());

    vvb was(h, vb(w, false));
    vector<pair<ll, pii> > res;
    for (int i = 0; i < sz(gs); i++) {
      int y = gs[i].second.first;
      int x = gs[i].second.second;
      if (was[y][x]) continue;
      res.pb(gs[i]);

      for (int dy = -h1 + 1; dy < h1; dy++)
      for (int dx = -w1 + 1; dx < w1; dx++) {
        int ny = y + dy;
        int nx = x + dx;
        if (nx < 0 || ny < 0 || nx >= w || ny >= h) continue;
        was[ny][nx] = true;
      }
    }

    printf("%d\n", sz(res));
    for (int i = 0; i < sz(res); i++)
      printf("%d %d %I64d\n", res[i].second.first + 1, res[i].second.second + 1, res[i].first);
  }
  return 0;
}