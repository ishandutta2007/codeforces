#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

int main() {
  int n;
  cin >> n;
  int t = 1;
  while ((t + 1) * (t + 1) <= n) ++t;
  if (t * t == n) {
    cout << 4 * t << endl;
  } else if (t * (t + 1) >= n) {
    cout << 4 * t + 2 << endl;
  } else {
    cout << 4 * t + 4 << endl;
  }
  return 0;
}