#include <bits/stdc++.h>

using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

struct UnionFind {
  V<int> ig;
  VV<int> gi;
  int gc;  // group count
  UnionFind(int n) {
    ig = V<int>(n);
    gi = VV<int>(n);
    for (int i = 0; i < n; i++) {
      ig[i] = i; gi[i] = {i};
    }
    gc = n;
  }
  void merge(int a, int b) {
    if (same(a, b)) return;
    gc--;
    int x = ig[a], y = ig[b];
    if (gi[x].size() < gi[y].size()) swap(x, y);
    for (int j: gi[y]) {
      ig[j] = x;
    }
    gi[x].insert(gi[x].end(), gi[y].begin(), gi[y].end());
    gi[y].clear();
  }
  bool same(int a, int b) { return ig[a] == ig[b]; }
};

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  auto uf = UnionFind(n+m);
  for (int i = 0; i < q; i++) {
    int x, y;
    cin >> x >> y; x--; y--;
    uf.merge(x, n + y);
  }
  cout << uf.gc - 1 << endl;
  return 0;

}