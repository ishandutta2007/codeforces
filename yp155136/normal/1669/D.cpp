#include <bits/stdc++.h>
using namespace std;

void go() {
  int n; cin >> n;
  string s; cin >> s;
  s = "W" + s + "W";
  bool ok = false;
  for (int i = 0; i < (int)s.size(); ++i) {
    if (s[i] != 'W') {
      if (s[i - 1] != 'W' && s[i - 1] != s[i]) {
        ok = true;
      }
    }
    else if (s[i] == 'W') {
      if (i > 0 && s[i - 1] != 'W' && !ok) {
        cout << "NO" << endl;
        return;
      }
      ok = false;
    }
  }
  cout << "YES" << endl;
  return;
}

int main () {
  ios::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  while (T--) {
    go();
  }
}