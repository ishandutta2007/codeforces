# include <bits/stdc++.h>
using namespace std;
int main() {
  long long b;
  scanf("%lld", &b);
  int ans = 0;
  for (int i = 1; i * 1ll * i <= b; ++i) {
    if (b % i == 0) {
      ans++;
      if (b / i != i)
        ans++;
    }
  }
  printf("%d\n", ans);
}