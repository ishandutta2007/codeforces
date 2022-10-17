#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, ans = 0, l = 1, r = 1e9;
  cin >> n;
  while(l <= r) {
    long long mid = l + r >> 1;
    if(mid * (mid + 1) / 2 < n) l = mid + 1;
    else ans = mid, r = mid - 1;
  }
  printf("%lld", n - ans * (ans - 1) / 2);
}