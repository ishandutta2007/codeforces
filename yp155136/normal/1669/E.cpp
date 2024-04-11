#include <bits/stdc++.h>
using namespace std;

void go() {
  int n; cin >> n;
  map<string, int> mp;
  for (int i = 0; i < n; ++i) {
    string s; cin >> s;
    mp[s] += 1;
  }
  long long ans = 0;
  for (auto p : mp) {
    string s = p.first;
    for (int i = 'a'; i <= 'k'; ++i) {
      for (int j = 0; j < 2; ++j) {
        string t = s;
        t[j] = i;
        if (t == s) continue;
        auto iter = mp.find(t);
        if (iter != mp.end()) ans += mp[t] * 1ll * p.second;
      }
    }
  }
  cout << ans / 2 << endl;
}

int main () {
  ios::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  while (T--) {
    go();
  }
}