# include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, a, b;
  scanf("%d%d%d%d", &n, &m, &a, &b);
  b = min(b, m * a);
  printf("%d\n", min(b * (n / m + 1), b * (n / m) + a * (n % m)));
}