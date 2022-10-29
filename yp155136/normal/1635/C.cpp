#include <bits/stdc++.h>
using namespace std;

const int N = 200006;
int a[N];

void go() {
  int n; cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = n - 1; i >= 1; --i) {
    if (a[i] > a[i + 1]) {
      if (i == n - 1) {
        cout << -1 << '\n';
        return;
      }
      else if (a[n] < 0) {
        cout << -1 << '\n';
        return;
      }
      else {
        cout << i << '\n';
        for (int j = 1; j <= i; ++j) {
          cout << j << ' ' << i + 1 << ' ' << n << '\n';
        }
        return;
      }
    }
  }
  cout << '0' << '\n';
}

int main () {
  ios::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  while (T--) {
    go();
  }
}