#include <bits/stdc++.h>
long long a, b, c; 
int main() {
//  freopen("polynomial.in", "r", stdin);
//  freopen("polynomial.out", "w", stdout);
  while (std::cin >> a >> b >> c) {
    if (a == b && b != c) {
      std::cout << 0;      
    } else if (a > b || b > c) {
      std::cout << ((b == c) ? 1 : 0);
    } else {
      if (b == c) {
        if (a == b) {
          if (a == 1) {
            std::cout << "inf";
          } else {
            std::cout << 2;
          }
        } else {
          std::cout << 1;
        }
      } else {
        bool flag = 0;
        if (a == 1) {
          long long x = b;
          for (int i = 1; i <= 100; ++i) {
            if (x == c) {
              flag = 1;
              std::cout << 1;
              break;
            }
            x *= b;
          }
        }
        if (!flag) {
          long long x = 0, y = 1;
          while (c) {
            x += (c % b) * y;
            c /= b;
            y *= a;
          }
          std::cout << ((x == b) ? 1 : 0);
        }
      }
    }
    std::cout << '\n';
  }
  return 0;
}