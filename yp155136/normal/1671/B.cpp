#include <bits/stdc++.h>
using namespace std;

const int N = 200006;
int a[N];

void go() {
  int n; cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  if (a[n] - a[1] > n + 1) {
    cout << "NO" << '\n';
  }
  else {
    cout << "YES" << '\n';
  }
}

int main () {
  ios::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  while (T--) {
    go();
  }
}