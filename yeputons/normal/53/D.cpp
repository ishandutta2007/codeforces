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

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) {}
#endif

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
                
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef pair<int, int> pii;

int n;
int main() {
  #ifdef DEBUG
  freopen("stdin.txt", "r", stdin);
  freopen("stdout.txt", "w", stdout);
  #endif

  while (scanf("%d", &n) >= 1) {
    vi a(n), b(n);
    forn (i, n) scanf("%d", &a[i]);
    forn (i, n) scanf("%d", &b[i]);

    vector<pii> ans;
    forn (i, n) {
      if (b[i] == a[i]) continue;
      for (int i2 = i; i2 < n; i2++)
        if (b[i2] == a[i]) {
          for (int i3 = i2; i3 > i; i3--) {
            ans.pb(mp(i3 - 1, i3));
            swap(b[i3 - 1], b[i3]);
          }
          break;
        }
      assert(b[i] == a[i]);
    }
    printf("%d\n", ans.size());
    forn (i, ans.size())
      printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
    
    #ifndef DEBUG
    #warning No multitest!!!
    break;
    #endif
  }
  return 0;
}