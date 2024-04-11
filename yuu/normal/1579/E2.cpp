#include <bits/stdc++.h>
using namespace std;
int n;
map<int, int> M;
int a[200001];
int ft[200001];
int update(int u) {
  for (; u <= M.size(); u += u & -u)
    ft[u]++;
}
int get(int u) {
  int res = 0;
  for (; u > 0; u -= u & -u)
    res += ft[u];
  return res;
}
void solve() {
  cin >> n;
  M.clear();
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    M[a[i]] = 1;
  }
  {
    int cnt = 0;
    for (auto &&s : M)
      s.second = ++cnt;
  }
  for (int i = 1; i <= M.size(); i++)
    ft[i] = 0;
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    int low = get(M[a[i]] - 1);
    int high = i - 1 - get(M[a[i]]);
    ans += min(low, high);
    update(M[a[i]]);
  }
  cout << ans << '\n';
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