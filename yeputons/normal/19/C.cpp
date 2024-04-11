#include <cstdio>
#include <cstdlib>
#include <cstdarg>
#include <cassert>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

int eprintf(const char *format, ...) {
  #ifdef DEBUG
  va_list args;
  va_start(args, format);
  int ret = vfprintf(stderr, format, args);
  va_end(args);
  return ret;
  #else
  return 0;
  #endif
}

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

typedef pair<int, int> pii;
typedef vector<pii> vpii;

typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<string> vs;

#define INF 2000000000
#define mp make_pair
#define pb push_back

#ifdef linux
#define LLD "%lld"
#elif _WIN32
#define LLD "%I64d"
#endif

class line_tree {
  typedef pii T;
  vector<T> tr;
  int off;

  public:
  line_tree(int sz) {
    off = 1; while (off < sz) off <<= 1;
    tr = vector<T>(off << 1, mp(INF, -1));
  }

  void set(int x, T v) {
    x += off;
    tr[x] = v;
    for (x >>= 1; x >= 1; x >>= 1)
      tr[x] = min(tr[x << 1], tr[(x << 1) + 1]);
  }
  T get(int l, int r) {
    l += off; r += off;
    T res(INF, -1);
    while (l <= r) {
      if (l & 1) res = min(res, tr[l++]);
      if (!(r & 1)) res = min(res, tr[r--]);
      l >>= 1; r >>= 1;
    }
    return res;
  }
};

int main() {
  int n;
  while (scanf("%d", &n) >= 1) {
    vi a(n);
    map<int, int> ids;
    vi src;
    for (int i = 0; i < n; i++) {
      int x;
      scanf("%d", &x);
      map<int, int>::iterator it = ids.find(x);
      if (it == ids.end()) {
        ids.insert(mp(x, a[i] = ids.size()));
        src.pb(x);
      } else {
        a[i] = it->second;
      }
    }
    int k = ids.size();
    vi next(n, -1);
    vi last(ids.size(), -1);
    for (int i = n - 1; i >= 0; i--) {
      if (last[a[i]] >= 0)
        next[i] = last[a[i]];
      last[a[i]] = i;
    }

    line_tree tr(n);
    for (int i = n - 2; i >= 0; i--) {
      for (int i2 = next[i]; i2 >= 0; i2 = next[i2]) {
        int l = i2 - i; bool good = true;
        if (i2 + l > n) break;
        for (int i3 = 1; i3 < l; i3++)
          if (a[i + i3] != a[i2 + i3]) {
            good = false;
            break;
          }
        if (good) {
          tr.set(i, mp(l, i2));
          break;
        }
      }
    }
     vi jump(n, -1);
     for (int i = 0; i < n; i++) {
       jump[i] = tr.get(i, n - 1).second;
     }

    int pos = 0;
    while (jump[pos] >= 0) pos = jump[pos];
    printf("%d\n", n - pos);
    for (int i = pos; i < n; i++)
      printf("%d%c", src[a[i]], "\n "[i + 1 < n]);

    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}