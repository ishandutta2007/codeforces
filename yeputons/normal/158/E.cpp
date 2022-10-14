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

const int DLEN = 86400;
const int INF = 1e9;

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n, k;
  while (scanf("%d%d", &n, &k) >= 1) {
    vi t(n), d(n);
    for (int i = 0; i < n; i++)
      scanf("%d%d", &t[i], &d[i]), t[i]--;

    vvi dyn(n + 1, vi(k + 1, INF));
    dyn[0][0] = 0;
    for (int i = 0; i < n; i++)
    for (int was = 0; was <= k; was++) {
      int st = max(t[i], dyn[i][was]);
      dyn[i + 1][was] = min(dyn[i + 1][was], st + d[i]);
      if (was < k)
        dyn[i + 1][was + 1] = min(dyn[i + 1][was + 1], dyn[i][was]);
    }

    int ans = 0;
    int ptr = 0;
    for (int st = 0; st < DLEN; st++) {
      while (ptr < n && t[ptr] < st) ptr++;

      for (int was = 0; was <= k; was++) if (dyn[ptr][was] <= st) {
        int rem = k - was;
        int en = DLEN;
        if (ptr + rem < n) en = t[ptr + rem];
        ans = max(ans, en - st);
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}