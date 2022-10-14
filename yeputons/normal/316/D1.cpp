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
    vi tys(n);
    for (int i = 0; i < n; i++)
      scanf("%d", &tys[i]);

    vi ord(n);
    for (int i = 0; i < n; i++)
      ord[i] = i;

    int ans = 0;
    do {
      vb was(n, false);
      bool g = true;
      for (int st = 0; st < n; st++) if (ord[st] != st && !was[st]) {
        int cnt1 = 0;
        for (int x = st; !was[x]; x = ord[x]) {
          cnt1 += tys[x] == 1;
          was[x] = true;
        }
        if (cnt1 > 2) {
          g = false;
          break;
        }
      }
      ans += g;
    } while (next_permutation(ord.begin(), ord.end()));
    printf("%d\n", ans);
  }
  return 0;
}