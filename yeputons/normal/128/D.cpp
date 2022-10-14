#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <cstdarg>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <vector>
#include <deque>
#include <string>

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
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif
  
  int n;
  while (scanf("%d", &n) >= 1) {
    vi ss(n);
    for (int i = 0; i < n; i++)
      scanf("%d", &ss[i]);
    sort(ss.begin(), ss.end());

    try {
      vi as;
      int pval = ss[0];
      as.pb(0);

      for (int i = 0; i < n; i++)
        if (pval != ss[i]) {
          if (pval + 1 != ss[i]) throw pval + 1;
          pval = ss[i];
          as.pb(1);
        } else
          as[sz(as) - 1]++;

      int n = sz(as);
/*      for (int i = 0; i < n; i++)
        eprintf("%d%c", as[i], "\n "[i + 1 < n]);
      eprintf("\n");*/

      if (n < 2) throw -1;

      int px = as[0];
      for (int i = 1; i < n; i++) {
        int nx = as[i] - px;
        if (nx < 0) throw 0;
        if (!nx && i + 1 < n)
          throw 0;
        px = nx;
      }
      if (px)
        throw 0;
      printf("YES\n");
    } catch (...) {
      printf("NO\n");
    }
  
    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}