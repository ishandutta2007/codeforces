#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 200006;
int a[N];
int cnt[3][2 * N];
int pre[N];
int n;

struct BIT {
  int a[2 * N];
  int n;
  void init(int _n) {
    n = _n;
    memset(a, 0, sizeof(a));
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
} bit1, bit2;

struct Event {
  int l, r;
  int type;
  Event(int _l, int _r, int _t): l(_l), r(_r), type(_t){}
};

bool operator<(const Event &e1, const Event &e2) {
  return e1.r < e2.r;
}

ll conquer(int l, int r, int mid) {
  if (a[mid] == -1 && a[mid + 1] == -1) {
    assert(0);
    return 0;
  }
  int _cnt = 0;
  pre[mid + 1] = 0;
  vector<Event> v[3];
  for (int i = mid; i >= l; --i) {
    if (i <= mid - 1 && a[i] == -1 && a[i + 1] == -1) {
      pre[i] = pre[i + 2] + 1;
    }
    else {
      if (i == mid) {
        pre[i] = 0;
      }
      else {
        pre[i] = pre[i + 1];
      }
    }
    _cnt += a[i];
    int L = _cnt, R = _cnt + pre[i] * 3;
    int bucket = (L % 3 + 3) % 3;
    v[bucket].push_back(Event(L, R, 1));
    // cerr << "i = " << i << " , l = " << L << " , r = " << R << endl;
  }
  _cnt = 0;
  pre[mid] = 0;
  for (int i = mid + 1; i <= r; ++i) {
    if (i >= mid + 2 && a[i] == -1 && a[i - 1] == -1) {
      pre[i] = pre[i - 2] + 1;
    }
    else {
      if (i == mid + 1) {
        pre[i] = 0;
      }
      else {
        pre[i] = pre[i - 1];
      }
    }
    _cnt += a[i];
    int L = _cnt, R = _cnt + pre[i] * 3;
    // cerr << "a[i] = " << a[i] << endl;
    // cerr << "_cnt = " << _cnt << endl;
    int bucket = ((-L) % 3 + 3) % 3;
    v[bucket].push_back(Event(-R, -L, 2));
    // cerr << "i = " << i << " , l = " << L << " , r = " << R << endl;
  }
  ll ret = 0;
  for (int i = 0; i < 3; ++i) {
    sort(v[i].begin(), v[i].end());
    for (Event e : v[i]) {
      if (e.type == 1) {
        bit2.update(e.l + N, 1);
      }
    }
    for (Event e : v[i]) {
      if (e.type == 2) {
        ret += bit1.queryLR(e.l + N, e.r + N);
        ret += bit2.queryLR(1, e.r + N);
      }
      else {
        bit2.update(e.l + N, -1);
        bit1.update(e.r + N, 1);
      }
    }
    for (Event e : v[i]) {
      if (e.type == 1) {
        bit1.update(e.r + N, -1);
      }
    }
  }
  // cerr << "l = " << l << " , r = " << r << " , ret = " << ret << endl;
  return ret;
}

bool ok(int mid, int l, int r) {
  if (l <= mid && mid + 1 <= r) {
    if (a[mid] == -1 && a[mid + 1] == -1) {
      return false;
    }
    return true;
  }
  return false;
}

ll dc(int l, int r) {
  if (l == r) {
    return 0;
  }
  // check if all are -1
  int cnt = 0;
  for (int i = l; i <= r; ++i) {
    cnt += (a[i] == -1);
  }
  if (cnt == r - l + 1) {
    ll ret = 0;
    for (int i = 3; i <= cnt; i += 3) {
      ret += (r - l + 1 - i + 1);
    }
    return ret;
  }
  int mid = -1;
  int _mid = (l + r) >> 1;
  for (int del = 0; ; ++del) {
    if (ok(_mid + del, l, r)) {
      mid = _mid + del;
      break;
    }
    if (ok(_mid - del, l, r)) {
      mid = _mid - del;
      break;
    }
  }
  assert(mid != -1);
  ll ret = 0;
  ret += dc(l, mid) + dc(mid + 1, r);
  ret += conquer(l, r, mid);
  return ret;
}

void go() {
  cin >> n;
  string s; cin >> s;
  for (int i = 1; i <= n; ++i) {
    a[i] = (s[i - 1] == '+' ? 1 : -1);
  }
  cout << dc(1, n) << '\n';
}

int main () {
  ios::sync_with_stdio(0); cin.tie(0);
  bit1.init(2 * N - 1);
  bit2.init(2 * N - 1);
  int T; cin >> T;
  while (T--) {
    go();
  }
}