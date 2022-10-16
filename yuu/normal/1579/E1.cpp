#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  deque<int> d;
  for (int i = 1, p; i <= n; i++) {
    cin >> p;
    if ((i == 1) || (p > d.front()))
      d.push_back(p);
    else
      d.push_front(p);
  }
  for (auto &&x : d)
    cout << x << ' ';
  cout << '\n';
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