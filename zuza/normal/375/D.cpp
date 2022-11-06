#include <algorithm>

#include <ctime>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <iostream>

#include <map>

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define TRACE(x) cout << #x << " = " << (x) << endl

typedef long long llint;

const int MAXN = 1e5 + 123;
int n_v, n_q;
int color[MAXN];
vector<int> E[MAXN];

int weight[MAXN];

void weight_dfs(int root) {
  static int dad[MAXN];
  static int e_it[MAXN];

  dad[root] = -1;
  e_it[root] = 0;
  weight[root] = 1;

  int ptr = root;
  while (ptr != -1) {
    if (e_it[ptr] < (int)E[ptr].size()) {
      int b = E[ptr][e_it[ptr]++];
      if (b == dad[ptr]) continue;

      dad[b] = ptr;
      e_it[b] = 0;
      weight[b] = 1;
      ptr = b;
    } else {
      int up = dad[ptr];
      weight[up] += weight[ptr];
      ptr = up;
    }
  }
}

const int MAXNODE = 18 * (1e5 + 123);
const int inf = 1e9;

mt19937 mt;

struct Node {
  int key, cnt;
  int l, r, p;
  mt19937::result_type rank;

  // --- order-statistics ---
  int w; // weight
  
  Node() { key = -1; l = r = p = 0; rank = mt(); cnt = 0; w = 0; /* maks = -inf; mini = +inf; */ }
  void update(Node& l, Node& r) {
    w = l.w + r.w;
    if (cnt != 0) { // include myself
      w += cnt;
    }
  }

} data[MAXNODE];

int data_mem = 1; // data[0] is a dummy

struct Treap {
  int root;

  Treap() { clear(); }
  void clear() { root = 0; }

  void set_l(int up, int down) {
    data[up].l = down;
    data[down].p = up;
    update_node(up);
  }
  void set_r(int up, int down) {
    data[up].r = down;
    data[down].p = up;
    update_node(up);
  }
  void prop_up(int ptr) {
    for (; ptr != 0; ptr = data[ptr].p)
      update_node(ptr);
  }
  void update_node(int ptr) {
    data[ptr].update(data[data[ptr].l], data[data[ptr].r]); 
  }
  void rotate(int up, int down) {
    int p = data[up].p;

    if (data[up].l == down) {
      set_l(up, data[down].r);
      set_r(down, up);
    } else if (data[up].r == down) {
      set_r(up, data[down].l);
      set_l(down, up);
    } else assert(false);

    if (p == 0) { root = down; data[down].p = 0; }
    else if (data[p].l == up) set_l(p, down);
    else if (data[p].r == up) set_r(p, down);
    else assert(false);
  }
  void repair(int ptr) {
    while (data[ptr].p != 0 && data[ptr].rank < data[data[ptr].p].rank) {
      rotate(data[ptr].p, ptr);
    }
  }

  int update(int key, int delta = 1) {
    int a = 0, b = root;

    while (b != 0) {
      a = b;
      if (key < data[a].key) b = data[a].l;
      else if (key > data[a].key) b = data[a].r;
      else { // encoutered a node with the same key
        data[a].cnt += delta;
        prop_up(a);
        return a;
      }
    }

    int ptr = data_mem++; // create a new node with key
    Node& node = data[ptr];
    node.p = a;
    node.key = key;
    node.cnt = delta;

    if (root == 0) {
      root = ptr;
      update_node(ptr);
    } else {
      if (key < data[a].key) set_l(a, ptr);
      else set_r(a, ptr);
      prop_up(ptr);
      repair(ptr);
    }
    return ptr;
  }

  int L, R;

  int _query(int ptr, int ptr_l, int ptr_r) { // search for [L, R) in ptr [ptr_l, ptr_r)
    if (ptr == 0) return 0;
    if (ptr_r <= L || R <= ptr_l) return 0;
    if (L <= ptr_l && ptr_r <= R) return data[ptr].w;
    return
      + _query(data[ptr].l, ptr_l, data[ptr].key)
      + _query(data[ptr].r, data[ptr].key + 1, ptr_r)
      + ((L <= data[ptr].key && data[ptr].key < R) ? data[ptr].cnt : 0);
  }
  int query(int a, int b) { // interval [a, b)
    L = a; R = b;
    return _query(root, -inf, +inf); // root limits
  }

  void debug(int ptr) { // testing only, tests various tree parameters
    if (ptr == 0) return;
    if (data[ptr].p != 0 && data[ptr].rank < data[data[ptr].p].rank) assert(false);
    Node before = data[ptr];
    update_node(ptr);
    assert(before.w == data[ptr].w); // test order statistics
    if (data[ptr].l != 0 && data[data[ptr].l].key >= data[ptr].key) assert(false); // test key values
    if (data[ptr].r != 0 && data[data[ptr].r].key <= data[ptr].key) assert(false);
    debug(data[ptr].l);
    debug(data[ptr].r);
  }
};

vector<int> v_qinds[MAXN];
int q_k[MAXN];
int q_res[MAXN];

void solve(int root, int root_dad, int c_depth) {
  vector<int> chain;

  for (int v = root, dad = root_dad; ; ) {
    chain.push_back(v);
    int best = -1;
    for (int b : E[v]) {
      if (b == dad) continue;
      if (best == -1 || weight[b] > weight[best]) best = b;
    }
    if (best == -1) break;
    dad = v;
    v = best;
  }

  static const int MAXLOG = 18;
  static map<int, int> c2freks[MAXLOG];
  static Treap trees[MAXLOG];

  assert(c_depth < MAXLOG);
  Treap& tree = trees[c_depth];
  map<int, int>& frek = c2freks[c_depth];

  // cleaup
  tree.clear();
  frek.clear();

  // process chain
  int sz = chain.size();
  for (int i = sz - 1; i >= 0; --i) {
    int v = chain[i];

    for (int b : E[chain[i]]) {
      if (i-1 >= 0 && b == chain[i-1]) continue;
      if (i+1 < sz && b == chain[i+1]) continue;
      if (b == root_dad) continue;

      solve(b, v, c_depth + 1);
      for (auto p : c2freks[c_depth + 1]) {
        int later = (frek[p.first] += p.second);
        if (later - p.second > 0) tree.update(later - p.second, -1);
        tree.update(later, +1);
      }
    }

    {
      int later = ++frek[color[v]];
      if (later-1 > 0) tree.update(later-1, -1);
      tree.update(later, +1);
    }

    for (int qind : v_qinds[v]) {
      int k = q_k[qind];
      q_res[qind] = tree.query(k, inf);
    }
  }
}

int main(void)
{
  scanf("%d %d", &n_v, &n_q);
  REP(i, n_v) { scanf("%d", color+i); --color[i]; }

  REP(i, n_v-1) {
    int a, b; scanf("%d %d", &a, &b); --a, --b;
    E[a].push_back(b);
    E[b].push_back(a);
  }

  REP(i, n_q) {
    int v, k; scanf("%d %d", &v, &k); --v;
    v_qinds[v].push_back(i);
    q_k[i] = k;
    q_res[i] = 0;
  }

  weight_dfs(0);
  solve(0, -1, 0);

  REP(i, n_q) printf("%d\n", q_res[i]);
  return 0;
}