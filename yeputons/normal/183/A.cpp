#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>

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

const char *strs[] = {
  "UL",
  "UR",
  "DL",
  "DR",
  "ULDR"
};

const char *dc = "URDL";
const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { 1, 0, -1, 0 };

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n;
  while (scanf("%d", &n) >= 1) {
    vi cnts(5);
    for (int i = 0; i < n; i++) {
      char buf[6];
      scanf("%s", buf);

      int ty = -1;
      for (int i2 = 0; i2 < 5; i2++) if (!strcmp(buf, strs[i2])) ty = i2;
      assert(ty >= 0);
      cnts[ty]++;
    }

    ll ans = ll(1 + cnts[0] + cnts[3] + cnts[4]) * ll(1 + cnts[1] + cnts[2] + cnts[4]);
    printf("%I64d\n", ans);
  }
  return 0;
}