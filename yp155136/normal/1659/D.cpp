#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 200006;
int a[N];

struct BIT {
  ll a[N];
  int n;
  void init(int _n) {
    n = _n;
    for (int i = 0; i <= n; ++i) {
      a[i] = 0;
    }
  }
  void update(int pos, ll val) {
    for (int i = pos; i <= n; i += i & (-i)) {
      a[i] += val;
    }
  }
  ll query(int pos) {
    ll ret = 0;
    for (int i = pos; i > 0; i -= i & (-i)) {
      ret += a[i];
    }
    return ret;
  }
  ll queryLR(int l, int r) {
    return query(r) - query(l - 1);
  }
} bit;

void modify(int l, int r, int val) {
  bit.update(l, val);
  bit.update(r + 1, -val);
}

void init(int n) {
  bit.init(n + 1);
  for (int i = 1; i <= n; ++i) {
    modify(i, i, a[i]);
  }
}

ll query(int pos) {
  return bit.query(pos);
}

int ans[N];

void go() {
  int n; cin >> n;
  ll n1 = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    n1 += a[i];
  }
  n1 /= n;
  init(n);
  for (int i = n; i >= 1; --i) {
    int _ = query(i);
    // cerr << "i = " << i << " , _ = " << _ << endl;
    if (_ == 0) {
      ans[i] = 0;
    }
    else if (_ == i) {
      ans[i] = 1;
      modify(i - n1 + 1, i, -1);
      --n1;
    }
    else if (_ == 1) {
      ans[i] = 0;
      modify(i - n1 + 1, i, -1);
    }
    else assert(0);
  }
  for (int i = 1; i <= n; ++i) {
    cout << ans[i] << " \n"[i == n];
  }
}

int main () {
  ios::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  while (T--) {
    go();
  }
}