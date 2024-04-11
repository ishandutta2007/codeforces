#include <bits/stdc++.h>
double a, b, c, x1, y1, x2, y2;
int main() {
  std::cin >> a >> b >> c;
  std::cin >> x1 >> y1 >> x2 >> y2;
  double ans = abs(x1 - x2) + abs(y1 - y2);
  double x[2] = {-1.0 * (b * y1 + c) / a, x1}, y[2] = {y1, -1.0 * (a * x1 + c) / b};
  double nx[2] = {-1.0 * (b * y2 + c) / a, x2}, ny[2] = {y2, -1.0 * (a * x2 + c) / b};
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      auto sqr = [&](double x) {
        return x * x;
      };
      ans = std::min(ans, fabs(x1 - x[i]) + fabs(y1 - y[i]) + sqrt(sqr(fabs(x[i] - nx[j])) + sqr(fabs(y[i] - ny[j]))) + fabs(nx[j] - x2) + fabs(ny[j] - y2));
    }
  } 
  std::cout << std::setprecision(20) << ans << "\n";
  return 0;
}