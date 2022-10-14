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
    vector<unsigned> ads(n);
    for (int i = 0; i < n; i++) {
      unsigned cur = 0;
      for (int i2 = 0; i2 < 4; i2++) {
        unsigned x;
        scanf("%u%*c", &x);
        cur <<= 8; cur |= x;
      }
      ads[i] = cur;
    }

    for (int cnt = 1; cnt <= 32; cnt++) {
      unsigned msk = 0;
      for (int i = 0; i < cnt; i++) { msk <<= 1; msk |= 1; }
      msk <<= 32 - cnt;

      set<unsigned> wasmsk;
      for (int i = 0; i < n; i++)
        wasmsk.insert(ads[i] & msk);
      if (sz(wasmsk) == k) {
        vi out;
        for (int i = 0; i < 4; i++) {
          out.pb(msk & 0xFF);
          msk >>= 8;
        }
        reverse(out.begin(), out.end());
        for (int i = 0; i < sz(out); i++)
          printf("%d%c", out[i], "\n."[i + 1 < sz(out)]);
        goto end;
      }
    }
    printf("-1\n");
    end:;
  }
  return 0;
}