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
#ifdef DEBUG
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n;
  while (scanf("%d", &n) >= 1) {
    vll as(n);
    for (int i = 0; i < n; i++)
      scanf("%I64d", &as[i]);
    vll sas = as;
    vi ord(n);
    vll msks(n);
    for (int i = 0; i < n; i++) {
      ord[i] = i;
    }

    ll sxor = 0;
    for (int i = 0; i < n; i++) sxor ^= as[i];

    int cid = 0;
    ll end = 0, eans = 0;
    for (int step = 0; step < 2; step++)
    for (ll coff = (1LL << 60); coff >= 1 && cid < n; coff >>= 1) if (step || (!(sxor & coff))) {
      for (int i = cid; i < n; i++)
        if (as[i] & coff) {
          swap(as[cid], as[i]);
          swap(ord[cid], ord[i]);
          swap(msks[cid], msks[i]);
          break;
        }
      if (!(as[cid] & coff)) continue;
      msks[cid] ^= 1LL << cid;
//      assert(as[cid] < (coff << 1));
      assert(as[cid] & coff);
      if (!(end & coff)) {
        end ^= as[cid];
        eans ^= msks[cid];
      }
      for (int i = cid + 1; i < n; i++) if (as[i] & coff) {
        as[i] ^= as[cid];
        msks[i] ^= msks[cid];
      }
      cid++;
    }
    vi out(n, 1);
    for (int i = 0; i < cid; i++) if (eans & (1LL << i)) {
      out[ord[i]] = 3 - out[ord[i]];
    }
/*    ll tmp = 0;
    for (int i = 0; i < n; i++) if (out[i] == 2)
      tmp ^= sas[i];
    assert(tmp == end);

    ll cans = 0;
    {
      ll tmp2 = 0;
      for (int i = 0; i < n; i++) tmp2 ^= sas[i];
      for (ll coff = 1; coff <= (1LL << 60); coff <<= 1)
        if (tmp2 & coff)
          cans += coff;
        else
          cans += (tmp & coff) << 1;
    }
    if (cans == 2078098915129555870LL)
      assert(false);
    eprintf("cans=%I64d\n", cans);*/
    for (int i = 0; i < n; i++)
      printf("%d%c", out[i], "\n "[i + 1 < n]);
  }
  return 0;
}