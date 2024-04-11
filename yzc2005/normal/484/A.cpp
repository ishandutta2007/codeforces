#include <bits/stdc++.h>
int main() {
  int t;
  std::cin >> t;
  while (t--) {
    long long l, r;
    std::cin >> l >> r;
    long long ans = 0;
    for (int i = 62; ~i; --i) {
      int x = l >> i & 1, y = r >> i & 1;
      if (x == y) {
        if (x) ans |= 1ll << i;
      } else {
        long long cur = (1ll << (i + 1)) - 1;
        if ((r & cur) == cur) ans |= cur;
        else ans |= (1ll << i) - 1; 
        break;
      }
    }
    std::cout << ans << std::endl;
  }
  return 0;   
}