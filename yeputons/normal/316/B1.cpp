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

  int n, me;
  while (scanf("%d%d", &n, &me) >= 1) {
    me--;

    vi nes(n);
    vb last(n, true);

    for (int i = 0; i < n; i++) {
      scanf("%d", &nes[i]), nes[i]--;
      if (nes[i] >= 0)
        last[nes[i]] = false;
    }

    vb canGet(n + 1, false);
    canGet[0] = true;

    int myoff = -1;

    for (int i = 0; i < n; i++) if (last[i]) {
      int clen = 0;
      int mypos = -1;
      for (int x = i; x >= 0; x = nes[x]) {
        if (x == me) mypos = clen;
        clen++;
      }
      if (mypos >= 0) {
        myoff = clen - mypos;
      } else {
        for (int i2 = n - clen; i2 >= 0; i2--)
          if (canGet[i2])
            canGet[i2 + clen] = true;
      }
    }
    assert(myoff >= 0);

    for (int i = 0; i <= n; i++)
      if (canGet[i])
        printf("%d\n", i + myoff);
    #ifdef DEBUG
    printf("\n");
    #endif
  }
  return 0;
}