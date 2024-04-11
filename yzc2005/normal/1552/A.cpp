#include <bits/stdc++.h>
using namespace std;

const int N = 45;
int n;

void solve() {
  string s; 
  cin >> n >> s;
  string t = s;
  sort(t.begin(), t.end());
  int ans = 0;
  for (int i = 0; i < n; ++i)
    if (s[i] != t[i]) ++ans;
  cout << ans << endl;
}

int main() {
  int t; scanf("%d", &t);
  while (t--) solve();
  return 0;
}