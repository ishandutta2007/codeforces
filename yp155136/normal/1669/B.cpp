#include <bits/stdc++.h>
using namespace std;

const int N = 200006;
int cnt[N];
int a[N];

void go() {
  int n; cin >> n;
  for (int i = 0; i <= n; ++i) cnt[i] = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; ++i) {
    cnt[a[i]]++;
    if (cnt[a[i]] >= 3) {
      cout << a[i] << '\n';
      return;
    }
  }
  cout << -1 << '\n';
}

int main () {
  ios::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  while (T--) {
    go();
  }
}