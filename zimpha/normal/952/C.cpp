#include <cstdio>
#include <vector>
#include <algorithm>

int main() {
  int n;
  scanf("%d", &n);
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < n; ++i) {
    int mx = 0;
    for (int j = 1; j < (int)a.size(); ++j) {
      mx = std::max(mx, std::abs(a[j] - a[j - 1]));
    }
    if (mx >= 2) {
      puts("NO");
      return 0;
    }
    int x = -1;
    for (int j = 0; j < (int)a.size(); ++j) {
      if (x == -1 || a[j] > a[x]) x = j;
    }
    std::vector<int> b;
    for (int j = 0; j < (int)a.size(); ++j) {
      if  (j != x) b.push_back(a[j]);
    }
  }
  puts("YES");
  return 0;
}