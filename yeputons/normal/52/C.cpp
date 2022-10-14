#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <cstring>
#include <cstdarg>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

inline int eprintf(const char* format, ...) {
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

#define pb push_back
#define mp make_pair

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<bool> vb;

class tree {
  vll tr, tadd;
  vi lb, rb;
  int off, n;

  void normalize(int v) {
    if (!tadd[v]) return;
    tr[v] += tadd[v];
    if (v < off) {
      tadd[v << 1] += tadd[v];
      tadd[(v << 1) + 1] += tadd[v];
    }
    tadd[v] = 0;
  }

  void add(int v, int l, int r, ll val) {
    if (r < lb[v] || rb[v] < l) return;

    normalize(v);
    if (l <= lb[v] && rb[v] <= r) {
      tadd[v] += val;
      return;
    }
    add(v << 1, l, r, val); normalize(v << 1);
    add((v << 1) + 1, l, r, val); normalize((v << 1) + 1);
    tr[v] = min(tr[v << 1], tr[(v << 1) + 1]);
  }

  ll get(int v, int l, int r) {
    if (r < lb[v] || rb[v] < l) return 1e18;

    normalize(v);
    if (l <= lb[v] && rb[v] <= r) {
      return tr[v];
    }
    return min(get(v << 1, l, r), get((v << 1) + 1, l, r));
  }

  public:
  tree(const vi &a) {
    off = 1;
    while (off < a.size()) off <<= 1;
    n = a.size();

    tr = vll(off << 1, 1e18);
    tadd = vll(off << 1, 0);
    for (int i = 0; i < a.size(); i++)
      tr[off + i] = a[i];
    for (int i = off - 1; i >= 1; i--)
      tr[i] = min(tr[i << 1], tr[(i << 1) + 1]);

    lb = vi(off << 1);
    rb = vi(off << 1);
    for (int i = 0; i < off; i++) lb[off + i] = rb[off + i] = i;
    for (int i = off - 1; i >= 0; i--) {
      lb[i] = lb[i << 1];
      rb[i] = rb[(i << 1) + 1];
    }
  }

  ll get(int l, int r) {
    if (l <= r) {
      return get(1, l, r);
    } else {
      return min(get(1, l, n - 1), get(1, 0, r));
    }
  }

  void add(int l, int r, ll v) {
    if (l <= r) {
      add(1, l, r, v);
    } else {
      add(1, l, n - 1, v);
      add(1, 0, r, v);
    }
  }

  void print() {
    int i = 1;
    for (int lev = 0; i < tr.size(); lev++) {
      for (int i2 = 0; i2 < (1 << lev); i2++, i++)
        eprintf("(%I64d, %I64d) ", tr[i], tadd[i]);
      eprintf("\n");
    }
  }
};

int n;
char buf[4096];
int main() {
  #ifdef DEBUG
  freopen("stdin.txt", "r", stdin);
  freopen("stdout.txt", "w", stdout);
  #endif

  while (scanf("%d", &n) >= 1) {
    vi a(n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    tree tr(a);
//    tr.print();

    int m; scanf("%d ", &m);
    for (int i = 0; i < m; i++) {
      fgets(buf, sizeof buf, stdin);
      int l, r; ll v;
      int ty = sscanf(buf, "%d%d%I64d", &l, &r, &v);
      assert(ty == 2 || ty == 3);
      if (ty == 2) {
        printf("%I64d\n", tr.get(l, r));
      } else {
        tr.add(l, r, v);
      }
    }
    
    #ifndef DEBUG
    #warning No multitest!!!
    break;
    #endif
  }
  return 0;
}