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

int p;
void madd(int &a, int b) {
  if ((a += b) >= p) a -= p;
}
int mmul(int a, int b) { return ll(a) * b % p; }
int mpow(int a, int b) {
  int res = 1;
  for (; b; b >>= 1, a = mmul(a, a))
    if (b & 1) res = mmul(res, a);
  return res;
}

bool isPrime() {
  for (int i = 2; i * i <= p; i++)
    if (p % i == 0) return false;
  return true;
}

vi ds;
bool isPrimitiveRoot(int x) {
  for (int i = 0; i < sz(ds); i++)
    if (mpow(x, ds[i]) == 1) return false;
  return true;
}
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int getMaxMod(int needMod, int maxVal) {
  int tmp = maxVal - maxVal % p;
  tmp += needMod;
  while (tmp >= maxVal) tmp -= p;
  return tmp;
}

int main() {
  #ifdef DEBUG
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
  #endif

  int n, x;
  while (scanf("%d%d", &n, &x) >= 1) {
    if (n == 1) {
      printf("%d\n", x - 1 > 1 ? x - 1 : -1);
      continue;
    }

    p = n + 1;
    if (!isPrime()) {
      printf("-1\n");
      continue;
    }

    {
      int tmp = n;
      for (int i = 2; i * i <= tmp; i++) if (tmp % i == 0) {
        ds.pb(n / i);
        while (tmp % i == 0) tmp /= i;
      }
      if (tmp > 1)
        ds.pb(n / tmp);
    }

    int cval = 1;
    while (!isPrimitiveRoot(cval))
      cval++;
    eprintf("p=%d, cval=%d\n", p, cval);

    int ans = -1;
    int cc = cval;
    for (int i = 1; i < p; i++) {
      if (gcd(i, n) == 1)
        ans = max(ans, getMaxMod(cc, x));
      cc = mmul(cc, cval);
    }
//    assert(cc == cval);
    printf("%d\n", ans);
  }
  return 0;
}