#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 100006;

int a[N];
int pre_0[N], pre_1[N], pre_2[N];

ll Q_0(int l, int r) {
  return pre_0[r] - pre_0[l - 1];
}

ll Q_1(int l, int r) {
  return pre_1[r] - pre_1[l - 1];
}

ll Q_2(int l, int r) {
  return pre_2[r] - pre_2[l - 1];
}

ll pre[N], suf[N];
ll p0[N], p1[N];
ll s0[N], s1[N];

int main () {
  ios::sync_with_stdio(0); cin.tie(0);
  string s; cin >> s;
  int n = (int)s.size();
  for (int i = 1; i <= n; ++i) {
    a[i] = s[i - 1] - '0';
    if (s[i - 1] == '?') {
      a[i] = -1;
    }
  }
  ll _01, _10; cin >> _01 >> _10;
  for (int i = 1; i <= n; ++i) {
    pre_0[i] = pre_0[i - 1] + (a[i] == 0);
    pre_1[i] = pre_1[i - 1] + (a[i] == 1);
    pre_2[i] = pre_2[i - 1] + (a[i] == -1);
  }
  ll ans = (1ll << 60);
  for (int i = 1; i <= n; ++i) {
    pre[i] = pre[i - 1];
    if (a[i] == 0) {
      // pre[i] += _01 * Q_1(i + 1, n) + _10 * Q_1(1, i - 1);
      pre[i] += _10 * Q_1(1, i - 1);
    }
    else if (a[i] == 1) {
      // pre[i] += _10 * Q_0(i + 1, n) + _01 * Q_0(1, i - 1);
      pre[i] += _01 * Q_0(1, i - 1);
    }
  }
  for (int i = n; i >= 1; --i) {
    suf[i] = suf[i + 1];
    if (a[i] == 0) {
      // suf[i] += _01 * Q_1(i + 1, n) + _10 * Q_1(1, i - 1);
      suf[i] += _01 * Q_1(i + 1, n);
    }
    else if (a[i] == 1) {
      // suf[i] += _10 * Q_0(i + 1, n) + _01 * Q_0(1, i - 1);
      suf[i] += _10 * Q_0(i + 1, n);
    }
  }
  for (int i = 1; i <= n; ++i) {
    p0[i] = p0[i - 1];
    p1[i] = p1[i - 1];
    if (a[i] == -1) {
      p0[i] += _01 * Q_1(i + 1, n) + _10 * Q_1(1, i - 1);
      p1[i] += _10 * Q_0(i + 1, n) + _01 * Q_0(1, i - 1);
    }
  }
  for (int i = n; i >= 1; --i) {
    s0[i] = s0[i + 1];
    s1[i] = s1[i + 1];
    if (a[i] == -1) {
      s0[i] += _01 * Q_1(i + 1, n) + _10 * Q_1(1, i - 1);
      s1[i] += _10 * Q_0(i + 1, n) + _01 * Q_0(1, i - 1);
    }
  }
  for (int i = 0; i <= n; ++i) {
    // [1, i] are 0
    // [i + 1, n] are 1
    ll tmp = pre[i] + suf[i + 1] + p0[i] + s1[i + 1];
    tmp += Q_2(1, i) * Q_2(i + 1, n) * _01;
    tmp += Q_0(1, i) * Q_1(i + 1, n) * _01;
    tmp += Q_1(1, i) * Q_0(i + 1, n) * _10;
    // cerr << "pre = " << pre[i] << " , suf = " << suf[i + 1] << " , p0 = " << p0[i] << " , s1 = " << s1[i + 1] << endl;
    // cerr << "i = " << i << " , tmp = " << tmp << endl;
    ans = min(ans, tmp);
  }
  for (int i = 0; i <= n; ++i) {
    // [1, i] are 1
    // [i + 1, n] are 0
    ll tmp = pre[i] + suf[i + 1] + p1[i] + s0[i + 1];
    tmp += Q_2(1, i) * Q_2(i + 1, n) * _10;
    tmp += Q_0(1, i) * Q_1(i + 1, n) * _01;
    tmp += Q_1(1, i) * Q_0(i + 1, n) * _10;
    // cerr << "i = " << i << " , tmp = " << tmp << endl;
    ans = min(ans, tmp);
  }
  cout << ans << endl;
}