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
int mmul(int a, int b) { return ll(a) * b % MOD; }
int mpow(int a, ll b) {
  int res = 1;
  for (; b; b >>= 1, a = mmul(a, a))
    if (b & 1)
      res = mmul(res, a);
  return res;
}

const int MAXN = 110;
int C[MAXN + 1][MAXN + 1];

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  memset(C, 0, sizeof C);
  for (int n = 0; n <= MAXN; n++) {
    C[n][0] = C[n][n] = 1;
    for (int k = 1; k < n; k++) {
      C[n][k] = C[n - 1][k - 1];
      madd(C[n][k], C[n - 1][k]);
    }
  }

  int n, k; ll m;
  while (scanf("%d%I64d%d", &n, &m, &k) >= 1) {
    vll degs(n);
    for (int i = 0; i < n; i++)
      degs[i] = m / n + (i < (m % n));

    vvi dyn(n + 1, vi(k + 1, 0));
    dyn[0][k] = 1;
    for (int i = 0; i < n; i++) {
      for (int cur = 0; cur <= n; cur++) {
        int ck = mpow(C[n][cur], degs[i]);

        for (int rem = k; rem >= cur; rem--) {
          int ncnt = mmul(dyn[i][rem], ck);
          madd(dyn[i + 1][rem - cur], ncnt);
        }
      }
    }
    printf("%d\n", dyn[n][0]);
  }
  return 0;
}