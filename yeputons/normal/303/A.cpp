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

int main() {
  #ifdef DEBUG
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
  #endif

  int n;
  while (scanf("%d", &n) >= 1) {
    eprintf("n=%d\n", n);
    if (n % 2 == 0) {
      printf("-1\n");
      continue;
    }
    assert(n != 4);

    vi as(n), bs(n);
    for (int i = 0; i < n; i++)
      as[i] = i;

    if (n % 2 == 0) {
      bs = as;
      bool ok = false;
      do {
        vb was(n, false);
        ok = true;
        for (int i = 0; i < n; i++) {
          int c = (as[i] + bs[i]) % n;
          if (was[c]) { ok = false; break; }
          was[c] = true;
        }
        if (ok) break;
      } while (next_permutation(bs.begin(), bs.end()));
      assert(ok);
    } else {
      for (int i = 0; i < n; i++)
        bs[i] = (as[i] + 1) % n;
    }

    for (int i = 0; i < n; i++)
      printf("%d%c", as[i], "\n "[i + 1 < n]);
    for (int i = 0; i < n; i++)
      printf("%d%c", bs[i], "\n "[i + 1 < n]);
    for (int i = 0; i < n; i++)
      printf("%d%c", (as[i] + bs[i]) % n, "\n "[i + 1 < n]);

    vb was(n);                                         
    for (int i = 0; i < n; i++) {
      assert(!was[bs[i]]);
      was[bs[i]] = true;
    }
    was = vb(n, false);
    for (int i = 0; i < n; i++) {
      int c = (as[i] + bs[i]) % n;
      assert(!was[c]);
      was[c] = true;
    }
  }
  return 0;
}