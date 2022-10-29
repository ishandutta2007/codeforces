#include <bits/stdc++.h>
using namespace std;

const int N = 200006;
const int K = 31;

int cnt[K];

void go() {
  int n, k; cin >> n >> k;
  memset(cnt, 0, sizeof(cnt));
  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    for (int j = 0; j < K; ++j) {
      if (((1 << j) & x) != 0) {
        cnt[j]++;
      }
    }
  }
  for (int i = K - 1; i >= 0; --i) {
    int need = n - cnt[i];
    if (k >= need) {
      k -= need;
      cnt[i] += need;
    }
  }
  int ans = 0;
  for (int i = K - 1; i >= 0; --i) {
    if (cnt[i] == n) ans |= (1 << i);
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