#include <bits/stdc++.h>
using namespace std;
int64_t a[3], b, c, m;
void solve() {
  cin >> a[0] >> a[1] >> a[2] >> m;
  int64_t t = a[0] + a[1] + a[2] - 1 - m;
  sort(a, a+3);
  if (t < 2) {
    cout << "No\n";
    return;
  }
  int64_t mx = 0;
  mx += a[1] * 2 - (a[1] == a[2]);
  a[2] -= a[1] + 1;
  if (a[2] < 0)
    a[2] = 0;
  if (a[2] > a[0])
    a[2] = a[0];
  mx += a[2] * 2;
  a[0] -= a[2];
  mx += a[0];
  if (mx >= t)
    cout << "Yes\n";
  else
    cout << "No\n";
  // n - 1 - transistion = m
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