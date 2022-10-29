#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k; cin >> n >> k;
  string s; cin >> s;
  vector<int> a(n + 1, 0);
  for (int i = n - 1; i >= 0; --i) {
    a[i] = max(s[i] - 'a', 'z' - s[i]);
    a[i] += a[i + 1];
  }
  if (a[0] < k) {puts("-1"); return 0;}
  for (int i = 0; i < n; ++i) {
    for (char c = 'a'; c <= 'z'; ++c) {
      if (k >= abs(c - s[i]) && k - abs(c - s[i]) <= a[i + 1]) {
        k -= abs(c - s[i]); putchar(c); break;
      }
    }
  }
  puts("");
  return 0;
}