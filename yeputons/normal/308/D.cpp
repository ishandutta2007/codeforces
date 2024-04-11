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

int xx;
inline int solve(int a, int b, int minv, int maxv) {
  if (a * minv >= b) return 0;
  if (a * maxv < b) return maxv - minv + 1;
/*  int xx = b / a;
  if (a * xx == b) xx--;
  return xx - minv + 1;*/
  int tmp = a * xx;
  while (xx >= minv && tmp >= b)
    xx--, tmp -= a;
  return xx - minv + 1;
}

int main() {
  #ifdef DEBUG
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
  #endif

  int n, m;
  while (scanf("%d%d", &n, &m) >= 1) {
    ll ans = 0;
    ll ans0 = 0;
    for (int x = m; x <= n - x - 1; x++) {
      int A = n - x + 1;
      int B = 2 * n - 2 * x - 1;
      int C = n - x - 2;

      int cans = 0;
      xx = n - m - 1;
      for (int y = m; y + m < n; y++) {
        int a = x + y + 2;
        int b = -y * A + x * B + C;
        int tmp = solve(a, b, m, n - m - 1);
        if (!tmp) break;
        cans += tmp;
      }
      if (x < n - x - 1) ans += cans;
      else ans0 += cans;
    }
    ans *= 2;
    ans += ans0;
    printf("%I64d\n", ans * 3);
  }
  eprintf("%d\n", clock());
  return 0;
}