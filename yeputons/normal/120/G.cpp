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

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #else
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif

  int n, t;
  while (scanf("%d%d", &n, &t) >= 2) {
    vvi as(n, vi(2)), bs(n, vi(2));
    for (int i = 0; i < n; i++)
      for (int i2 = 0; i2 < 2; i2++)
        scanf("%d%d", &as[i][i2], &bs[i][i2]);

    int m;
    scanf("%d", &m);
    vector<string> ns(m); vi cs(m);
    for (int i = 0; i < m; i++) {
      char buf[30];
      scanf("%s%d", buf, &cs[i]);
      ns[i] = buf;
    }

    vector<vector<string> > res(n);

    vvi d(n, vi(m, 0));
    deque<int> dq;
    for (int i = 0; i < m; i++) dq.pb(i);

    int cur = 0, cpl = 0;
    while (!dq.empty()) {
      int curt = t;
      while (curt > 0 && !dq.empty()) {
        int card = dq.front(); dq.pop_front();
        int need = max(1, cs[card] - (as[cur][cpl] + bs[cur][!cpl]) - d[cur][card]);
        if (curt >= need) {
          curt -= need;
          res[cur].pb(ns[card]);
        } else {
          dq.pb(card);
          d[cur][card] += curt;
          curt = 0;
        }
      }

      if (++cur >= n) {
        cur = 0;
        cpl = !cpl;
      }
    }
    for (int i = 0; i < n; i++) {
      printf("%d", sz(res[i]));
      for (int i2 = 0; i2 < sz(res[i]); i2++)
        printf(" %s", res[i][i2].c_str());
      printf("\n");
    }
  }
  return 0;
}