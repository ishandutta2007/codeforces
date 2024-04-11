#include <bits/stdc++.h>
using namespace std;
int n;
int a[200001];
priority_queue<pair<int, int>> q;
vector<pair<int, int>> ans;
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  ans.clear();
  while (!q.empty())
    q.pop();
  for (int i = 1; i <= n; i++)
    q.push({a[i], i});
  while (q.size() >= 2) {
    auto A = q.top();
    q.pop();
    auto B = q.top();
    q.pop();
    if (B.first == 0)
      break;
    ans.push_back({A.second, B.second});
    q.push({A.first - 1, A.second});
    q.push({B.first - 1, B.second});
  }
  cout << ans.size() << '\n';
  for (auto &&[a, b] : ans) {
    cout << a << ' ' << b << '\n';
  }
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