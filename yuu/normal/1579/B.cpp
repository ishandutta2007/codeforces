#include <bits/stdc++.h>
using namespace std;
int n;
int a[51];
class oper {
public:
  int l, r, d;
  oper(int l, int r, int d) : l(l), r(r), d(d){};
};
vector<oper> ans;
void perform_shift(int l, int r) {
  ans.emplace_back(l, r, r - l);
  for (int i = r - 1; i >= l; i--)
    swap(a[i], a[i + 1]);
}
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  ans.clear();
  for (int i = 1; i <= n; i++) {
    int best = i;
    for (int j = i + 1; j <= n; j++)
      if (a[j] < a[best])
        best = j;
    if (best == i)
      continue;
    perform_shift(i, best);
  }
  cout << ans.size() << '\n';
  for (auto &&[l, r, d] : ans) {
    cout << l << ' ' << r << ' ' << d << '\n';
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