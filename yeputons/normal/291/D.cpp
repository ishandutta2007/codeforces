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

  int n, k;
  while (scanf("%d%d", &n, &k) >= 1) {
    vi vals(n, 1);
    vals[n - 1] = 0;
    for (int step = 0; step < k; step++) {
      for (int i = 0; i < n; i++) {
        int need = n - i - 1 - vals[i];
        assert(need >= 0);
        int x = i;
        while (vals[x] > need) {
          x++;
          assert(x < n);
        }
        printf("%d%c", x + 1, "\n "[i + 1 < n]);
        vals[i] += vals[x];
      }
    }
  }
  return 0;
}