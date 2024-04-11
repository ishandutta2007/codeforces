#include <bits/stdc++.h>
using namespace std;

const int N = 200006;
int a[N];
int ans[N];

void go() {
  int n, k; cin >> n >> k;
  string s; cin >> s;
  for (int i = 0; i < n; ++i) {
    a[i + 1] = s[i] - '0';
    if (k & 1) {
      a[i + 1] = 1 - a[i + 1];
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (k && a[i] == 0) {
      --k;
      a[i] = 1;
      ans[i] = 1;
    }
    else {
      ans[i] = 0;
    }
  }
  if (k & 1) {
    ans[n] += k;
    a[n] = 1 - a[n];
  }
  else {
    ans[n] += k;
  }
  for (int i = 1; i <= n; ++i) {
    cout << a[i];
  }
  cout << '\n';
  for (int i = 1; i <= n; ++i) {
    cout << ans[i] << " \n"[i == n];
  }
}

int main () {
  ios::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  while (T--) {
    go();
  }
}