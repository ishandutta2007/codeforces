#include <bits/stdc++.h>
using namespace std;
int main() {
  int n; cin >> n;
  cout << "? " << 1 << " " << n << endl;
  int p; cin >> p;
  int l = 1, r = n;
  while (l < r) {
    if (l + 1 == r) {
      if (p == l) cout << "! " << r << endl, exit(0);
      else if (p == r) cout << "! " << l << endl, exit(0);
    }
    int mid = l + r >> 1;
    if (p <= mid) {
      cout << "?" << " " << min(l, p) << " " << mid << endl;
      int pp; cin >> pp;
      if (pp != p) l = mid + 1;
      else r = mid;
    } else {
      if (mid == l) ++mid;
      cout << "?" << " " << mid << " " << max(r, p) << endl;
      int pp; cin >> pp;
      if (pp != p) r = mid - 1;
      else l = mid;
    }
  }
  cout << "! " << l << endl;
  return 0;
}