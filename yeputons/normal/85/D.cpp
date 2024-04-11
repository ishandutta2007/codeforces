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

int eoff;
void eoprintf(const char *format, ...) {
  va_list args;
  va_start(args, format);
  for (int i = 0; i < eoff; i++) eprintf(" ");
  vfprintf(stderr, format, args);
  va_end(args);
}

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

const int M = 5;
class cart_tree {
  typedef struct _node {
    int v, cnt;
    int y;
    ll sums[M];
    _node *l, *r;

    _node(int _v) : v(_v), cnt(1), l(0), r(0) {
      memset(sums, 0, sizeof sums);
      sums[0] = v;
      y = (rand() << 16) | rand();
    }

    void recalc() {
      cnt = 0;
      memset(sums, 0, sizeof sums);
      if (l) {
        for (int i = 0; i < M; i++)
          sums[(i + cnt) % M] += l->sums[i];
        cnt += l->cnt;
      }
      sums[cnt++ % M] += v;
      if (r) {
        for (int i = 0; i < M; i++)
          sums[(i + cnt) % M] += r->sums[i];
        cnt += r->cnt;
      }
    }
  } *node;

  node root;

  node merge(node l, node r) {
    if (!l) return r;
    if (!r) return l;

    if (l->y < r->y) {
      l->r = merge(l->r, r);
      l->recalc();
      return l;
    } else {
      r->l = merge(l, r->l);
      r->recalc();
      return r;
    }
  }

  void split(node v, int key, node &l, node &r) {
    l = r = 0;
    if (!v) return;

    node tmp;
    if (v->v < key) {
      l = v;
      split(l->r, key, tmp, r);
      l->r = tmp;
      l->recalc();
    } else {
      r = v;
      split(r->l, key, l, tmp);
      r->l = tmp;
      r->recalc();
    }
  }

  void print(node v) {
    if (!v) { eoprintf("EMPTY\n"); return; }
    eoprintf("v=%d, y=%d (", v->v, v->y);
    for (int i = 0; i < M; i++)
      eprintf("%I64d%c", v->sums[i], ") "[i + 1 < M]);
    eprintf("\n");
    eoff += 2;
    print(v->l);
    print(v->r);
    eoff -= 2;
  }

  public:
  cart_tree() : root(0) {}

  void insert(int x) {
    node l, r;
    split(root, x, l, r);
    root = merge(merge(l, new _node(x)), r);
  }
  void erase(int x) {
    node l, m1, m2, r;
    split(root, x, l, m1);
    split(m1, x + 1, m2, r);
    if (m2) { delete m2; m2 = 0; }
    root = merge(l, r);
  }
  ll get(int m) {
    if (!root) return 0;
    return root->sums[m % M];
  }
  void print() { print(root); }
};

char buf[1024];
int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif
  
  int n;
  while (scanf("%d", &n) >= 1) {
    cart_tree tr;
    for (int i = 0; i < n; i++) {
      scanf("%s", buf);
      if (!strcmp(buf, "sum")) {
        #ifdef DEBUG
        tr.print();
        #endif
        printf("%I64d\n", tr.get(2));
      } else {
        int x;
        scanf("%d", &x);
        if (!strcmp(buf, "add")) {
          tr.insert(x);
        } else if (!strcmp(buf, "del")) {
          tr.erase(x);
        } else
          assert(false);
      }
    }
  
    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}