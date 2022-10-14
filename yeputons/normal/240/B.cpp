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

const int MAXN = 210;
const int MAXV = 4e4 + 1e3;

void relax(int &a, int b) { a = min(a, b); }

int dyn[MAXN + 1][MAXV + 1][2];
const int INF = 0x7F7F7F7F;

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #else
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif

  int n, mr, mg;
  while (scanf("%d%d%d", &n, &mr, &mg) >= 1) {
    vi as(n);
    for (int i = 0; i < n; i++)
      scanf("%d", &as[i]);

    memset(dyn, 0x7F, sizeof dyn);
    dyn[0][0][0] = 0;
    dyn[0][0][1] = 0;

    int sum = 0;
    for (int i = 0; i < n; i++) {
      for (int wr = 0; wr <= mr; wr++)
      for (int prev = 0; prev < 2; prev++) {
        int val = dyn[i][wr][prev];
        if (val >= INF) continue;

        int wg = sum - wr;
        assert(wg >= 0);

        int remr = mr - wr;
        int remg = mg - wg;

        int bad = 0;
        if (i > 0)
          bad = min(as[i - 1], as[i]);

        if (remr >= as[i])
          relax(dyn[i + 1][wr + as[i]][0], val + (prev != 0) * bad);
        if (remg >= as[i])
          relax(dyn[i + 1][wr][1], val + (prev != 1) * bad);
      }
      sum += as[i];
    }
    int ans = INF;
    for (int i = 0; i <= mr; i++) {
      relax(ans, dyn[n][i][0]);
      relax(ans, dyn[n][i][1]);
    }
    if (ans >= INF) printf("-1\n");
    else printf("%d\n", ans);
  }
  return 0;
}