#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cstdarg>
#include <cassert>
#include <algorithm>
#include <vector>
#include <string>

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

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n, m;
  while (scanf("%d%d", &n, &m) >= 1) {
    vector<pii> a(m);
    for (int i = 0; i < m; i++)
      scanf("%d", &a[i].first), a[i].second = i;
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());

    try {
      int maxc = n / 2;
      int sum = 0;
      for (int i = 0; i < m; i++) {
        a[i].first = min(a[i].first, maxc);
        sum += a[i].first;
      }
      if (sum < n) throw 0;

      vi pord;
      for (int i = 0; i + 1 < n; i += 2)
        pord.pb(i);
      if (n % 2 == 1) pord.pb(n - 1);
      for (int i = 1; i < n; i += 2)
        pord.pb(i);
      assert(pord.size() == n);

      vi res(n, -1);
      int pos = 0;
      for (int i = 0; i < m; i++)
        while (pos < n && a[i].first) {
          res[pord[pos]] = a[i].second; a[i].first--;
          pos++;
        }

      for (int i = 0; i < n; i++) {
        int pr = res[(i + n - 1) % n];
        int ne = res[(i + 1) % n];
        int cur = res[i];
        if (pr == cur || cur == ne) throw 0;
      }
      for (int i = 0; i < n; i++)
        printf("%d%c", res[i] + 1, "\n "[i + 1 < n]);
    } catch (...) {
      printf("-1\n");
    }
    
    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}