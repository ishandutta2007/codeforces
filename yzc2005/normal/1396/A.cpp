#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, a[N], b[N], c[N];
void exgcd(int a, int &x, int b, int &y) {
  if (b == 0) {x = 1, y = 0; return;}
  exgcd(b, x, a % b, y);
  int z = x; x = y, y = z - (a / b) * y; 
}
int main() {
  cin >> n; for (int i = 1; i <= n; ++i) cin >> a[i];
  printf("1 %d\n", n);
  for (int i = 1; i < n; ++i) exgcd(n, b[i], n - 1, c[i]), cout << -1ll * n * b[i] * a[i] << ' ';
  printf("0\n1 %d\n", max(1, n - 1));
  for (int i = 1; i <= max(1, n - 1); ++i) cout << -1ll * (n - 1) * c[i] * a[i] << ' ';
  printf("\n%d %d\n", n, n);
  printf("%d\n", -a[n]);
}