#include <bits/stdc++.h>
using namespace std;

int main () {
  map<int, string> mp;
  for (int i = -5000; i <= 1399; ++i) {
    mp[i] = "Division 4";
  }
  for (int i = 1400; i <= 1599; ++i) {
    mp[i] = "Division 3";
  }
  for (int i = 1600; i <= 1899; ++i) {
    mp[i] = "Division 2";
  }
  for (int i = 1900; i <= 5000; ++i) {
    mp[i] = "Division 1";
  }
  int T; cin >> T;
  while (T--) {
    int x; cin >> x;
    cout << mp[x] << '\n';
  }
}