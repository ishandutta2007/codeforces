#include <bits/stdc++.h>
using namespace std;

int f[10];

int query(int d) {
  cout << "? " << (200 / d * 200) << endl;
  for (int i = d; i <= 200; i += d)
    for (int j = 1; j <= 200; ++j)
      cout << i << " " << j << " ";
  cout << endl;
  int res;
  cin >> res;
  return res;
}

int main() {
  f[0] = query(1);
  int l = 1, r = 7, p = 0;
  while (l <= r) {
    int mid = (l + r) >> 1;
    f[mid] = query(1 << mid);
    if (f[mid] * (1 << mid) == f[0]) 
      p = mid, l = mid + 1;
    else r = mid - 1;
  }
  int h = abs(2 * f[p + 1] - f[p]) - 1;
  int w = f[0] / (h + 1) - 1;
  cout << "! " << 2 * (w + h) << endl;
  return 0;
}