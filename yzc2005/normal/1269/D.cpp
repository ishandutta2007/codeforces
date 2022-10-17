#include <bits/stdc++.h>
 
int main() {
  int n;
  std::cin >> n;
  
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  
  long long sum[2] = {0, 0};
  
  for (int i = 0; i < n; ++i) {
    int x = (a[i] + (i & 1)) / 2;
    int y = a[i] - x;
    sum[0] += x;
    sum[1] += y;
  }
  
  std::cout << std::min(sum[0], sum[1]) << "\n";
}