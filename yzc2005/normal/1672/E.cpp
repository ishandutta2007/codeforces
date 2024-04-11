#include <bits/stdc++.h>
using namespace std;
int query(int l) {
  cout << "? " << l << endl;
  int x;
  cin >> x;
  return x;
}
int main() {
  int n;
  cin >> n;
  int l = n, r = n * 2000, s = -1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (query(mid + n - 1) == 1) {
      s = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  int ans = s + n - 1;
  for (int k = 2; k <= n; ++k) {
    int l = (s + n - 1) / k;
    if (query(l) == k) {
      ans = min(ans, l * k);
    }
  }
  cout << "! " << ans << endl;
  return 0;
}