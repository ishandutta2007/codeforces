#include <bits/stdc++.h>

const int N = 5005;

int n, x[N], y[N], p[N];

bool judge(int a, int b, int c) { // angle (ABC)
  int x1 = x[a] - x[b], y1 = y[a] - y[b];
  int x2 = x[c] - x[b], y2 = y[c] - y[b];
  return 1ll * x1 * x2 + 1ll * y1 * y2 > 0;
}

int main() { 
  std::cin >> n;
  for (int i = 1; i <= n; ++i) {
    std::cin >> x[i] >> y[i];
  }
  
  for (int i = 1; i <= n; ++i) {
    p[i] = i;
    for (int j = i - 1; j > 1 && !judge(p[j - 1], p[j], p[j + 1]); --j) {
      std::swap(p[j], p[j + 1]);
    }
  }
  
  for (int i = 1; i <= n; ++i) {
    std::cout << p[i] << " \n"[i == n];
  }
  
  return 0;
}