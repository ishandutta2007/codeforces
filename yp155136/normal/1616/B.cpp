#include <bits/stdc++.h>
using namespace std;

string s;

void show(int k) {
  for (int i = 0; i <= k; ++i) {
    cout << s[i];
  }
  for (int i = k; i >= 0; --i) {
    cout << s[i];
  }
  cout << '\n';
}

int main () {
  ios::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  while (T--) {
    int n; cin >> n;
    cin >> s;
    if (n == 1) {
      show(0);
      continue;
    }
    if (s[0] == s[1]) {
      show(0);
      continue;
    }
    for (int i = 1; i < n; ++i) {
      if (s[i] > s[i - 1]) {
        show(i - 1);
        break;
      }
      if (i == n - 1) {
        show(n - 1);
        break;
      }
    }
  }
}