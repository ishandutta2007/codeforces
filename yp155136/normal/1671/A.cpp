#include <bits/stdc++.h>
using namespace std;

void go() {
  string s; cin >> s;
  if ((int)s.size() == 1) {
    cout << "NO" << '\n';
    return;
  }
  if (s[0] != s[1]) {
    cout << "NO" << '\n';
    return;
  }
  int n = (int)s.size();
  if (s[n - 2] != s[n - 1]) {
    cout << "NO" << '\n';;
    return;
  }
  for (int i = 1; i < n - 1; ++i) {
    if (s[i] != s[i - 1] && s[i] != s[i + 1]) {
      cout << "NO" << '\n';
      return;
    }
  }
  cout << "YES" << '\n';
}

int main() {
  int T; cin >> T;
  while (T--) {
    go();
  }
}