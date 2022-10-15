#include <stdio.h>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <complex>
#include <map>
#include <unordered_map>
#include <queue>
#include <array>
#include <bitset>
#include <chrono>
#include <random>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
const int mod = 998244353;

ll mpow(ll x, ll n) {
  ll res = 1;
  while (n) {
    if (n & 1) res = res * x % mod;
    x = x * x % mod;
    n /= 2;
  }
  return res;
}

typedef struct item * pitem;

struct item {
  int prior, value, cnt, left, right, mon;
  pitem l, r;
  //    item() { }
  //	item (int key, int prior) : key(key), prior(prior), l(NULL), r(NULL) { }
};

item pool[2000005];

int cnt (pitem it) {
  return it ? it->cnt : 0;
}

int mon (pitem it) {
  return it ? it->mon : 0;
}

void upd_cnt (pitem it) {
  if (it) {
    it->cnt = cnt(it->l) + cnt(it->r) + 1;
    it->left = it->l ? it->l->left : it->value;
    it->right = it->r ? it->r->right : it->value;
    it->mon = mon(it->l) + mon(it->r);
    if (it->l && it->l->right > it->value) ++it->mon;
    if (it->r && it->r->left < it->value) ++it->mon;
  }
}

void push (pitem it) {
}

void merge (pitem & t, pitem l, pitem r) {
  push (l);
  push (r);
  if (!l || !r)
    t = l ? l : r;
  else if (l->prior > r->prior)
    merge (l->r, l->r, r),  t = l;
  else
    merge (r->l, l, r->l),  t = r;
  upd_cnt (t);
}

int getval(pitem t, int key, int add = 0) {
  push (t);
  int cur_key = add + cnt(t->l);
  if (key == cur_key)
    return t->value;
  if (key < cur_key)
    return getval(t->l, key, add);
  else return getval(t->r, key, add + 1 + cnt(t->l));
}

void split (pitem t, pitem & l, pitem & r, int key, int add = 0) {
  if (!t)
    return void( l = r = 0 );
  push (t);
  int cur_key = add + cnt(t->l);
  if (key <= cur_key)
    split (t->l, l, t->l, key, add),  r = t;
  else
    split (t->r, t->r, r, key, add + 1 + cnt(t->l)),  l = t;
  upd_cnt (t);
}

void outputerr (pitem t) {
  if (!t)  return;
  push (t);
  outputerr (t->l);
  cerr << t->value << ' ';
  outputerr (t->r);
}

void outerr(pitem t) {
  outputerr(t);
  cerr << endl;
}

void output (pitem t) {
  if (!t)  return;
  push (t);
  output (t->l);
  printf("%c", (char)('a'+t->value));
  output (t->r);
}

void out(pitem t, int l, int r) {
  pitem t1, t2, t3;
  split (t, t1, t2, l);
  split (t2, t2, t3, r-l+1);
  output(t2);
  merge (t, t1, t2);
  merge (t, t, t3);
  printf("\n");
}

void output (pitem t, vi & v, int & it) {
  if (!t)  return;
  push (t);
  output (t->l, v, it);
  v[it] = t->value;
  ++it;
  output (t->r, v, it);
}

void calc (pitem t, int l, int r, int& c) {
  pitem t1, t2, t3;
  split (t, t1, t2, l);
  split (t2, t2, t3, r-l+1);
  c += t2->mon;
  merge (t, t1, t2);
  merge (t, t, t3);
}

void out (pitem t, int l, int r, vi & v) {
  v.resize(r-l+1);
  pitem t1, t2, t3;
  split (t, t1, t2, l);
  split (t2, t2, t3, r-l+1);
  int it = 0;
  output(t2, v, it);
  merge (t, t1, t2);
  merge (t, t, t3);
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  vl fac(1e6, 1);
  for (int i = 2; i < fac.size(); ++i) fac[i] = fac[i - 1] * i % mod;
  auto root = &pool[0];
  root->value = 0;
  root->cnt = 0;
  for (int i = 1; i < 200005; ++i) {
    pool[i].cnt = 0;
    pool[i].prior = rand();
    pool[i].value = pool[i].left = pool[i].right = i;
    merge(root, root, &pool[i]);
  }
  int T;
  cin >> T;
  for (int test = 0; test < T; ++test) {
    int n, m;
    cin >> n >> m;
    vi x(m), y(m);
    for (int i = 0; i < m; ++i) {
      cin >> x[i] >> y[i];
      --x[i]; --y[i];
    }
//    vi v; out(root, 0, n - 1, v); for (int i : v) cerr << i << ' '; cerr << endl;
    for (int i = 0; i < m; ++i) {
      pitem t1,t2,t3,t4;
//      cerr << "split: " << x << ' ' << y << endl;
//      outerr(root);
      split(root, t1, t2, y[i]);
      split(t2, t2, t3, x[i] - y[i]);
      split(t3, t3, t4, 1);
//      outerr(t1);
//      outerr(t2);
//      outerr(t3);
//      outerr(t4);
      merge(root, t1, t3);
      merge(root, root, t2);
      merge(root, root, t4);
    }
    int c = 1 + root->mon;
//    out(root, 0, n - 1, v); for (int i : v) cerr << i << ' '; cerr << endl;
//    cerr << c << endl;
    int k = n - c;
    cout << fac[n + k] * mpow(fac[n] * fac[k] % mod, mod - 2) % mod << '\n';
    for (int i = m - 1; i >= 0; --i) {
      pitem t1,t2,t3,t4;
//      cerr << "split: " << x << ' ' << y << endl;
//      outerr(root);
      split(root, t1, t2, y[i]);
      split(t2, t2, t3, 1);
      split(t3, t3, t4, x[i] - y[i]);
//      outerr(t1);
//      outerr(t2);
//      outerr(t3);
//      outerr(t4);
      merge(root, t1, t3);
      merge(root, root, t2);
      merge(root, root, t4);
    }
  }
  return 0;
}