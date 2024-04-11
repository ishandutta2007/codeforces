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

const int MAXN = 1e6 + 100;
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

  int n;
  while (scanf("%d", &n) >= 1) {
    facs[0] = ifacs[0] = 1;
    for (int i = 1; i <= n + 50; i++) {
      facs[i] = mmul(facs[i - 1], i);
      ifacs[i] = mmul(ifacs[i - 1], minv(i));
    }

    int a = 0, b = 0;
    for (int i = 0; i < n; i++) {
      int t;
      scanf("%d", &t);
      a += t == 1;
      b += t == 2;
    }

/*    vvi tmp(n + 1, vi(n + 1, 0));
    tmp[0][0] = 1;
    for (int sum = 1; sum <= n; sum++)
    for (int k = 0; k <= sum; k++) {
      tmp[sum][k] = tmp[sum - 1][k];
      if (k > 0 && sum >= 2)
        madd(tmp[sum][k], tmp[sum - 2][k - 1]);
    }*/

    int ans = 0;
    for (int c2a = 0; c2a * 2 <= a; c2a++) {
      int grcnt = a - c2a;
      int cans = C(grcnt, c2a);
      cans = mmul(cans, ifacs[grcnt]);
      cans = mmul(cans, mpow(2, MOD - 1 - c2a));
      madd(ans, cans);
    }
    ans = mmul(ans, facs[n]);
    printf("%d\n", ans);
  }
  return 0;
}