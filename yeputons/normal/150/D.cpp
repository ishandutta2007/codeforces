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

const int MAXL = 150;
char s[MAXL + 1];

int d[MAXL][MAXL][MAXL + 1];
int d2[MAXL][MAXL];

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n;
  while (scanf("%d", &n) >= 1) {
    vi ws(n + 1);
    ws[0] = 0;
    for (int i = 1; i <= n; i++)
      scanf("%d", &ws[i]);
    scanf("%s", s);

    memset(d, 0xC0, sizeof d);
    for (int len = 1; len <= n; len++)
    for (int l = 0; l + len <= n; l++) {
      int r = l + len - 1;
      for (int rem = 0; rem < n; rem++) {
        int &res = d[l][r][rem];

        if (rem > 0 && ws[rem] >= 0)
          res = max(res, d[l][r][0] + ws[rem]);

        if (len == 1) {
          if (ws[rem + 1] >= 0)
            res = max(res, ws[rem + 1]);
          continue;
        }

        if (s[l] == s[r]) {
          if (len == 2 && rem + 2 <= n && ws[rem + 2] >= 0) {
            res = max(res, ws[rem + 2]);
          }
          if (len > 2 && rem + 2 < n)
            res = max(res, d[l + 1][r - 1][rem + 2]);
        }

        for (int spl = l + 1; spl <= r; spl++) {
          res = max(res, d[l][spl - 1][rem] + d[spl][r][0]);
          res = max(res, d[l][spl - 1][0] + d[spl][r][rem]);
        }
      }
    }

    memset(d2, 0, sizeof d2);
    for (int len = 1; len <= n; len++)
    for (int l = 0; l + len <= n; l++) {
      int r = l + len - 1;
      int &res = d2[l][r];
      res = max(res, d[l][r][0]);

      for (int spl = l + 1; spl <= r; spl++)
        res = max(res, d2[l][spl - 1] + d2[spl][r]);
    }
    printf("%d\n",  d2[0][n - 1]);
  }
  return 0;
}