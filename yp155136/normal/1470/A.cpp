#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 300006;

ll k[N];
ll c[N];
ll cnt[N];
ll pre[N];

void go() {
  int n, m; cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> k[i];
  }
  for (int i = 1; i <= m; ++i) {
    cin >> c[i];
    // cnt[i] = 0;
    pre[i] = pre[i - 1] + c[i];
  }
  ll tot = 0;
  for (int i = 1; i <= n; ++i) {
    tot += c[k[i]];
  }
  // binary search the all-ok
  sort(k + 1, k + n + 1);
  reverse(k + 1, k + n + 1);
  int mx_cnt = n;
  for (int i = 1; i <= n; ++i) {
    int tmp = i + k[i] - 1;
    if (tmp < mx_cnt) {
      mx_cnt = tmp;
    }
    if (i == mx_cnt) {
      break;
    }
  }
  ll ans = (1ll << 60);
  for (int i = 1; i <= mx_cnt; ++i) {
    tot -= c[k[i]];
    ans = min(ans, tot + pre[i]);
  }
  cout << ans << '\n';
  /*
  for (int i = 1; i <= n; ++i) {
    cnt[k[i]]++;
  }
  ll ans = 0;
  ll _ = 0;
  deque<ll> dq;
  for (int i = 1; i <= m; ++i) {
    if (cnt[i] == 0) {
      // _2 += c[i];
      dq.push_back(c[i]);
    }
    else {
      while (!dq.empty() && cnt[i] > 0) {
        --cnt[i];
        ans += dq.front();
        dq.pop_front();
      }
      if (cnt[i] == 0) {
        dq.push_back(c[i]);
      }
      else if (cnt[i] == 1) {
        ans += c[i];
      }
      else {
        ans += cnt[i] * c[i];
      }
    }
  }
  */
}

int main () {
  ios::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  while (T--) {
    go();
  }
}