#include <bits/stdc++.h>
using namespace std;

int n;

const int N = 106;
int a[N];

int check(int l, int r) {
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (i == l || i == r) continue;
    int top = (a[r] - a[l]) * (i - l);
    int down = r - l;
    if (top % down != 0) {
      ans++;
      continue;
    }
    int v = a[l] + top / down;
    if (v != a[i]) ++ans;
  }
  return ans;
}

void go() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  if (n == 1) {
    cout << 0 << endl;
    return;
  }
  int ans = n - 2;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (i == j) continue;
      ans = min(ans, check(i, j));
    }
  }
  cout << ans << endl;
}

int main () {
  ios::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  while (T--) {
    go();
  }
}