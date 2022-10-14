#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define pb push_back
#define mp make_pair

typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
  #ifdef DEBUG
  freopen("stdin.txt", "r", stdin);
  freopen("stdout.txt", "w", stdout);
  #endif

  int n;
  while (scanf("%d", &n) >= 1) {
    int x = n;
    vi ps, pos;
    for (int i = 2; i <= n; i++) if (!(n % i)) {
      ps.pb(i);
      int pw = 0;
      while (!(n % i)) { pw++; n /= i; }
      pos.pb(pw);
    }

    vi ans;
    for (int i = 0; i < ps.size(); i++)
      while (pos[i]--) {
        ans.pb(x);
        x /= ps[i];
      }
    ans.pb(x);

    for (int i = 0; i < ans.size(); i++)
      printf("%d%c", ans[i], "\n "[i + 1 < ans.size()]);

    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}