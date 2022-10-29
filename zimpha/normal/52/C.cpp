#include <cstdio>
#include <limits>
#include <algorithm>
#include <sstream>
#include <iostream>

using i64 = long long;

const int N = 2e5 + 10;

struct Node {
  i64 min, add;
  
  void apply(i64 t_add) {
    min += t_add;
    add += t_add;
  }
} nodes[N << 1];

inline int get_id(int l, int r) { return (l + r) | (l != r); }
inline Node* get_node(int l, int r) { return nodes + get_id(l, r); }

void push(Node* o, int l, int r, int m) {
  if (o->add) {
    get_node(l, m)->apply(o->add);
    get_node(m + 1, r)->apply(o->add);
    o->add = 0;
  }
}

void pull(Node* o, int l, int r, int m) {
  o->min = std::min(get_node(l, m)->min, get_node(m + 1, r)->min);
}

void build(int l, int r) {
  Node* o = get_node(l, r);
  if (l == r) {
    std::cin >> o->min;
    return;
  }
  int m = (l + r) >> 1;
  build(l, m);
  build(m + 1, r);
  pull(o, l, r, m);
}

void add(int l, int r, int L, int R, int v) {
  Node* o = get_node(l, r);
  if (L <= l && R >= r) {
    o->apply(v);
    return;
  }
  int m = (l + r) >> 1;
  push(o, l, r, m);
  if (L <= m) add(l, m, L, R, v);
  if (R > m) add(m + 1, r, L, R, v);
  pull(o, l, r, m);
}

i64 get(int l, int r, int L, int R) {
  Node *o = get_node(l, r);
  if (L <= l && R >= r) return o->min;
  int m = (l + r) >> 1;
  push(o, l, r, m);
  i64 ret = std::numeric_limits<i64>::max();
  if (L <= m) ret = std::min(ret, get(l, m, L, R));
  if (R > m) ret = std::min(ret, get(m + 1, r, L, R));
  return ret;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  int n, m;
  std::cin >> n;
  build(1, n);
  std::cin >> m;
  std::string line;
  std::getline(std::cin, line);
  for (int i = 0; i < m; ++i) {
    std::getline(std::cin, line);
    std::stringstream sin(line);
    int l, r, v;
    sin >> l >> r;
    ++l, ++r;
    if (sin >> v) {
      if (l <= r) add(1, n, l, r, v);
      else {
        add(1, n, l, n, v);
        add(1, n, 1, r, v);
      }
    } else {
      i64 ret = 0;
      if (l <= r) ret = get(1, n, l, r);
      else {
        ret = std::min(get(1, n, l, n), get(1, n, 1, r));
      }
      printf("%lld\n", ret);
    }
  }
  return 0;
}