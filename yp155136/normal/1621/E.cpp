#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
#define F first
#define S second

bool cmp(pii a, pii b) {
  // a.F / a.S > b.F / b.S
  return a.F * b.S > a.S * b.F;
}

const int N = 200006;

ll a[N];
vector<ll> b[N];
ll sum_b[N], sz_b[N];
pii val_b[N];

struct BIT {
  int a[N];
  int n;
  void init(int _n) {
    n = _n;
    for (int i = 0; i <= n; ++i) {
      a[i] = 0;
    }
  }
  void update(int pos, int val) {
    for (int i = pos; i <= n; i += i & (-i)) {
      a[i] += val;
    }
  }
  int query(int pos) {
    int ret = 0;
    for (int i = pos; i > 0; i -= i & (-i)) {
      ret += a[i];
    }
    return ret;
  }
  int queryLR(int l, int r) {
    return query(r) - query(l - 1);
  }
} bit_now, bit_pre, bit_suf;

bool ok(ll a1, pii p1) {
  return a1 * p1.S >= p1.F;
}

bool checkLR(int l, int r, int m) {
  if (bit_now.queryLR(1, l - 1) != l - 1) return false;
  if (bit_now.queryLR(r + 1, m) != m - r) return false;
  return true;
}

void go() {
  int n, m; cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  reverse(a + 1, a + n + 1);
  vector<int> idx;
  vector<pii> all_b;
  for (int i = 1; i <= m; ++i) {
    cin >> sz_b[i];
    b[i].clear(); sum_b[i] = 0;
    for (int j = 0; j < sz_b[i]; ++j) {
      ll x; cin >> x;
      b[i].push_back(x);
      sum_b[i] += x;
    }
    val_b[i] = make_pair(sum_b[i], sz_b[i]);
    idx.push_back(i);
    all_b.push_back(val_b[i]);
  }
  sort(idx.begin(), idx.end(), [](const int &i, const int &j) {
    return cmp(val_b[i], val_b[j]);
  });
  sort(all_b.begin(), all_b.end(), cmp);
  bit_now.init(n);
  bit_pre.init(n);
  bit_suf.init(n);
  for (int i = 1; i <= m; ++i) {
    pii p_now = val_b[idx[i - 1]];
    if (ok(a[i], p_now)) {
      bit_now.update(i, 1);
    }
    if (i > 1) {
      pii p_pre = val_b[idx[i - 2]];
      if (ok(a[i], p_pre)) {
        bit_pre.update(i, 1);
      }
    }
    if (i < m) {
      pii p_suf = val_b[idx[i]];
      if (ok(a[i], p_suf)) {
        bit_suf.update(i, 1);
      }
    }
  }
  for (int i = 1; i <= m; ++i) {
    for (int j = 0; j < sz_b[i]; ++j) {
      bool okok = true;
      int ori_pos = lower_bound(all_b.begin(), all_b.end(), val_b[i], cmp) - all_b.begin() + 1;
      pii p_new = make_pair(sum_b[i] - b[i][j], sz_b[i] - 1);
      int new_pos = lower_bound(all_b.begin(), all_b.end(), p_new, cmp) - all_b.begin() + 1;
      if (cmp(val_b[i], p_new)) {
        // new one is bigger
        --new_pos;
      }
      if (ori_pos == new_pos) {
        okok &= checkLR(ori_pos, new_pos, m);
        if (okok) {
          okok &= ok(a[ori_pos], p_new);
        }
      }
      else if (ori_pos > new_pos) {
        int l = min(ori_pos, new_pos);
        int r = max(ori_pos, new_pos);
        okok &= checkLR(l, r, m);
        if (okok) {
          okok &= ok(a[l], p_new);
          okok &= (bit_pre.queryLR(l + 1, r) == r - l);
        }
      }
      else if (ori_pos < new_pos) {
        int l = min(ori_pos, new_pos);
        int r = max(ori_pos, new_pos);
        okok &= checkLR(l, r, m);
        if (okok) {
          okok &= ok(a[r], p_new);
          okok &= (bit_suf.queryLR(l, r - 1) == r - l);
        }
      }
      if (okok) cout << '1';
      else cout << '0';
    }
  }
  cout << '\n';
}

int main () {
  ios::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  while (T--) {
    go();
  }
}