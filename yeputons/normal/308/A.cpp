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
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define sz(x) ((int)(x).size())

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

int main() {
  #ifdef DEBUG
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
  #endif

  int n; ll l, t;
  while (scanf("%d%I64d%I64d", &n, &l, &t) >= 1) {
    vector<ll> as(2 * n);
    for (int i = 0; i < n; i++) {
      scanf("%I64d", &as[i]), as[i + n] = l + as[i];
    }
    t *= 2;

    ll ans = 0;
    for (int a = 0; a < n; a++) {
//      eprintf("a=%d, pos=%d\n", a, as[a]);
      ll cnt = t / l;
      ll max1 = t % l;
      ans += cnt * (n - 1);
//      eprintf("  cnt=%I64d, max1=%I64d\n", cnt, max1);

      int badPos = upper_bound(as.begin() + a, as.begin() + a + n, as[a] + max1) - as.begin();
      assert(badPos > a);
      ans += badPos - a - 1;
    }

    printf("%I64d.%02d\n", ans / 4, (int)(ans % 4) * 25);
  }
  return 0;
}