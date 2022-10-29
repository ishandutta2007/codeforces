#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

const int mod = 1e9 + 7;

int main() {
  int n;
  scanf("%d", &n);
  std::vector<int> dsu(n * 2), size(n * 2), edge(n * 2);
  std::vector<bool> loop(n * 2);
  for (int i = 0; i < n * 2; ++i) {
    dsu[i] = i;
    size[i] = 1;
    edge[i] = 0;
    loop[i] = false;
  }
  std::function<int(int)> root = [&](int x) {
    if (x != dsu[x]) dsu[x] = root(dsu[x]);
    return dsu[x];
  };
  for (int i = 0; i < n; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    int a = root(u - 1), b = root(v - 1);
    if (a == b) {
      edge[a]++;
      loop[a] = loop[a] | (u == v);
    } else {
      size[a] += size[b];
      edge[a] += edge[b] + 1;
      loop[a] = loop[a] | loop[b];
      dsu[b] = a;
    }
  }
  int ret = 1;
  for (int i = 0; i < n * 2; ++i) {
    if (root(i) != i) continue;
    if (size[i] == edge[i]) ret = ret * (!loop[i] + 1) % mod;
    else ret = 1ll * ret * size[i] % mod;
  }
  printf("%d\n", ret);
  return 0;
}