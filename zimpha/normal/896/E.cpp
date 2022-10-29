#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cassert>
#include <cmath>

constexpr int N = 1e6 + 10;
constexpr int M = 5e5 + 10;
constexpr int V = 1e5 + 10;
constexpr int BlockSize = 2000;

struct Query {
  int op, l, r, x;
  int ret;
};

Query queries[M];
int a[N];

struct Block {
  int parent[V];
  int cnt[V];

  int l, r;
  int delta, mx;

  void init(int _l, int _r) {
    l = _l;
    r = _r;
    build(l, r);
  }

  void build(int l, int r) {
    delta = 0;
    for (int i = 0; i < V; ++i) {
      parent[i] = i;
      cnt[i] = 0;
    }
    mx = *std::max_element(a + l, a + r);
    for (int i = l; i < r; ++i) {
      cnt[a[i]]++;
    }
  }

  int root(int x) {
    if (parent[x] != x) parent[x] = root(parent[x]);
    return parent[x];
  }

  // change x to y
  void merge(int x, int y) {
    x = root(x);
    y = root(y);
    if (x != y) {
      parent[x] = y;
      cnt[y] += cnt[x];
    }
  }

  void modify(int ql, int qr, int x) {
    if (x + delta >= mx) return;
    if (qr - ql == r - l) modify_all(x);
    else modify_part(ql, qr, x);
  }

  void modify_all(int x) {
    if (x < mx - x - delta) {
      for (int i = delta + 1; i <= x + delta; ++i) {
        merge(i, i + x);
      }
      delta += x;
    } else {
      for (int i = mx; i >= x + 1 + delta; --i) {
        merge(i, i - x);
      }
      mx = x + delta;
    }
  }

  void modify_part(int ql, int qr, int x) {
    for (int i = ql; i < qr; ++i) {
      a[i] = root(a[i]);
      if (a[i] - delta > x) {
        --cnt[a[i]];
        a[i] = root(a[i] - x);
        ++cnt[a[i]];
      }
    }
  }

  int query(int ql, int qr, int x) {
    if (qr - ql == r - l) return query_all(x);
    else return query_part(ql, qr, x);
  }

  int query_all(int x) {
    x += delta;
    if (x > mx || root(x) != x) return 0;
    else return cnt[root(x)];
  }

  int query_part(int ql, int qr, int x) {
    int ret = 0;
    for (int i = ql; i < qr; ++i) {
      int w = root(a[i]) - delta;
      ret += w == x;
    }
    return ret;
  }
} block;

struct FastIO {
  static const int S = 655360;
  char buf[S];
  int pos, len;
  bool eof;
  FILE *in;
  FastIO(FILE *_in = stdin) {
    in = _in;
    pos = len = 0;
    eof = false;
  }
  inline int next_char() {
    if (pos == len)
      pos = 0, len = fread(buf, 1, S, in);
    if (pos == len) {eof = true; return -1;}
    return buf[pos++];
  }
  inline int next_u32() {
    int c = next_char(), x = 0;
    while (c <= 32) c = next_char();
    for (;'0' <= c && c <= '9'; c = next_char()) x = x * 10 + c - '0';
    return x;
  }
  inline int next_i32() {
    int s = 1, c = next_char(), x = 0;
    while (c <= 32) c = next_char();
    if (c == '-') s = -1, c = next_char();
    for (; '0' <= c && c <= '9'; c = next_char()) x = x * 10 + c - '0';
    return x * s;
  }
} io;

int main() {
  int n = io.next_u32();
  int m = io.next_u32();
  int block_size = sqrt(n);
  for (int i = 0; i < n; ++i) {
    a[i] = io.next_u32();
  }
  for (int i = 0; i < m; ++i) {
    queries[i].op = io.next_u32();
    queries[i].l = io.next_u32() - 1;
    queries[i].r = io.next_u32();
    queries[i].x = io.next_u32();
  }

  for (int bl = 0; bl < n; bl += block_size) {
    int br = std::min(n, bl + block_size);
    block.init(bl, br);
    for (int i = 0; i < m; ++i) {
      int ql = std::max(bl, queries[i].l);
      int qr = std::min(br, queries[i].r);
      if (ql >= qr) continue;
      if (queries[i].op == 1) block.modify(ql, qr, queries[i].x);
      else queries[i].ret += block.query(ql, qr, queries[i].x);
    }
  }

  for (int i = 0; i < m; ++i) {
    if (queries[i].op == 2) printf("%d\n", queries[i].ret);
  }
  return 0;
}