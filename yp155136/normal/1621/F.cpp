#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
#define F first
#define S second

ll a, b, c;

ll case1(vector<pii> v) {
  ll n = (int)v.size();
  ll basic_1 = 0;
  ll basic_0 = 0;
  ll basic_00 = 0;
  vector<ll> merge_need;
  for (int i = 0; i < n; ++i) {
    if (v[i].F == 1) {
      basic_1 += v[i].S - 1;
    }
    else {
      if (i - 1 >= 0 && i + 1 < n) {
        merge_need.push_back(v[i].S - 1);
      }
      else {
        basic_0 += v[i].S - 1;
        basic_00++;
      }
    }
  }
  sort(merge_need.begin(), merge_need.end());
  int m = (int)merge_need.size();
  ll ans = 0;
  ll tmp_basic_1 = basic_1;
  for (int i = 0; i < m; ++i) {
    ll _ = min(tmp_basic_1, merge_need[i]);
    tmp_basic_1 -= _;
    merge_need[i] -= _;
    ans += _ * (a + b);
  }
  if (tmp_basic_1 == 0) {
    // need merge
    for (int i = 0; i < m; ++i) {
      if (merge_need[i] == 0) {
        ans += (b - c);
      }
    }
    // see if there's an extra 0
    if (basic_0 > 0) {
      ans += a;
      return ans;
    }
    for (int i = 0; i < m; ++i) {
      if (merge_need[i] > 0) {
        ans += a;
        return ans;
      }
    }
    return ans;
  }
  else {
    // merge all
    for (int i = 0; i < m; ++i) {
      if (merge_need[i] == 0) {
        ans += (b - c);
      }
    }
    ll _ = min(tmp_basic_1, basic_0);
    ans += _ * (a + b);
    tmp_basic_1 -= _;
    basic_0 -= _;
    // cerr << "here _ = " << _ << " , ans = " << ans << " , tmp_basic_1 = " << tmp_basic_1 << endl;
    if (tmp_basic_1 == 0) {
      if (basic_0 > 0) {
        return ans + a;
      }
      else {
        return ans;
      }
    }
    else {
      ll __ = min(tmp_basic_1, basic_00);
      ans += __ * (b - c);
      tmp_basic_1 -= __;
      if (tmp_basic_1 > 0) {
        return ans + b;
      }
      else {
        return ans + c;
      }
    }
  }
}

void go() {
  int n;
  cin >> n >> a >> b >> c;
  string s; cin >> s;
  vector<pii> v;
  s += " ";
  char last = 'c';
  int cnt = 0;
  for (char cc : s) {
    if (cc != last) {
      if (last == '0') {
        v.push_back(make_pair(0, cnt));
      }
      else if (last == '1') {
        v.push_back(make_pair(1, cnt));
      }
      cnt = 0;
    }
    last = cc;
    ++cnt;
  }
  if (c >= b) {
    // trivial case
    ll all[2] = {0, 0};
    for (pii p : v) {
      all[p.F] += p.S - 1;
    }
    ll mn = min(all[0], all[1]);
    cout << min(mn + 1, all[0]) * a + min(mn + 1, all[1]) * b << '\n';
    return;
  }
  cout << case1(v) << '\n';
}

int main () {
  ios::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  while (T--) {
    go();
  }
}