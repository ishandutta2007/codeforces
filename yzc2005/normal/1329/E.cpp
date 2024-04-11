#include <bits/stdc++.h>
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int cases;
  std::cin >> cases;
  while (cases--) {
    int m;
    long long n, k;
    std::cin >> n >> m >> k;
    std::vector<long long> c(m + 1);
    for (int i = 0; i < m; ++i) {
      std::cin >> c[i];
    }
    c[m] = n;
    for (int i = m; i; --i) {
      c[i] -= c[i - 1];
    }
    k += m + 1;
    long long L, R;
    [&]() {
      long long l = 1, r = *std::min_element(c.begin(), c.end());
      while (l <= r) {
        long long mid = l + r >> 1;
        long long cnt = 0;
        for (auto x : c) {
          cnt += x / mid;
        }
        if (cnt >= k) {
          L = mid;
          l = mid + 1;
        } else {
          r = mid - 1;
        }
      }
    }();
    [&]() {
      long long l = 1, r = *std::max_element(c.begin(), c.end());
      while (l <= r) {
        long long mid = l + r >> 1;
        long long cnt = 0;
        for (auto x : c) {
          cnt += (x + mid - 1) / mid;
        }
        if (cnt <= k) {
          R = mid;
          r = mid - 1;
        } else {
          l = mid + 1;
        }
      }
    }();
    std::vector<std::pair<long long, long long>> limits;
    for (auto x : c) {
      long long lower = (x + R - 1) / R, upper = x / L;
      if (lower > upper) {
        limits.push_back(std::make_pair(x / (upper + 1), (x - 1) / (lower - 1) + 1));
      }
    } 
    std::sort(limits.begin(), limits.end());
    long long max = R, ans = n;
    for (auto limit : limits) {
      ans = std::min(ans, max - limit.first);
      max = std::max(max, limit.second);
    }
    ans = std::min(ans, max - L);
    std::cout << ans << "\n";
  }
  return 0;
}