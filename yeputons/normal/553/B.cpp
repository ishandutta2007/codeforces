#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>

using namespace std;

#define pb push_back
#define mp make_pair
#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...)
#endif
#define sz(x) ((int)(x).size())
#define forn(i, n) for (int i = 0; i < (n); i++)

#ifdef DEBUG
struct Timestamper {
  string msg;
  clock_t start;

  Timestamper(const string &_msg) : msg(_msg), start(clock()) {}
  ~Timestamper() {
    eprintf("[ %s ] Time=%.3lfs\n", msg.c_str(), (clock() - start) * 1.0 / CLOCKS_PER_SEC);
  }
} __timestamper("end");
#else
struct Timestamper {};
#endif

typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pll;

const ll INFLL = ll(2e18);
void madd(ll &a, ll b) {
  a = min(a + b, INFLL);
}

int main() {
  #ifdef DEBUG
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
  #endif

  int n;
  ll k;
  while (scanf("%d%I64d", &n, &k) == 2) {
    vector<ll> dyn(n + 1, 0);
    dyn[0] = 1;
    dyn[1] = 1;
    for (int i = 2; i <= n; i++) {
      madd(dyn[i], dyn[i - 1]);
      madd(dyn[i], dyn[i - 2]);
    }
    eprintf("%I64d\n", dyn[n]);
    k--;

    vi ans;
    int rem = n, ptr = 1;
    while (rem > 1) {
      assert(0 <= k && k < dyn[rem]);
      if (k < dyn[rem - 1]) {
        ans.pb(ptr++);
        rem--;
        continue;
      } else {
        k -= dyn[rem - 1];
      }

      assert(k < dyn[rem - 2]);
      ans.pb(ptr + 1);
      ans.pb(ptr + 0);
      ptr += 2;
      rem -= 2;
    }
    assert(0 <= k && k < dyn[rem]);
    if (rem == 1) {
      ans.pb(ptr++);
    }
    assert(ptr == n + 1);
    forn (i, n)
      printf("%d%c", ans[i], "\n "[i + 1 < n]);
  }
  return 0;
}