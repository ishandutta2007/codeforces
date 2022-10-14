#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <list>
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
void madd(int &a, int b) { if ((a += b) >= MOD) a -= MOD; }
int mmul(int a, int b) { return ll(a) * b % MOD; }
int mpow(int a, int b) {
  int res = 1;
  for (; b; b >>= 1, a = mmul(a, a))
    if (b & 1) res = mmul(res, a);
  return res;
}
int minv(int a) {
  assert(0 < a && a < MOD);
  return mpow(a, MOD - 2);
}

const int MAXN = 510;
int facs[MAXN + 1];
int ifacs[MAXN + 1];

int C(int n, int k) {
  assert(0 <= k && k <= n && n <= MAXN);
  return mmul(facs[n], mmul(ifacs[k], ifacs[n - k]));
}

int main() {
  #ifdef DEBUG
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
  #endif

  facs[0] = ifacs[0] = 1;
  for (int i = 1; i <= MAXN; i++) {
    facs[i] = mmul(facs[i - 1], i);
    ifacs[i] = mmul(ifacs[i - 1], minv(i));
  }

  int n;
  while (scanf("%d", &n) >= 1) {
    int a = 0, b = 0;
    for (int i = 0; i < n; i++) {
      int t;
      scanf("%d", &t);
      a += t == 1;
      b += t == 2;
    }

    vvi dyn(a + 1, vi(b + 1, 0));
    dyn[0][0] = 1;
    for (int i = 1; i <= b; i++)
      dyn[0][i] = mmul(dyn[0][i - 1], i);

    for (int ca = 1; ca <= a; ca++)
    for (int cb = 0; cb <= b; cb++) {
      for (int sela = 1; sela <= ca && sela <= 2; sela++)
      for (int selb = 0; selb <= cb; selb++) {
        int cans = dyn[ca - sela][cb - selb];
        cans = mmul(cans, C(ca - 1, sela - 1));
        cans = mmul(cans, C(cb, selb));
        cans = mmul(cans, facs[sela + selb - 1]);
        madd(dyn[ca][cb], cans);
      }
    }
    printf("%d\n", dyn[a][b]);
  }
  return 0;
}