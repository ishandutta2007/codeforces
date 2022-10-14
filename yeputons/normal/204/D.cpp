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

const int MOD = 1e9 + 7;
void madd(int &a, int b) { a += b; if (a >= MOD) a -= MOD; }
void msub(int &a, int b) { madd(a, MOD - b); }
int msum(int a, int b) { madd(a, b); return a; }
int mdiff(int a, int b) { madd(a, MOD - b); return a; }
int mmul(int a, int b) { return ll(a) * b % MOD; }

const int MAXL = 1e6 + 1e2;
char s[MAXL + 1];
int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n, k;
  while (scanf("%d%d%s", &n, &k, s) >= 1) {
    vvi dynAll(n + 1, vi(2));
    dynAll[0][0] = 1;
    for (int i = 0; i < n; i++) {
      int pcnt = msum(dynAll[i][0], dynAll[i][1]);
      if (s[i] != 'W') madd(dynAll[i + 1][0], pcnt);
      if (s[i] != 'B') madd(dynAll[i + 1][1], pcnt);
    }

    vvi dynB(n + 1, vi(2, 0));
    int pcnt = 0;
    for (int i = 0; i < n; i++) {
      int &valb = dynB[i + 1][0];
      int &valw = dynB[i + 1][1];

      if (s[i] != 'W') madd(valb, msum(dynB[i][0], dynB[i][1]));
      if (s[i] != 'B') madd(valw, msum(dynB[i][0], dynB[i][1]));

      pcnt += s[i] != 'W';
      if (i >= k)
        pcnt -= s[i - k] != 'W';

      int pr = i - k + 1;
      if (pr >= 0 && pcnt == k) {
        if (pr == 0) madd(valb, 1);
        else
          madd(valb, mdiff(dynAll[pr][1], dynB[pr][1]));
      }

/*      {
        int rval = 0;
        for (int m = 0; m < (1 << (i + 1)); m++) {
          bool g = true;
          bool g2 = false;

          int clen = 0;
          for (int i2 = 0; i2 <= i; i2++) {
            char bc = "BW"[!!(m & (1 << i2))];
            if (s[i2] == bc) { g = false; break; }

            if (m & (1 << i2)) {
              clen++;
            } else
              clen = 0;
            if (clen >= k) g2 = true;
          }
          if (!g) continue;
          if (!g2) continue;
          rval++;
        }
        assert(rval ==valb + valw);
      }*/
    }

    vvi dynBW(n + 1, vi(2));
    pcnt = 0;
    for (int i = 0; i < n; i++) {
      int &valb = dynBW[i + 1][0];
      int &valw = dynBW[i + 1][1];
      if (s[i] != 'W') madd(valb, msum(dynBW[i][0], dynBW[i][1]));
      if (s[i] != 'B') madd(valw, msum(dynBW[i][0], dynBW[i][1]));

      pcnt += s[i] != 'B';
      if (i >= k)
        pcnt -= s[i - k] != 'B';

      int pr = i - k + 1;
      if (pr >= 0 && pcnt == k)
        madd(valw, mdiff(dynB[pr][0], dynBW[pr][0]));

/*      {
        int rval = 0;
        for (int m = 0; m < (1 << (i + 1)); m++) {
          bool g = true;
          int g2 = 1e9;

          int clen = 0;
          int clen2 = 0;
          for (int i2 = 0; i2 <= i; i2++) {
            char bc = "BW"[!!(m & (1 << i2))];
            if (s[i2] == bc) { g = false; break; }

            if (clen < k) {
              if (m & (1 << i2))
                clen++;
              else
                clen = 0;
            }

            if (clen >= k) {
              if (m & (1 << i2))
                clen2 = 0;
              else
                clen2++;
              if (clen2 >= k) g2 = min(g2, i2 + 1);
            }
          }
          if (!g) continue;
          if (g2 >= 1e9) continue;
          rval++;
        }
        eprintf("%d\n", rval);
        assert(rval ==valb + valw);
      }*/
    }
    printf("%d\n", msum(dynBW[n][0], dynBW[n][1]));
  }
  return 0;
}