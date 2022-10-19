#include <bits/stdc++.h>
int main() {
  int t, d;
  std::cin >> t;
  while (t--) {
    std::cin >> d;
    int delta = d * d - 4 * d;
    if (delta < 0) std::cout << 'N';
    else {
      double x1 = (double) (d + sqrt(delta)) / 2;
      double x2 = (double) (d - sqrt(delta)) / 2;
      if (x1 < 0 || x2 < 0) std::cout << 'N';
      else std::cout << std::setprecision(10) << 'Y' << ' ' << x1 << ' ' << x2;
    }
    std::cout << std::endl;
  }
  return 0;
}