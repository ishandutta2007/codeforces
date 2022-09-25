#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int maxn = 2005;

struct State {
  int pos;
  int m[4];

  State() : pos(1) {
    for (int i = 0; i < 4; ++i) {
      m[i] = 0;
    }
  }

  void norm() {
    sort(m, m + 4);
  }
};

int _d[2][10][10][10][10][10];
vector<pair<State, int>> _g[10][10][10][10][10];

int& d(int q, const State& s) {
  return _d[q][s.pos][s.m[0]][s.m[1]][s.m[2]][s.m[3]];
}

vector<pair<State, int>>& g(const State& s) {
  return _g[s.pos][s.m[0]][s.m[1]][s.m[2]][s.m[3]];
}

signed main() {
#ifdef LOCAL
  assert(freopen("c.in", "r", stdin));
#endif
  State s;
  int num = 0;
  for (s.pos = 1; s.pos <= 9; ++s.pos) {
    for (s.m[0] = 0; s.m[0] <= 9; ++s.m[0]) {
      for (s.m[1] = s.m[0]; s.m[1] <= 9; ++s.m[1]) {
        for (s.m[2] = s.m[1]; s.m[2] <= 9; ++s.m[2]) {
          for (s.m[3] = s.m[2]; s.m[3] <= 9; ++s.m[3]) {
            ++num;
            for (int mid = 1; mid <= 9; ++mid) {
              for (int to = 1; to <= 9; ++to) {
                int L = min(mid, to), R = max(mid, to);
                State t;
                t.pos = to;
                for (int i = 0; i < 4; ++i) {
                  if (s.m[i] < L || s.m[i] > R) {
                    t.m[i] = s.m[i];
                  }
                }
                t.norm();
                if (t.m[0] != 0) {
                  continue;
                }
                g(t).emplace_back(s, abs(mid - to) + abs(mid - s.pos));
              }
            }
          }
        }
      }
    }
  }
  cerr << "states: " << num << '\n';

  memset(_d, 127, sizeof(_d));

  State start;
  int q = 0;
  d(q, start) = 0;
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i, q ^= 1) {
    memset(_d[q ^ 1], 127, sizeof(_d[q ^ 1]));

    int a, b;
    cin >> a >> b;

    s.pos = a;
    s.m[0] = 0;
    for (s.m[1] = s.m[0]; s.m[1] <= 9; ++s.m[1]) {
      for (s.m[2] = s.m[1]; s.m[2] <= 9; ++s.m[2]) {
        for (s.m[3] = s.m[2]; s.m[3] <= 9; ++s.m[3]) {
          auto& es = g(s);
          State s2 = s;
          s2.m[0] = b;
          s2.norm();
          for (auto p : es) {
            auto from = p.first;
            int dist = d(q, from) + p.second;
            auto& res = d(q ^ 1, s2);
            res = min(res, dist);
          }
        }
      }
    }
  }
  State finish;
  int res = 1e9;
  for (finish.pos = 1; finish.pos <= 9; ++finish.pos) {
    for (auto p : g(finish)) {
      auto from = p.first;
      int dist = d(q, from) + p.second;
      res = min(res, dist);
    }
  }
  res += 2 * n;
  cout << res << '\n';
}