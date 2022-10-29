#include <bits/stdc++.h>
using namespace std;

void go() {
  int n, m; cin >> n >> m;
  string s[n];
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }
  for (int j = 0; j < m; ++j) {
    for (int x = 0; x < n; ++x) {
      for (int i = n - 1; i >= 1; --i) {
        if (s[i][j] == '.' && s[i - 1][j] == '*') {
          swap(s[i][j], s[i - 1][j]);
        }
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    cout << s[i] << endl;
  }
}

int main () {
  ios::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  while (T--) {
    go();
  }
}