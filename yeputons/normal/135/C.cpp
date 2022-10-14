#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cstdarg>
#include <cassert>
#include <algorithm>
#include <vector>
#include <string>
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

const int MAXL = 1e5 + 100;
char s[MAXL];

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  while (scanf("%s", s) >= 1) {
    int n = strlen(s);
    vi pos0, pos1, pos2;
    for (int i = n - 1; i >= 0; i--)
      if (s[i] == '0') pos0.pb(i);
      else if (s[i] == '1') pos1.pb(i);
      else pos2.pb(i);

    vector<string> res;
    int t1 = (n - 2 + 1) / 2;
    int t2 = (n - 2) / 2;

    if (sz(pos1) <= t1) {
      res.pb("00");
    }
    if (sz(pos0) <= t2) {
      res.pb("11");
    }
    if (sz(pos1) <= t1 + 1 && sz(pos0) <= t2 + 1) {
      int maxp0 = -1;
      if (sz(pos0)) maxp0 = max(maxp0, pos0[0]);

      int maxp1 = -1;
      if (sz(pos1)) maxp1 = max(maxp1, pos1[0]);

      if (sz(pos2)) {
        int c1 = t1 + 1 - sz(pos1);
        int c0 = t2 + 1 - sz(pos0);

        eprintf("%d %d\n", c1, c0);
        {
          int np0 = max(maxp0, c1 < sz(pos2) ? pos2[c1] : 0);
          int np1 = max(maxp1, c1 ? pos2[0] : -1);
          assert(np0 >= 0 && np1 >= 0);
          if (np0 < np1) res.pb("01");
          else res.pb("10");
        }
        {
          int np0 = max(maxp0, c0 ? pos2[0] : -1);
          int np1 = max(maxp1, c0 < sz(pos2) ? pos2[c0] : 0);
          assert(np0 >= 0 && np1 >= 0);
          if (np0 < np1) res.pb("01");
          else res.pb("10");
        }
      } else {
        if (maxp0 < maxp1) res.pb("01");
        else res.pb("10");
      }
    }

    sort(res.begin(), res.end());
    res.resize(unique(res.begin(), res.end()) - res.begin());
    for (int i = 0; i < sz(res); i++)
      printf("%s\n", res[i].c_str());
    
    #ifndef DEBUG
    break;
    #else
    printf("\n");
    #endif
  }
  return 0;
}