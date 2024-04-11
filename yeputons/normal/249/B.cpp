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

const int MAXL = 5e5 + 1e3;
int n, t;
char dat[MAXL + 1];

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n;
  while (scanf("%d%d%s", &n, &t, dat) >= 1) {
    int hl = n, hr = -1, hcnt = 0;
    vi shops;
    for (int i = 0; i < n; i++)
      if (dat[i] == 'H') {
        hl = min(hl, i);
        hr = max(hr, i);
        hcnt++;
      } else if (dat[i] == 'S') {
        shops.pb(i);
      }

    t--;
    if (hr > t) printf("-1\n");
    else {
      int L = -1, R = hcnt;
      while (L + 1 < R) {
        int M = (L + R) / 2;
        assert(M < hcnt);
        bool good = false;
        int rem = hcnt - M;
        if (rem <= sz(shops)) {
          int maxpos = max(hr, shops[rem - 1]);

          int ctim = maxpos;
          int btim = 2e9;

          int bal = M;

          for (int i = 0; i <= maxpos; i++) {
            if (dat[i] == 'H') bal--;
            else if (dat[i] == 'S') bal++;
            if (bal < 0) {
              btim = min(btim, ctim + maxpos - i);
              ctim += 2;
            }
          }
          btim = min(btim, ctim);
          if (btim <= t) good = true;
//          eprintf("M=%d %d; %d %d\n", M, good, ctim, t);
        }
        if (good) R = M;
        else L = M;
      }
      printf("%d\n", R);
    }
  }
  return 0;
}