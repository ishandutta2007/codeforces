#include <bits/stdc++.h>
using namespace std;
int cnt[3];
void solve() {
  string s;
  cin >> s;
  cnt[0] = cnt[1] = cnt[2] = 0;
  for (auto &&c : s)
    cnt[c - 'A']++;
  if ((cnt[1] == cnt[0] + cnt[2]))
    cout << "YES\n";
  else
    cout << "NO\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--)
    solve();
}