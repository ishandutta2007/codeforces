#include <bits/stdc++.h>
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> adj(n);
  for (int i = 0; i < n; ++i) {
    std::string str;
    std::cin >> str;
    for (int j = 0; j < n; ++j) {
      if (str[j] == '1') {
        adj[i].push_back(j);
      } 
    }
  }
  std::vector<int> pop(1 << n);
  for (int s = 0; s < 1 << n; ++s) {
    pop[s] = pop[s >> 1] + (s & 1);
  }
  std::vector<std::vector<long long>> g(1 << n, std::vector<long long>(n));
  std::vector<std::vector<long long>> h(n + 1, std::vector<long long>(1 << n));
  for (int i = 0; i < n; ++i) {
    g[1 << i][i] = 1;
  }
  for (int s = 0; s < 1 << n; ++s) {
    for (int u = 0; u < n; ++u) {
      if (s >> u & 1) {
        h[pop[s]][s] += g[s][u];
        for (auto v : adj[u]) {
          if (!(s >> v & 1)) {
            g[s | (1 << v)][v] += g[s][u];
          }
        }
      }
    }
  }
  for (int t = 1; t <= n; ++t) {
    for (int i = 0; i < n; ++i) {
      for (int s = 0; s < 1 << n; ++s) {
        if (s >> i & 1) {
          h[t][s] += h[t][s ^ (1 << i)];
        }
      }
    }
  } 
  std::vector<long long> f(1 << n), par(1 << n, 1);
  std::vector<int> lengths;
  std::function<void(int)> dfs = [&](int cur) {
    if (cur == n) {
      long long sum = 0;
      for (int s = 0; s < 1 << n; ++s) {
        if ((n ^ pop[s]) & 1) {
          sum -= par[s];
        } else {
          sum += par[s];
        }
      }
      do {
        int t = 0, p = 0;
        for (auto l : lengths) {
          for (int i = 1; i < l; ++i) {
            t |= 1 << (p++);
          }
          ++p;
        }
        f[t] += sum;
      } while (std::next_permutation(lengths.begin(), lengths.end()));
    }
    std::vector<long long> last = par;
    for (int i = lengths.empty() ? 1 : lengths.back(); cur + i <= n; ++i) {
      lengths.push_back(i);
      for (int s = 0; s < 1 << n; ++s) {
        par[s] *= h[i][s];
      }
      dfs(cur + i);
      lengths.pop_back();
      par = last;
    }
  }; dfs(0);
  for (int i = 0; i < n; ++i) {
    for (int s = 0; s < 1 << n; ++s) {
      if (s >> i & 1) {
        f[s ^ (1 << i)] -= f[s];
      }
    }
  }
  for (int s = 0; s < 1 << n - 1; ++s) {
    std::cout << f[s] << " \n"[s == (1 << n) - 1];
  }
  return 0;
}