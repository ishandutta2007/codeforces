#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

mt19937 rnd(98561);

void reverse(string& s, int len) {
  //cerr << "rev " << len << '\n';
  reverse(s.begin(), s.begin() + len);
  for (int i = 0; i < len; ++i) {
    if (s[i] == 1) {
      s[i] = 2;
    } else if (s[i] == 2) {
      s[i] = 1;
    }
  }
}

void dbg(const string& s) {
  for (auto c : s) {
    cerr << char(c + '0');
  }
  cerr << '\n';
}

bool try_solve(string a, const string& b, vector<int>& op) {
  int n = (int) a.size();
  vector<int> pos;
  for (int i = n - 1; i >= 0; --i) {
    if (a[i] == b[i]) {
      continue;
    }
    if ((int) op.size() >= n * 2 + 1) {
      return false;
    }
    pos.clear();
    for (int j = 0; j <= i; ++j) {
      if (a[j] == b[i]) {
        pos.push_back(j);
      }
    }
    bool sos = pos.empty();
    if (pos.empty()) {
      assert(b[i] == 1 || b[i] == 2);
      //cerr << "bitch move\n";
      for (int j = 0; j <= i; ++j) {
        if (a[j] == 1 || a[j] == 2) {
          pos.push_back(j);
        }
      }
    }
      //dbg(a);
      //dbg(b);
    int x = pos[rnd() % (int) pos.size()];
    //cerr << "x " << x << '\n';
    op.push_back(x + 1);
    reverse(a, x + 1);
    if (sos) {
      op.push_back(1);
      reverse(a, 1);
    }
    op.push_back(i + 1);
    reverse(a, i + 1);
      //dbg(a);
      //dbg(b);
    assert(a[i] == b[i]);
  }
  return (int) op.size() <= n * 2 + 1;
}

string convert(const string& s) {
  string res;
  for (int i = 0; i < (int) s.size(); i += 2) {
    int d = (s[i] - '0') * 2 + (s[i + 1] - '0');
    res += d;
  }
  return res;
}

void solve() {
  string a, b;
  cin >> a >> b;
  a = convert(a);
  b = convert(b);
  array<int, 4> cnt{{0, 0, 0, 0}};
  for (auto c : a) {
    cnt[c]++;
  }
  for (auto c : b) {
    cnt[c]--;
  }
  if (cnt[0] != 0 || cnt[3] != 0) {
    cout << -1 << '\n';
    return;
  }

  vector<int> res;
  while (true) {
    res.clear();
    if (try_solve(a, b, res)) {
      break;
    }
  }
  cout << res.size() << '\n';
  for (auto x : res) {
    cout << x * 2 << ' ';
  }
  cout << '\n';
}

signed main() {
#ifdef LOCAL
  assert(freopen("h.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);

  int tn;
  cin >> tn;
  for (int i = 0; i < tn; ++i) {
    solve();
  }
}