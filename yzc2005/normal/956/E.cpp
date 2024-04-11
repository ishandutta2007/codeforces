#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
int n, m, l, r, f[N];
pair<int, int> a[N];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> l >> r;
  int sum = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].second;
    sum += a[i].second;
    a[i].second *= -1;
  } 
  swap(l, r);
  l = sum - l;
  r = sum - r;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].first;
  }
  sort(a + 1, a + n + 1);
  memset(f, 0xcf, sizeof(f));
  f[0] = 0;
  for (int i = 1; i <= n; ++i) {
    a[i].second *= -1;
    for (int j = r; j >= a[i].second; --j) {
      f[j] = max(f[j], f[j - a[i].second] + (a[i].first && j >= l));
    }
  }
  cout << *max_element(f, f + sum + 1) << "\n";
  return 0;
}