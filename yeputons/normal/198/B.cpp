#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <queue>
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

const int INF = 1e9;
const int MAXN = 1e5 + 1e2;
char s[2][MAXN + 1];

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n, k;
  while (scanf("%d%d%s%s", &n, &k, s[0], s[1]) >= 1) {
    vvi d(2, vi(n, INF));
    d[0][0] = 0;

    deque<pii> q;
    q.pb(mp(0, 0));
    bool good = false;

    while (!q.empty()) {
      int t = q.front().first;
      int x = q.front().second;
      int cd = d[t][x];
      q.pop_front();

      pii cs[3] = { mp(t, x - 1), mp(t, x + 1), mp(!t, x + k) };
      int nd = cd + 1;
      for (int i = 0; i < 3; i++) {
        int nt = cs[i].first;
        int nx = cs[i].second;
        if (nx < 0 || nx < nd) continue;
        if (nx >= n) { good = true; goto end; }
        assert(0 <= nx && nx < n);
        if (s[nt][nx] == 'X') continue;
        if (nd >= d[nt][nx]) continue;
        d[nt][nx] = nd;
        q.pb(mp(nt, nx));
      }
    }
    end:;
    printf(good ? "YES\n" : "NO\n");
  }
  return 0;
}