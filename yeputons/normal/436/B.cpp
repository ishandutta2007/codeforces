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
#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...)
#endif
#define sz(x) ((int)(x).size())
#define forn(i, n) for (int i = 0; i < (n); i++)

#ifdef DEBUG
struct Timestamper {
  string msg;
  clock_t start;

  Timestamper(const string &_msg) : msg(_msg), start(clock()) {}
  ~Timestamper() {
    eprintf("[ %s ] Time=%.3lfs\n", msg.c_str(), (clock() - start) * 1.0 / CLOCKS_PER_SEC);
  }
} __timestamper("end");
#else
struct Timestamper {};
#endif

typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pll;

const int inf = 1e9;

int main() {
  #ifdef DEBUG
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
  #endif

  int h, w;
  while (scanf("%d%d%*d", &h, &w) >= 1) {
    vi ans(w);
    forn (y, h) {
      const int MAXW = 2010;
      static char f[MAXW + 1];
    	scanf("%s", f);
    	forn (x, w) {
    	  if (f[x] == 'R') {
    	    int pos = x + y;
    	    if (pos < w) ans[pos]++;
    	  } else if (f[x] == 'L') {
    	    int pos = x - y;
    	    if (pos >= 0) ans[pos]++;
    	  } else if (f[x] == 'U') {
    	    if (y % 2 == 0) ans[x]++;
    	  }
    	}
    }
    forn (i, w)
      printf("%d%c", ans[i], "\n "[i + 1 < w]);
  }
  return 0;
}