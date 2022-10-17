#include <bits/stdc++.h>
int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;
    int sum = 0, max = 0;
    while (n--) {
      int x;
      std::cin >> x;
      sum += x;
      if (max < x) {
        max = x;
      }
    }
    if (max * 2 > sum) {
      puts("T");
    } else {
      puts((sum & 1) ? "T" : "HL");
    }
  }
}